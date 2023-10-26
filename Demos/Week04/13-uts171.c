/*
 * Copyright (C) 2017-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2017-1 (midterm)
 * REV04: Thu 26 Oct 2023 20:00
 * REV03: Wed 26 Feb 2020 20:00
 * REV02: Sun 23 Feb 2020 16:00
 * REV01: Thu 17 Jan 2019 16:00
 * START: Thu 30 Mar 2017 18:00

 * INT is 32 bit little endian
 * 41H='A'; 42H='B'; 43H='C"; 44H='D'
 */

#include <stdio.h>
char chrary[]="ZZZZ ZZZZ ";
void main(void) {
   char  chrvar = 'M';
   int   intvar = 0x41424344;
   int*  intptr = (int*) chrary;
   printf("YY.     chrary=%p\n",  chrary);
   printf("ZZ.     intptr=%p\n",  intptr);
   printf("01.     chrvar=%c\n",  chrvar);
   printf("02.    *chrary=%c\n", *chrary);
   printf("03. str chrary=%s\n",  chrary);
   *intptr      =  intvar;
   printf("04. str chrary=%s\n",  chrary);
}


