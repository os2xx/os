/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2019-2 (midterm)
 * REV02: Thu 26 Oct 2023 19:00
 * REV01: Fri 07 Feb 2020 01:00
 * START: Tue 22 Oct 2019 18:00
 */

#include <stdio.h>
int aa=0;
int* function(int* bb) {
   return bb;
}
void main (void) {
   int cc=aa++;
   printf("START\n");
   printf("1. aa = %d\n", aa);
   printf("2. *function()=%d\n", *function(&cc));
   printf("3. cc = %d\n", ++cc);
   printf("STOP\n");
}

