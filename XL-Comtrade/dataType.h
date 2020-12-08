#ifndef _DATATYPE_H_
#define _DATATYPE_H_


#ifdef __cplusplus
extern "C" {
#endif

    /************************************************************************/

#define XL_TRUE		1
#define XL_FALSE	0
#define XL_SUCCESS 	0
#define XL_FAILURE 	1

    /************************************************************************/
    /* WINDOWS 95/NT							*/
    /************************************************************************/

#if defined(_WIN32)				/* VC++, 32-Bit		*/

  //  typedef signed char         CHAR;
    typedef signed int			INT;
    typedef signed long int     LONG;

    typedef unsigned char       UCHAR;
    typedef unsigned int        UINT;
    typedef unsigned long       ULONG;

    typedef double				DOUBLE;
    typedef float				FLOAT;

    typedef signed char			INT8;
    typedef signed short		INT16;
    typedef signed int			INT32;
    typedef signed __int64		INT64;

    typedef	unsigned char   	INT8U;
    typedef	unsigned short		INT16U;
    typedef	unsigned long		INT32U;
    typedef	unsigned __int64	INT64U;

    typedef unsigned char		BOOLEAN;
    typedef	float				FLOAT32;
    typedef	double				FLOAT64;

    typedef signed int          RET;
  //  typedef void				VOID;

#endif


    /************************************************************************/
    /* LINUX SYSTEM								*/
    /************************************************************************/
#if defined(linux)

    typedef char                CHAR;
    typedef signed int          INT;
    typedef signed long int     LONG;

    typedef unsigned char       UCHAR;
    typedef unsigned int        UINT;
    typedef unsigned long       ULONG;

    typedef double              DOUBLE;
    typedef float               FLOAT;

    typedef signed char			INT8;
    typedef signed short		INT16;
    typedef signed int			INT32;
    typedef signed long long	INT64;

    typedef	unsigned char   	INT8U;
    typedef	unsigned short		INT16U;
    typedef	unsigned long		INT32U;
    typedef	unsigned long long	INT64U;

    typedef unsigned char		BOOLEAN;
    typedef	float				FLOAT32;
    typedef	double				FLOAT64;

    typedef  void               VOID;
    typedef  signed int	        RET;

#endif	/* linux */

#ifdef __cplusplus
}
#endif


#endif /* _DATATYPE_H_ */
