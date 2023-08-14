#ifndef _TYPES_H
#define _TYPES_H

#include <stdio.h>
#include <stdlib.h>

#define ZERO   0

typedef unsigned char  uint8_t  ;
typedef unsigned short uint16_t ;
typedef unsigned int   uint32_t ;

typedef signed   char  sint8_t  ;
typedef signed   short sint16_t ;
typedef signed   int   sint32_t ;


typedef enum ret_status {
    R_NOK,
    R_OK
}ret_status_t;




#endif // _TYPES_H
