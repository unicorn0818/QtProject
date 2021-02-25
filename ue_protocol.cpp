
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HAVE_REMOTE
#include <pcap.h>

#define UE_PROTOCOL_DLL_FILE

#include "ue_protocol.h"

char errbuf[PCAP_ERRBUF_SIZE];


/*! size of the memory block to allocate to the stack.  */
#define ETHER_STACK_SIZE          (1024*1024*2)

int g_TxBuffStartPos = 0;

static pcap_if_t *g_alldevs = NULL;
static pcap_t *g_fp = NULL;


ETH_CFG_INFO user_net_config_info[2] =
{
    {
        0,
        60,
        40,
        1600,
        1548,
        0,
        0,
        0,
        0,
        {0x00, 0x0a, 0x1a, 0x00, 0x05, 0x18},
        {0x00, 0x0a, 0x1a, 0x00, 0x05, 0x20},
        0,
    },
    {0}
};

unsigned int user_net_num_ifces = sizeof ( user_net_config_info ) / sizeof ( ETH_CFG_INFO );


//////////////////////////////////////////////////////

u16 flip16 ( u16 srv_value )
{
    int i, size_len, half_size;
    u8 *buf, swap;

    buf = NULL;
    size_len = sizeof ( srv_value );
    half_size = size_len / 2;

    if ( size_len == 0 )
    {
        return 0;
    }

    buf = ( u8 * ) &srv_value;

    if ( buf == NULL )
    {
        return 0;
    }

    for ( i = 0; i < half_size; i++ )
    {
        swap = * ( buf + i );
        * ( buf + i ) = * ( buf + ( size_len - i - 1 ) );
        * ( buf + ( size_len - i - 1 ) ) = swap;
    }

    return * ( u16 * ) ( buf );
}

u32 flip32 ( u32 srv_value )
{
    int i, size_len, half_size;
    u8 *buf, swap;   // swap交换数据的临时变量

    buf = NULL;
    size_len = sizeof ( srv_value );
    half_size = size_len / 2;

    if ( size_len == 0 )
    {
        return 0;
    }

    buf = ( u8 * ) &srv_value;

    if ( buf == NULL )
    {
        return 0;
    }

    for ( i = 0; i < half_size; i++ )
    {
        swap = * ( buf + i );
        * ( buf + i ) = * ( buf + ( size_len - i - 1 ) );
        * ( buf + ( size_len - i - 1 ) ) = swap;
    }

    return * ( u32 * ) ( buf );
}

///////////////////////////////////////////////////////////



static int PackData ( char *pUartData , unsigned int  UartDataLen, unsigned char hwaddr[6], unsigned char DstAddr[6], EMAC_FRAME_Q *pInMem, EMAC_FRAME_Q *pOutMem )
{

    int ret = 0;
    int i ;

    unsigned int uLen;
    int Count;
    int Remainder ;

    ADI_ETHER_FRAME_BUFFER *pPkt;
    UART_TO_ETHERNET_FRM *pUartFrm ;

    ADI_ETHER_BUFFER *pBuff ;
    ADI_ETHER_BUFFER *pBuffFirst;


    if ( !pUartData || !pInMem || !pOutMem )
        return 0;

    Count = UartDataLen / ETHERNET_DATA_SIZE ;
    Remainder = UartDataLen % ETHERNET_DATA_SIZE;

    if ( 0 != Remainder )
    {
        Count  += 1;
    }



    pBuff = pInMem->pQueueHead;

    pBuffFirst = pBuff;

    for ( i = 0; i < Count && pBuff; i++ )
    {
        pPkt = pBuff->FrmData;

        pUartFrm = ( UART_TO_ETHERNET_FRM * )   pBuff->FrmData->Data ;


        pUartFrm->ethFrmCount = flip16 ( Count );
        pUartFrm->ethFrmIndex = flip16 ( i );

        uLen  = ( Count == 1 ) ? UartDataLen : ETHERNET_DATA_SIZE;

        if ( i == Count - 1 && 0 != Remainder )
            uLen = Remainder;

        pUartFrm->uartFrmLen = flip32 ( uLen );

        memcpy ( pUartFrm->uartFrm,  pUartData + i * ( ETHERNET_DATA_SIZE ), uLen );

        pPkt->LTfield = flip16 ( UART_ETHERNET_TYPE_DEFINE ) ;

        memcpy ( pPkt->Srce, hwaddr, 6 );

        memcpy ( pPkt->Dest, DstAddr, 6 );

        pPkt->NoBytes = sizeof ( ADI_ETHER_FRAME_BUFFER ) - sizeof ( pPkt->NoBytes ) + ( UART_TO_ETHERNET_FRM_SIZE + uLen );

        pPkt->NoBytes |= 0x1000;

        pOutMem ->pQueueTail = pBuff;

        pBuff = pBuff->pNext;

        pInMem->ElementCount--;
        pOutMem->ElementCount++;

    }

    if ( i == Count )
    {
        pInMem->pQueueHead = pBuff;
        pOutMem->pQueueHead = pBuffFirst;
        if(pOutMem->pQueueTail!=NULL)
        {
            pOutMem->pQueueTail->pNext = NULL;
        }

        ret = Count;
    }

    else if ( i < Count )
    {
        ret  = 0;
    }


    return ret;

}


/* 将串口帧数据转换成以太网帧数据，成功返回以太网帧数目，否则，返回0*/
static int UartFrm2EtherFrm ( char *pUartData , unsigned int  UartDataLen, unsigned char hwaddr[6], unsigned char DstAddr[6], EMAC_FRAME_Q *pInMem, EMAC_FRAME_Q *pOutMem )
{
    int ret = 0;

    if ( !pUartData || !pInMem || !pOutMem )
        return 0;

    return PackData (  pUartData,  UartDataLen,  hwaddr, DstAddr, pInMem, pOutMem );

}





/* 将以太网帧数据转换成串口帧数据，成功返回串口帧数据字节长度，否则，返回0 */

/*Notes: 只处理一帧数据*/

static int EtherFrm2UartFrm ( u_char *pRecvFrm, char *pUartBuff , int nStartPos )
{

    UART_TO_ETHERNET_FRM *pUartFrm;

    char *UartData;

    unsigned int uartFrmLen ;

    int  buffIdx = nStartPos;

    if ( !pUartBuff || !pRecvFrm )
        return -1;


    pUartFrm = ( UART_TO_ETHERNET_FRM * ) ( pRecvFrm + 14 );

    UartData = pUartFrm->uartFrm;

    uartFrmLen = flip32 ( pUartFrm->uartFrmLen );

    memcpy ( pUartBuff + buffIdx , UartData, uartFrmLen );

    buffIdx += uartFrmLen;


    return  buffIdx;
}


////////////////////////////////
/****************************************************************
 * Initialises, assigns Tx and Rx buffers to each
 * network interface.
 *
 * Buffer structure
 *
 *   ----------------  ---------------   -----------------------
 *   ADI_ETHER_BUFFER| buffer_overhead|  ADI_ETHER_FRAME_BUFFER
 *   ----------------  ----------------  -----------------------
 ****************************************************************/
static int InitBuff ( const unsigned int inMemSize, char *MemArea )
{
    int i, overhead = 0;

    int nw_ifce_buffer_length = 0;
    int total_buffer_length = 0;

    unsigned int BUFF_AREA_START = 0;

    unsigned int BUFF_AREA_LEN = 0;

    int rx_len, tx_len;

    int num_if;
    short buffs;

    BUFF_AREA_START = ( unsigned int ) ( ( ( unsigned int ) ( MemArea + 32 ) ) & ~31 );
    BUFF_AREA_LEN   = ( unsigned int ) inMemSize;

    //LWIP_ASSERT("Supplied memory is not aligned",CHECK_ALIGNMENT((unsigned int)MemArea));

    // defined in the user configuration file.
    num_if =  user_net_num_ifces;

    // get driver specific overhead
    //
    for ( i = 0; i < num_if; i++ )
    {

        //	  adi_ether_GetBufferPrefix( g_hDev[i],(void*)&overhead);
        user_net_config_info[i].buff_overhead  = 0;

    }

    // Caluculate the total buffer space for rx/tx and for all n/w interfaces.
    nw_ifce_buffer_length = 0;

    for ( i = 0; i < num_if; i += 1 )
    {

        rx_len = sizeof ( ADI_ETHER_BUFFER ) + user_net_config_info[i].buff_overhead + user_net_config_info[i].rx_buff_datalen;
        tx_len = sizeof ( ADI_ETHER_BUFFER ) + user_net_config_info[i].buff_overhead + user_net_config_info[i].tx_buff_datalen;

        // make rx and tx lengths multiple of 32 byte cache lines
        rx_len = ( rx_len + 31 ) & ~31;
        tx_len = ( tx_len + 31 ) & ~31;

        user_net_config_info[i].rx_len_align = rx_len;
        user_net_config_info[i].tx_len_align = tx_len;

        nw_ifce_buffer_length  = user_net_config_info[i].rx_buffs * rx_len;
        nw_ifce_buffer_length  += user_net_config_info[i].tx_buffs * tx_len;

        if ( BUFF_AREA_LEN - total_buffer_length < nw_ifce_buffer_length )
        {
            buffs = ( BUFF_AREA_LEN - total_buffer_length ) / ( rx_len + tx_len );

            if ( buffs < 1 )
            {
                printf ( "InitBuff: NO enough memory!\n" );
                return -1;
            }

            user_net_config_info[i].rx_buffs = buffs;
            user_net_config_info[i].tx_buffs = buffs;

            nw_ifce_buffer_length  = user_net_config_info[i].rx_buffs * rx_len;
            nw_ifce_buffer_length  += user_net_config_info[i].tx_buffs * tx_len;
        }

        user_net_config_info[i].buff_area = ( char * ) ( BUFF_AREA_START + total_buffer_length );
        user_net_config_info[i].buff_area_size = nw_ifce_buffer_length;

        // add it to the total length
        total_buffer_length += nw_ifce_buffer_length;
    }

    return 1;
}

static void InitFrameBuff ( ETH_CFG_INFO *bsInfo )
{
    ADI_ETHER_BUFFER *p;

    int rx_len, tx_len, count;

    ADI_ETHER_BUFFER *rx_head = NULL;
    ADI_ETHER_BUFFER *tx_head = NULL;

    char *buf;

    if ( !bsInfo || bsInfo->rx_buff_datalen < MIN_ETHER_FRAME_LEN ||
            bsInfo->tx_buff_datalen < MIN_ETHER_FRAME_LEN )
        return;

    if ( !bsInfo->buff_area || 0 >= bsInfo->buff_area_size )
        return;

    bsInfo->xmt_queue.pQueueHead = NULL;
    bsInfo->xmt_queue.pQueueTail = NULL;
    bsInfo->xmt_queue.ElementCount = 0;

    bsInfo->recv_queue.pQueueHead = NULL;
    bsInfo->recv_queue.pQueueTail = NULL;
    bsInfo->recv_queue.ElementCount = 0;

    // calculate total requirement for each rx and tx buffer

    rx_len = bsInfo->rx_len_align;
    tx_len = bsInfo->tx_len_align;

    rx_len = ( ( rx_len + 3 ) / 4 ) * 4;
    tx_len = ( ( tx_len + 3 ) / 4 ) * 4;

    rx_len = ( rx_len + 31 ) & ~31;
    tx_len = ( tx_len + 31 ) & ~31;

    buf = ( char * ) ( ( ( unsigned int ) bsInfo->buff_area + 31 ) & ~31 );

    // allocate buffers in required ratio from supplied memory area
    //while (bsInfo->buff_area_size > rx_len || bsInfo->buff_area_size > tx_len)
    if ( bsInfo->buff_area_size > rx_len || bsInfo->buff_area_size > tx_len )
    {
        int n;

        for ( n = 0; n < bsInfo->rx_buffs; n += 1 )
        {
            if ( bsInfo->buff_area_size < rx_len )
                break;

            p = ( ADI_ETHER_BUFFER * ) bsInfo->buff_area;

            bsInfo->buff_area += rx_len;

            bsInfo->buff_area_size -= rx_len;

            p->pNext = rx_head;
            rx_head = p;

            if ( 0 == n )
            {
                bsInfo->recv_queue.pQueueTail = p;
            }

        }

        for ( n = 0; n < bsInfo->tx_buffs; n += 1 )
        {
            if ( bsInfo->buff_area_size < tx_len )
                break;

            p = ( ADI_ETHER_BUFFER * ) bsInfo->buff_area;

            bsInfo->buff_area += tx_len;

            bsInfo->buff_area_size -= tx_len;

            p->pNext = tx_head;
            tx_head = p;

            if ( 0 == n )
            {
                bsInfo->xmt_queue.pQueueTail = p;
            }
        }
    }

    // initialise each buffer's ADI_ETHER_BUFFER descriptor
    p = rx_head;
    count = 0;

    while ( p )
    {
        p->FrmData = ( ADI_ETHER_FRAME_BUFFER * ) ( ( char * ) p + sizeof ( ADI_ETHER_BUFFER ) + bsInfo->buff_overhead );

        /* set up first desc to point to receive frame buffer  */

        /* set up second desc to point to status word */


        count += 1;
        p = p->pNext;
    }

    bsInfo->rx_buffs = count;

    bsInfo->recv_queue.pQueueHead = rx_head;

    bsInfo->recv_queue.ElementCount = bsInfo->rx_buffs;

    //	bsInfo->recv_queue.pQueueTail->pNext = bsInfo->recv_queue.pQueueHead ; //成环状


    p = tx_head;
    count = 0;

    while ( p )
    {
        p->FrmData =  ( ADI_ETHER_FRAME_BUFFER * ) ( ( char * ) p + sizeof ( ADI_ETHER_BUFFER ) + bsInfo->buff_overhead );

        /* set up first desc to point to receive frame buffer */

        /* set up second desc to point to status word */

        count += 1;
        p = p->pNext;
    }

    bsInfo->tx_buffs = count;

    bsInfo->xmt_queue.pQueueHead = tx_head;

    bsInfo->xmt_queue.ElementCount = bsInfo->tx_buffs;

}


static int push_queue ( EMAC_FRAME_Q *pQueue, ADI_ETHER_BUFFER  *pBuffer )
{

    int32_t NumInputBuffers = 0;
    ADI_ETHER_BUFFER *pTempBuffer = pBuffer, *pLastBuffer = NULL;

    if ( !pQueue || !pBuffer )
    {
        return 0;
    }


    /* typically the number of incoming buffers are small */
    do
    {
        NumInputBuffers++;
        pLastBuffer = pTempBuffer;
        pTempBuffer = pTempBuffer->pNext;

    }
    while ( pTempBuffer != NULL );

    //ENTER_CRITICAL_REGION();
    //int int_sts = cli();

    /* Now insert and update the queue */
    if ( ( pQueue->pQueueHead == NULL ) && ( pQueue->pQueueTail == NULL ) )
        pQueue->pQueueHead = pBuffer;

    else
        pQueue->pQueueTail->pNext = pBuffer;

    pQueue->pQueueTail    = pLastBuffer;
    pQueue->ElementCount += NumInputBuffers;

    //EXIT_CRITICAL_REGION();
    //sti ( int_sts );

    return NumInputBuffers;
}



static int netSend(pcap_t *fp, unsigned char *packet, int nSize)
{

    /* Send down the packet */
    if(fp==NULL)
        return 1;
    if (pcap_sendpacket(fp, packet, nSize /* size */) != 0)
    {
        fprintf(stderr,"\nError sending the packet: %s\n", pcap_geterr(fp));


        return 0 ;
    }


    return 1;
}

/////////DLL导出函数///////////////////////////////////////////////////////

 int  __declspec(dllexport) InitMemBuff()
{
    char* ether_stack_block;

    ether_stack_block = (char *) malloc ( ETHER_STACK_SIZE );

    if ( ether_stack_block == NULL )
    {
        printf ( " ether_stack_block: failed to allocate memory to the stack \n" );
        return ( -1 );
    }

    memset ( ether_stack_block, 0, ETHER_STACK_SIZE );
    /*必须要清零，后面只给用到的变量重新赋值，
    当这些值用来初始化寄存器时,没用到的变量的值会干扰寄存器
    */

    /* init buf mem */
    InitBuff ( ETHER_STACK_SIZE, ether_stack_block );

    InitFrameBuff ( &user_net_config_info[0] );

    return 1;

}

void __declspec(dllexport)  GetallDevName(char **name,char **desc, unsigned char &arrSize )
{


    /* 获取本机设备列表 */
    if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &g_alldevs, errbuf) == -1)
    {
        fprintf(stderr,"Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }

    int i = 0;

    pcap_if_t *d;

    for(d=g_alldevs; d && i < arrSize; d=d->next,i++)
    {
        if(name)
            name[i] = d->name;
        if(desc)
            desc[i] = d->description;
    }

    arrSize = i;

}
//约定好每个名称和描述符按200个字节计算
void __declspec(dllexport)  GetallDevName_ex(char *name,char *desc, int &nameSize, int &descSize )
{
    int nameLen, descLen;

    int nameTotalLen = 0;

    int descTotalLen = 0;
    int c=0,i;

    pcap_if_t *d;
    /* 获取本机设备列表 */
    if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &g_alldevs, errbuf) == -1)
    {
        fprintf(stderr,"Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }
    for(d = g_alldevs; d!=NULL ; d=d->next)
    {

        if ( nameSize > nameTotalLen )
        {
            nameLen = strlen( d->name);
            for(i=0;i<nameLen;i++)
                *(name+c*200+i)=d->name[i];
            //strcat(name, d->name);
            nameTotalLen += nameLen;
            //name[nameTotalLen++] = '\n';
        }

        if( descSize > descTotalLen)
        {

            descLen = strlen(d->description);
            for(i=0;i<descLen;i++)
                *(desc+c*200+i)=d->description[i];
                //*(desc+c*200+i)='a';
            //strcat(desc, d->description);
            descTotalLen += descLen;
            //desc[descTotalLen++] = '\n';
        }
        c++;
    }

    //strcpy(name,"                                                                                 ");
    nameSize = c;
    descSize = c;
}


int  __declspec(dllexport) SetDev(char* devName, int readTimeout_ms)
 {

    pcap_if_t *d;

    if(!devName)
    {
        return 0;
    }

    for(d = g_alldevs; d ; d=d->next)
    {
        if(0 == strcmp(d->name, devName) )
            break;
    }

    if( !d)
    {
        fprintf(stderr,"Error in setDev for find dev: %s\n", devName);
        return 0;
    }


    /* Open the output device */
    if ( (g_fp = pcap_open(d->name,			// name of the device
                        65535,				// portion of the packet to capture (only the first 148 bytes)
                        PCAP_OPENFLAG_PROMISCUOUS, 	// promiscuous mode
                        readTimeout_ms,				// read timeout
                        NULL,				// authentication on the remote machine
                        errbuf				// error buffer
                        ) ) == NULL)
    {
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);


        return 0;
    }

    //set filter
    u_int netmask;

    struct bpf_program fcode;

    char packet_filter[] = "ether proto 0x06ff and ether dst 00:0a:1a:00:05:18";

    if(d->addresses != NULL)
        /* Retrieve the mask of the first address of the interface */
        netmask=((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
    else
        /* If the interface is without addresses we suppose to be in a C class network */
        netmask=0xffffff;

     //compile the filter
    if (pcap_compile(g_fp, &fcode, packet_filter, 1, netmask) <0 )
    {
        fprintf(stderr,"/nUnable to compile the packet filter. Check the syntax./n");

        return 0;
    }

    //set the filter
    if (pcap_setfilter(g_fp, &fcode)<0)
    {
        fprintf(stderr,"/nError setting the filter./n");

        return 0;
    }

    return 1;


 }

int  __declspec(dllexport) SetDev_ex(char* devName, unsigned char srcMac[6], unsigned char destMac[6],int readTimeout_ms)
{

    pcap_if_t *d;

    if(!devName)
    {
        return 0;
    }

    for(d = g_alldevs; d ; d=d->next)
    {
        if(0 == strcmp(d->name, devName) )
            break;
    }

    if( !d)
    {
        fprintf(stderr,"Error in setDev for find dev: %s\n", devName);
        return 0;
    }


    /* Open the output device */
    if ( (g_fp = pcap_open(d->name,			// name of the device
        65536,				// portion of the packet to capture (only the first 148 bytes)
        PCAP_OPENFLAG_PROMISCUOUS, 	// promiscuous mode
        readTimeout_ms,				// read timeout
        NULL,				// authentication on the remote machine
        errbuf				// error buffer
        ) ) == NULL)
    {
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);


        return 0;
    }

    //set filter
    u_int netmask;

    struct bpf_program fcode;

    char packet_filter[128] = "ether proto 0x06ff and ether dst ";
    char mac_filter[64] = {0};

    memcpy( user_net_config_info[0].hwaddr, srcMac, 6);

    memcpy( user_net_config_info[0].DstAddr, destMac, 6);

    sprintf(mac_filter, " %02x:%02x:%02x:%02x:%02x:%02x", srcMac[0], srcMac[1], srcMac[2], srcMac[3], srcMac[4], srcMac[5]);

    strcat(packet_filter, mac_filter);

    if(d->addresses != NULL)
        /* Retrieve the mask of the first address of the interface */
        netmask=((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
    else
        /* If the interface is without addresses we suppose to be in a C class network */
        netmask=0xffffff;

    //compile the filter
    if (pcap_compile(g_fp, &fcode, packet_filter, 1, netmask) <0 )
    {
        fprintf(stderr,"/nUnable to compile the packet filter. Check the syntax./n");

        return 0;
    }

    //set the filter
    if (pcap_setfilter(g_fp, &fcode)<0)
    {
        fprintf(stderr,"/nError setting the filter./n");

        return 0;
    }

    return 1;


}
    void  __declspec(dllexport)  set_out_byte_out_time(int value)
    {
        send_byte_time_out=value;
    }

    void del_sleep(int time){
    int delayTime = time; //微秒级的延时.
    LARGE_INTEGER m_liPerfFreq={0};
        if (!QueryPerformanceFrequency(&m_liPerfFreq))
    {
        printf("你的当前计算机硬件不支持高精度计时器\n");
    return;
    }
        LARGE_INTEGER m_liPerfStart={0};
        QueryPerformanceCounter(&m_liPerfStart);
    LARGE_INTEGER liPerfNow={0};
    for(;;)
    {
    QueryPerformanceCounter(&liPerfNow);
    double time=( ((liPerfNow.QuadPart -
    m_liPerfStart.QuadPart)*1000000)/(double)m_liPerfFreq.QuadPart);
    if (time >= delayTime)
    break;
    }
   }
int  __declspec(dllexport) EthSend( char *pUartBuff , unsigned int  UartFrmLen )
{

    int ret = 0;
    int nEthFrmSize;

    ADI_ETHER_BUFFER *pBuff;

    ADI_ETHER_FRAME_BUFFER *pPkt;

    EMAC_FRAME_Q ethFrmQueue={0};

    //分帧
    ret = UartFrm2EtherFrm ( pUartBuff , UartFrmLen, user_net_config_info[0].hwaddr, user_net_config_info[0].DstAddr, &( user_net_config_info[0].xmt_queue ), &ethFrmQueue );

    pBuff = ethFrmQueue.pQueueHead;

    //发送
    while( pBuff )
    {
        pPkt = pBuff->FrmData;

        nEthFrmSize = (pPkt->NoBytes) & (~0x1000);

        ret = netSend( g_fp, (unsigned char *)pPkt->Dest, nEthFrmSize );

        if(0 == ret)
            break;

        //
        pBuff= pBuff->pNext;
                    //Sleep(1);
                    del_sleep(send_byte_time_out);

    }

    //buff复用
    ret = push_queue ( &( user_net_config_info[0].xmt_queue ), ethFrmQueue.pQueueHead );

    return ret;

}
//int  __declspec(dllexport) EthRecv( char *pUartBuff , unsigned int*  pUartFrmLen ,long *t1,long *t2,long *t3)
int  __declspec(dllexport) EthRecv( char *pUartBuff , unsigned int*  pUartFrmLen)
{
    int ret = 0;
    long tim;
    struct pcap_pkthdr *header = NULL;

    u_char *pkt_data = NULL;

    UART_TO_ETHERNET_FRM *pUartFrm = NULL;

    int nEthFrmCount, nEthFrmIdx ;

    *pUartFrmLen = 0;
    //pcap_loop(g_fp, 0, packet_handler, NULL);
    tim=GetTickCount();
    //*t1=tim;
    if(g_fp==NULL)
        return 0;
    while( ( ret = pcap_next_ex( g_fp, &header, (const u_char**)&pkt_data) ) >= 0 )
    {
        if(ret == 0)
        {
            //continue; // Timeout elapsed
            break;
        }

        if((pkt_data[12] == 0x06) && (pkt_data[13] == 0xff))
        {
            pUartFrm =  ( UART_TO_ETHERNET_FRM * ) ( pkt_data + 14 );
            nEthFrmCount = flip16 ( pUartFrm->ethFrmCount );
            nEthFrmIdx = flip16 ( pUartFrm->ethFrmIndex );

            ret =  EtherFrm2UartFrm ( pkt_data, pUartBuff,  g_TxBuffStartPos );
            g_TxBuffStartPos = ret;

            //只有一帧数据或是最后一帧数据,收到完整的串口帧
            if ( (1 == nEthFrmCount)  || (nEthFrmIdx ==  nEthFrmCount - 1 ))
            {

                *pUartFrmLen = g_TxBuffStartPos;
                g_TxBuffStartPos = 0;
                break;
            }
            pkt_data[12] =0;
            pkt_data[13] =0;
        }
        if((GetTickCount()-tim)>10000)	//超过10秒，退出
        {
            //*t2=(GetTickCount()-tim);
            //break;
            return -2;
        }
    }

    if(ret == -1)
    {
        printf(" Error reading the packets: %s\n ", pcap_geterr(g_fp));

        return -1;
    }
    //*t3=GetTickCount();
    return 1;

}
/*
struct pcap_pkthdr *header = NULL;

u_char *pkt_data = NULL;

UART_TO_ETHERNET_FRM *pUartFrm = NULL;

int nEthFrmCount, nEthFrmIdx ;

*pUartFrmLen = 0;


void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
if( pkt_data[12] == 0x06 && pkt_data[13] == 0xff)
{
    pUartFrm =  ( UART_TO_ETHERNET_FRM * ) ( pkt_data + 14 );
    nEthFrmCount = flip16 ( pUartFrm->ethFrmCount );
    nEthFrmIdx = flip16 ( pUartFrm->ethFrmIndex );

    ret =  EtherFrm2UartFrm ( pkt_data, pUartBuff,  g_TxBuffStartPos );
    g_TxBuffStartPos = ret;

    //只有一帧数据或是最后一帧数据,收到完整的串口帧
    if ( 1 == nEthFrmCount  || nEthFrmIdx ==  nEthFrmCount - 1 )
    {

        *pUartFrmLen = g_TxBuffStartPos;
        g_TxBuffStartPos = 0;
        break;
    }
}

}
*/
