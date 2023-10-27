/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Fri 27 Oct 2023 07:00
 * REV07: Tue 24 Mar 2020 13:00
 * REV06: Wed 29 Aug 2018 16:00
 * REV02: Mon 30 Oct 2017 10:00
 * START: Mon 24 Oct 2016 09:00
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

