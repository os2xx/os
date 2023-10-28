/*
 * Copyright (C) 2023-2023 BinKadal, Sdn. Bhd.
 * modified by Heri Kurniawan
 * This program is free script/software. This program is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2023-2 (midterm)
 REV01: Sat 28 Oct 2023 18:00
 START: Sun 01 Oct 2023 00:00
 */

#include <stdio.h>
int returnInt(int ii) {
   return ii;
}
char returnChar(char cc) {
   return cc;
}
void main(void) {
    unsigned char xx='A';
    int ii=0x50515253;
    printf("returnChar ==%c\n",
            returnChar((char) ii));
    printf("returnChar ==%#x\n", 
      (int) returnChar((char) ii));
    printf("returnInt  ==%c\n",  
     (char) returnInt(ii));
    printf("returnInt  ==%#x\n",
            returnInt(ii));
    printf("mystery int==%#X\n",
            (ii - xx + 0x40));
    printf("mystery char=%c\n",
            (ii - xx + 0x40));
}

