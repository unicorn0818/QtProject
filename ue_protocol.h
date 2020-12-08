#ifndef UE_PROTOCOL_H
#define UE_PROTOCOL_H
#include <pcap.h>
static int send_byte_time_out=300;

#ifdef __cplusplus
extern "C"  {
#endif


#define CONF_CMD_START_CHAR (0x68)
#define CONF_CMD_END_CHAR (0x16)

#define ETHERNET_DATA_SIZE (1400U)
#define UART_ETHERNET_TYPE_DEFINE (0x06FF)
#define MIN_ETHER_FRAME_LEN 64


    typedef unsigned char u8;
    typedef unsigned short u16;
    typedef unsigned int u32;

    /*   发送接收数据所使用的数据结构    */


    /* DMA Configuration  little endian */
    typedef struct ADI_DMA_CONFIG_REG
    {
        unsigned short b_DMAEN: 1;  /* 0 Enabled */
        unsigned short b_WNR: 1;    /* 1 Direction */
        unsigned short b_WDSIZE: 2; /* 2:3 Transer word size */
        unsigned short b_DMA2D: 1;  /* 4 DMA mode */
        unsigned short b_SYNC: 1;   /* 5 Retain FIFO */
        unsigned short b_DI_SEL: 1; /* 6 Data interrupt timing select */
        unsigned short b_DI_EN: 1;  /* 7 Data interrupt enabled */
        unsigned short b_NDSIZE: 4; /* 8:11 Flex descriptor size */
        unsigned short b_FLOW: 3;   /* 12:14 Flow */
    } ADI_DMA_CONFIG_REG;

    /* DMA Descriptor */
    typedef struct dma_descriptor
    {
        struct dma_descriptor *NEXT_DESC_PTR;
        unsigned int START_ADDR;
        ADI_DMA_CONFIG_REG CONFIG;
    } DMA_DESCRIPTOR;


    /* Ethernet Frame Buffer */
    typedef struct adi_ether_frame_buffer
    {
        unsigned short NoBytes;   /* the no. of following bytes */
        unsigned char Dest[6];    /* destination MAC address */
        unsigned char Srce[6];    /* source MAC address */
        unsigned short LTfield;   /* length/type field */
        char Data[1];    /* payload bytes */
    } ADI_ETHER_FRAME_BUFFER;

    /*  top level structure   */
    typedef struct adi_ether_buffer
    {
        DMA_DESCRIPTOR Dma[2];             /* first for the frame,second for the status  */
        ADI_ETHER_FRAME_BUFFER *FrmData;   /* pointer to data  */
        struct adi_ether_buffer *pNext;    /* next buffer */
        struct adi_ether_buffer *pPrev;    /* prev buffer */
        unsigned short IPHdrChksum;                   /* the IP header checksum */
        unsigned short IPPayloadChksum;               /* the IP header and payload checksum */
        unsigned int StatusWord;                    /* the frame status word */
    } ADI_ETHER_BUFFER;

    /*! Frame queue */
    typedef struct EMAC_FRAME_Q
    {
        ADI_ETHER_BUFFER  *pQueueHead;        /*!< frame queue head */
        ADI_ETHER_BUFFER  *pQueueTail;        /*!< frame queue tail */
        unsigned int            ElementCount;      /*!< number of buffers in a queue */

    } EMAC_FRAME_Q;



        void del_sleep(int time);
    /*=============  D A T A    T Y P E S   =============*/


    /* \struct Uart2Ethernet
    *
    * Structure map the Uart frame to the ethernet MAC frame
    */
    typedef struct Uart_TO_Ethernet_FRM
    {
        unsigned short ethFrmCount;
        short ethFrmIndex;
        unsigned int  uartFrmLen;
        char uartFrm[1];

    } UART_TO_ETHERNET_FRM;

#define UART_TO_ETHERNET_FRM_SIZE (2+2+4)


    typedef struct eth_cfg_info
    {
        size_t                    buff_overhead;

        short                     rx_buffs;
        short                     tx_buffs;
        // the maximum data size that each receive and transmit buffer must support
        short                     rx_buff_datalen;
        short                     tx_buff_datalen;

        short 					rx_len_align;
        short					tx_len_align;

        // the address and size of the area from which buffers are to be allocated
        // (must be 32-bit aligned, uncached and accessible by the controller)
        char                     *buff_area;
        int                       buff_area_size;

        // interface's individual (MAC) address
        unsigned char             hwaddr[6];
        unsigned char             DstAddr[6];

        // netif's device driver handle
        void                     *handle;

        // lists of received/transmitted buffers awaiting to be submit to Dev'RX/TX Channel
        EMAC_FRAME_Q recv_queue;
        EMAC_FRAME_Q xmt_queue;


        // lists of received/transmitted  buffers have been completed by EMAC awaiting APP processing/disposal
        //		QType rx_completed_q;
        //		QType tx_completed_q;

    } ETH_CFG_INFO;

    /*
    ETH_CFG_INFO user_net_config_info[] =
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
    };
    */


    //全局变量
    #ifdef UE_PROTOCOL_DLL_FILE

    extern int g_TxBuffStartPos;
    extern ETH_CFG_INFO user_net_config_info[2] ;

    #else



    #endif


    ///////////////////////////////////////////////////////////////////////////

    /*******************************************************************
    *   Function:    int InitMemBuff()

    *   Description: 初始化网口发送所需要的内存.

    *	@Params:         无

    *	@return： 	内存分配初始化成功，返回1，否则返回0
    *******************************************************************/
      int  __declspec(dllexport) InitMemBuff();




    /*******************************************************************
    *   Function:    void GetallDevName(char **name,char **desc, unsigned char &arrSize )

    *   Description: 获取本机所有的网卡设备，用户在调用前分配好 name, desc 的内存空间。eg:
                        char** name;
                        char** desc;
                        unsigned char uDevNum = 4;//本机可能拥有的最大网卡设备数；

                        name = (char **) malloc ( uDevNum * sizeof(char *) );
                        desc = (char **) malloc ( uDevNum * sizeof(char *) );
                        for(int j = 0; j < uDevNum; j++)
                        {
                            name[j] = (char *) malloc ( 64 * sizeof(char) );
                            desc[j] = (char *) malloc ( 64 * sizeof(char) );
                        }

    *	@@Params:    name: in & out, arrSize个设备的名称，
                     desc: in & out, arrSize个设备的描述，
                     arrSize: in & out, 输入时，传递name和desc的个数；输出时，返回设备的个数

    *	@return： 	无
    *******************************************************************/
     void __declspec(dllexport)  GetallDevName(char **name,char **desc, unsigned char &arrSize );


        /*******************************************************************
    *   Function:    void GetallDevName(char **name,char **desc, unsigned char &arrSize )

    *   Description: 获取本机所有的网卡设备，用户在调用前分配好 name, desc 的内存空间。eg:
                        char** name;
                        char** desc;
                        unsigned char uDevNum = 4;//本机可能拥有的最大网卡设备数；

                        name = (char **) malloc ( uDevNum * sizeof(char *) );
                        desc = (char **) malloc ( uDevNum * sizeof(char *) );
                        for(int j = 0; j < uDevNum; j++)
                        {
                            name[j] = (char *) malloc ( 64 * sizeof(char) );
                            desc[j] = (char *) malloc ( 64 * sizeof(char) );
                        }

    *	@@Params:    name: in & out, arrSize个设备的名称，不同设备名称中间以‘\n’隔开
                     desc: in & out, arrSize个设备的描述，不同设备描述中间以‘\n’隔开
                     arrSize: in & out, 输入时，传递name和desc的个数；输出时，返回设备的个数

    *	@return： 	无
    *******************************************************************/
     void __declspec(dllexport)  GetallDevName_ex(char *name,char *desc, int &nameSize,int &descSize );




    /*******************************************************************
    *   Function:    int SetDev(char* devName, int readTimeout_ms)

    *   Description: 设置使用哪一个网卡设备，打开设备，并设置MAC()过滤.

    *	@Params:     devName: in, 设备名称，由GetallDevName 的name[]提供。
                     readTimeout_ms: in, 网卡接收超时时间，单位ms。
                     eg:
                        SetDev(name[0], 1000);


    *	@return： 	成功返回1，否则返回0.
    *******************************************************************/
     int  __declspec(dllexport) SetDev(char* devName, int readTimeout_ms);



    /*******************************************************************
    *   Function:    int SetDev_ex(char* devName, unsigned char myMac[6],int readTimeout_ms)

    *   Description: 设置使用哪一个网卡设备，打开设备，并设置MAC过滤.

    *	@Params:     devName: in, 设备名称，由GetallDevName 的name[]提供。
                    srcMac: in, 设备的MAC地址，字符类型(16进制)
                    destMac: in, 报文的目的MAC地址，字符类型(16进制)
                     readTimeout_ms: in, 网卡接收超时时间，单位ms。
                     eg:
                        SetDev(name[0], 1000);


    *	@return： 	成功返回1，否则返回0.
    *******************************************************************/
     int  __declspec(dllexport) SetDev_ex(char* devName, unsigned char srcMac[6], unsigned char destMac[6],int readTimeout_ms);



    /*******************************************************************
    *   Function:    int EthSend( char *pUartBuff , unsigned int  UartFrmLen )

    *   Description: 网口发送，用户只需提供要发送的数据和长度即可，接口会执行Ethernet打包、分帧，发送.

    *	@Params:     pUartBuff: in, 待发送数据的buffer。
                     UartFrmLen: in, 待发送数据的长度，单位byte。

    *	@return： 	成功返回1，否则返回0.
    *******************************************************************/
      int  __declspec(dllexport) EthSend( char *pUartBuff , unsigned int  UartFrmLen );



    /*******************************************************************
    *   Function:    int EthRecv( char *pUartBuff , unsigned int*  pUartFrmLen )

    *   Description: 网口接收，用户需提供要足够大的接收buff（一般设置为可能的最大值 65536+8），和存放接收数据长度变量的地址。

    *	@Params:     pUartBuff: in & out, in, 存放接收数据的buffer; out, 接收数据的首指针。
                     pUartFrmLen: in & out, in, 存放接收数据长度变量的地址，out, 接收数据的长度，单位byte。

    *	@return： 	成功返回1，否则返回0.
    *******************************************************************/
     int  __declspec(dllexport) EthRecv( char *pUartBuff , unsigned int*  pUartFrmLen );

     void  __declspec(dllexport)  set_out_byte_out_time(int value);

    ////////////////////////////////////////////////////////////////////////////

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);


#ifdef __cplusplus
}
#endif
#endif // UE_PROTOCOL_H
