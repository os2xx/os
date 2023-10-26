/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2019-1 (midterm)
 * REV02: Thu 26 Oct 2023 20:00
 * REV01: Sun 23 Feb 2020 16:00
 * REV00: Tue 01 Oct 2019 11:00
 * START: Fri 15 Mar 2019 13:00
 */

#include <stdio.h>
char  ch_array[]="abcdefg";
char* ch_pointer="ABCDEFG";

void main(void) {
   printf(" &ch_array[0]=%p\n", &ch_array[0]);
   printf("  ch_array[0]=%c\n",  ch_array[0]);
   ch_pointer = ch_pointer + 5;
   printf(" &ch_pointer =%p\n", &ch_pointer);
   printf("  ch_pointer =%p\n",  ch_pointer);
   printf(" *ch_pointer =%c\n", *ch_pointer);
}

/*
This Clue #1 - Clue #4:
=======================
1: All strings end with 0x00
2: Address=64 bit Little ENDIAN
3: ASCII ’A’ is 0x41
4: ASCII ’a’ is 0x61
5: Initially: addresses 0x556677889900-1F=0x00

This is the Program Output:
===========================
 &ch_array[0]=0x556677889910
  ch_array[0]=0
 &ch_pointer =0x556677889918
  ch_pointer =0x556677889909
 *ch_pointer =F
*/

