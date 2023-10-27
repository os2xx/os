/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Fri 27 Oct 2023 07:00
 * REV07: Tue 24 Mar 2020 13:52:25 WIB 2020
 * REV06: Wed 29 Aug 2018 16:11:46 WIB 2018
 * REV02: Mon 30 Oct 2017 10:24:44 WIB 2017
 * START: Mon 24 Oct 2016 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>

void main(void) {
   int ii;
   printf("Sleeping 3s with fflush(): ");
   fflush(NULL);
   for (ii=0; ii < 3; ii++) {
      sleep(1);
      printf("x ");
      fflush(NULL);
   }
   printf("\nSleeping with no fflush(): ");
   for (ii=0; ii < 3; ii++) {
      sleep(1);
      printf("x ");
   }
   printf("\n");
}

/*
# INFO: System call "fflush()"
# INFO:                   Compare the first loop with fflush() and the second one.
 */

