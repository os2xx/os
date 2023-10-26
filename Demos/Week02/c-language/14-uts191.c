/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2019-1 (midterm)
 * REV03: Thu 26 Oct 2023 19:00
 * REV02: Fri 07 Feb 2020 01:00
 * START: Mon 24 Mar 2019 23:00
 */

// Rahmat M. Samik-Ibrahim 
// Clue: ASCII ’a’ is 0x61.
#include <stdio.h>
void main (void) {
   unsigned char ch1='a', ch2='y', ch3='z';
   printf("START\n");
   printf("1) ch1 = %c or ASCII %#X\n", ch1, ch1);
   ch1 = ch1 + ch3 - ch2;
   printf("2) ch1 = %c or ASCII %#X\n", ch1, ch1);
   printf("STOP\n");
}

