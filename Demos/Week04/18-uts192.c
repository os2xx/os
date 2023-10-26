/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2019-2 (midterm)
 * REV02: Thu 26 Oct 2023 20:00
 * REV01: Sun 23 Feb 2020 16:00
 * START: Mon 21 Oct 2019 20:00
 */
/* 
This Clue #1 - Clue #5:
=======================
1: All strings end with 0x00.
2: A "string size" includes that 0x00.
3: All arrays start with index 0.
4: Address=64 bit Little ENDIAN.
5: ASCII ’0’ is 0x30.
The first 3 lines of program output:
====================================
1. &string1[0]=0x556677889910
2. &string2[0]=0x556677889918
3. &stringPtr =0x556677889928
*/

#include <stdio.h>
#include <string.h>
char  string1[]="0123456";
char  string2[]="0123456";
char* stringPtr;

void main(void) {
   int   size1=sizeof(string1);
   stringPtr=&string1[size1-1];
   printf("1. &string1[0]=%p\n", &string1[0]);
   printf("2. &string2[0]=%p\n", &string2[0]);
   printf("3. &stringPtr =%p\n", &stringPtr);
   printf("4.  stringPtr =%p\n",  stringPtr);
   *stringPtr = '7';
   printf("5.  STRING:   %s\n", &string1[0]);
}

