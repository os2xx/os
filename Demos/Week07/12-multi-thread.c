/*
 * Copyright (C) 2017-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV03: Sat 28 Oct 2023 12:00
 * REV02: Wed 25 Mar 2020 09:00
 * REV01: Wed 29 Aug 2018 18:00
 * START: Mon 27 Nov 2017 10:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"
#define  NTHREAD      8
#define  RECDEEP      8
#define  LOOP1  100
#define  LOOP2  100
#define  LOOP3  100

volatile unsigned share=0;
unsigned multiloop(int recursive) {
   sleep(1);
   unsigned dummy = share;
   for (int ii; ii<LOOP1; ii++) {
      for (int jj; jj<LOOP2; jj++) {
         for (int kk; kk<LOOP3; kk++) {
            dummy++;
         }
      }
   }
   share = dummy;
   if (recursive-- < 0)
      return share;
   else
      return multiloop(recursive);
}

void* thread (void* a) {
   printf("Start Thread %8.8X ...\n", share);
   share=multiloop(RECDEEP);
   printf("Stop  Thread %8.8X ...\n", share);
}

void main(void) {
   printf("This is MAIN\n");
   for (int ii=0;ii<NTHREAD;ii++)
      daftar_trit  (thread);
   jalankan_trit ();
   beberes_trit  ("TREXIT!");
}

/*
# INFO: PTHREAD: See also "99-myutils.c" and "99-myutils.h"
# INFO:                   Terdapat perbedaan nilai "share" antar "thread()".
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
 */

