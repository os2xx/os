/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2018-1 (midterm)
 * REV03: Thu 26 Oct 2023 19:00
 * REV02: Fri 07 Feb 2018 01:00
 * REV01: Thu 17 Jan 2019 13:00
 * START: Mon 01 Jan 2018 00:00
 * NOTE: ASCII 61H = a; 62H = b
 */

#include <stdio.h>

void main(void) {
   unsigned int   ii='a';
   unsigned char  ch='b';
   unsigned char* st="dcba";
   printf("START\n");
   printf(" ii    = %X or %c\n",   ii,  ii);
   printf(" ch    = %X or %c\n",   ch,  ch);
   printf("*st    = %X or %c\n",  *st, *st);
   printf(" st[2] = %X or %c\n", st[2], st[2]);
   printf("STOP\n");
}

