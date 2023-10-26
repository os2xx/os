/*
 * Copyright (C) 2013-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: a loop example.
 * REV06: Thu 26 Oct 2023 19:00
 * REV05: Fri 07 Feb 2020 01:00
 * REV03: Tue 28 Aug 2018 13:00
 * START: Tue 01 Jan 2013 00:00
 */

#define LINETXT "==========\n"
#define OLOOPTXT "OL [%4.4d]\n"
#define OLOOP  4
#define ILOOP  3

#include <stdio.h>
void main(void) {
   int ii, jj;
   printf(LINETXT);
   for (ii=0; ii<OLOOP; ii++) {
      printf(OLOOPTXT, ii);
      for (jj=0; jj<ILOOP; jj++) {
         printf("    IL[%d]\n",jj);
      }
   }
   printf(LINETXT);
}

/*
 * TAKE NOTE(AII)
 * Looping in c is similar to looping in java
 *
 * The outer loop will execute the block 
 * including the inner loop 
 * 4 times as declared at the beginning in 
 * variable OLOOP.
 * 
 * The inner loop will print to console 3 times as declared
 * at the beginning in variable ILOOP
 */

