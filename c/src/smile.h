#ifndef _SMILE_H_
#define _SMILE_H_

#include "api.h"

#define DEBUG_BYTE(byte) printf("0x%02x ", (u8) byte);
#define PRINT(ip, length) while (length--) {putchar(*ip++);}
#define PRINT_EOK putchar(':'); putchar(' ');
#define PRINT_INDENT printf("%-*s", indent, " ");

#define ZZ_DECODE(n) ((n >> 1) ^ (-(n & 1)))

#define PRINT_STRING_VALUE(ip, length) \
    putchar('"'); \
    PRINT(ip, length) \
    putchar('"');

#define PRINT_STRING_KEY(ip, length) \
    PRINT_INDENT \
    PRINT_STRING_VALUE(ip, length)

#define PRINT_INT_VALUE(ip) \
    printf("%d", ZZ_DECODE(ip));

#define PRINT_LONG_VALUE(ip) \
    printf("%lu", ZZ_DECODE(ip));

#define SUCCESS 0

#define BUFFER_SIZE 1024

// Smile Tokens
#define SMILE_EOS (u8) 0xFF
#define SMILE_EMPTY_STRING (u8) 0x20
#define SMILE_NULL (u8) 0x21
#define SMILE_TRUE (u8) 0x22
#define SMILE_FALSE (u8) 0x23

#define SMILE_START_ARRAY (u8) 0xF8
#define SMILE_END_ARRAY (u8) 0xF9
#define SMILE_START_OBJECT (u8) 0xFA
#define SMILE_END_OBJECT (u8) 0xFB

int smile_decode_header(u8*);
void smile_decode_key(u8**, struct content_handler*);
void smile_decode_value(u8**, struct content_handler*);
void smile_decode(u8*, int, struct content_handler*);

#endif /* !_SMILE_H_ */
