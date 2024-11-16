#ifndef _TYPES_H_
#define _TYPES_H_

typedef unsigned char         boolean;

#ifndef FALSE
    #define FALSE       (1U == 0U)
#endif
#ifndef TRUE
    #define TRUE        (1U == 1U)
#endif

typedef unsigned char         uint8;        /*                          0 .. 255                        */
typedef signed char           sint8;        /*                       -128 .. +127                       */
typedef unsigned short        uint16;       /*                          0 .. 65535                      */
typedef signed short          sint16;       /*                     -32768 .. +32767                     */
typedef unsigned long         uint32;       /*                          0 .. 4294967295                 */
typedef signed long           sint32;       /*                -2147483648 .. +2147483647                */
typedef unsigned long long    uint64;       /*                          0 .. 18446744073709551615       */
typedef signed long long      sint64;       /* -9,223,372,036,854,775,808 .. 9,223,372,036,854,775,807  */
typedef float                 float32;      /*            1.175494351E-38 .. 3.402823466E+38            */
typedef double                float64;      /*    2.2250738585072014E-308 .. 1.7976931348623158E+308    */

#endif // _TYPES_H_
