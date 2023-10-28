/*
 * Copyright (C) 2023-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2023-2 (midterm)
 * REV01: Mon 09 Oct 2023 18:00
 * START: Mon 09 Oct 2023 17:00
 */

/* 
This Clue #1 - Clue #6:
=======================
1: All strings end with 0x00.
2: All arrays start with index 0.
3: Address=64 bit Little ENDIAN.
4: ASCII ’0’ is 0x30.
5: ASCII ’A’ is 0x41.
6: ASCII ’a’ is 0x61.
*/

#include <stdio.h>
#include <string.h>
typedef unsigned long UL;
typedef char*     STRING;
char   array[]="0123456789ABCDE";
STRING   dummy="ZZZZZZZZZZZ";
STRING  string="abcdefghijklmno";

void main(void) {
    printf("X1. %#16.16lX\n", (UL)  dummy);
    printf("X2. %#16.16lX\n", (UL)  string);
    printf("\n");
    printf("X3. %#16.16lX\n", (UL) &array[0]);
    printf("X4. %#16.16lX\n", (UL) &dummy);
    printf("X5. %#16.16lX\n", (UL) &string);
    printf("\n");
    printf("01. %s\n",              string);
    printf("02. %c\n",             *string);
    string+=2;
    printf("03. %#16.16lX\n", (UL)  string);
    printf("04. %c\n",             *string);
    printf("\n");
    printf("05. %s\n",              array);
    string=&array[2];
    printf("06. %c\n",             *string);
    printf("07. %#16.16lX\n", (UL)  string);
    string+=2;
    printf("08. %c\n",             *string);
    printf("09. %#16.16lX\n", (UL)  string);
}

