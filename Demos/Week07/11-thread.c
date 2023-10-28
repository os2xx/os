/*
 * Copyright (C) 2015-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Sat 28 Oct 2023 12:00
 * REV07: Wed 25 Mar 2020 09:00
 * REV06: Wed 29 Aug 2018 18:00
 * REV05: Wed 01 Nov 2017 19:00
 * REV04: Tue 13 Dec 2016 15:00
 * START: Wed 30 Sep 2015 00:00
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"
#define  nSem 7

sem_t	sem[nSem];

void* thread1 (void* a) {
   sem_wait   (&sem[1]);
   printf("T1X\n");
   sem_post   (&sem[4]);
}

void* thread2 (void* a) {
   sem_wait   (&sem[2]);
   printf("T2X\n");
   sem_post   (&sem[5]);
   sem_post   (&sem[1]);
}

void* thread3 (void* a) {
   printf("T3X\n");
   sem_post   (&sem[6]);
   sem_post   (&sem[2]);
}

void* thread4 (void* a) {
   sem_wait   (&sem[4]);
   printf("T44\n");
   sem_wait   (&sem[5]);
   printf("T45\n");
   sem_wait   (&sem[6]);
   printf("T46\n");
}

void main(void) {
   printf("MAIN\n");
   for (int ii=1;ii<nSem;ii++)
      sem_init(&sem[ii], 0, 0);
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   daftar_trit   (thread4);
   jalankan_trit ();
   beberes_trit  ("TREXIT");
}


/*
# INFO: PTHREAD: See also "99-myutils.c" and "99-myutils.h"
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
# INFO:                   sem_init():      init a semaphore.
# INFO:                   sem_wait():      wait a semaphore.
# INFO:                   sem_post():      signal a semaphore.
 */

