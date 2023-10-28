/*
 * Copyright (C) 2015-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Sat 28 Oct 2023 10:00
 * REV07: Mon 13 Apr 2020 07:57:03 WIB 2020
 * REV05: Wed 29 Aug 2018 18:34:21 WIB 2018
 * REV01: Wed 02 Nov 2016 11:49:39 WIB 2016
 * START: Wed 30 Sep 2015 XX:XX:XX UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

sem_t	generik;
sem_t	generik2;

void* thread1 (void* a) {
   sem_wait   (&generik);
   printf("THREAD1: I am second!\n");
   sem_post   (&generik2);
   beberes_trit  ("Bye Bye THREAD1...");
}

void* thread2 (void* a) {
   printf("THREAD2: I am first!\n");
   sem_post   (&generik);
   beberes_trit  ("Bye Bye THREAD2...");
}

void* thread3 (void* a) {
   sem_wait   (&generik2);
   printf("THREAD3: I am last!\n");
   beberes_trit  ("Bye Bye THREAD3...");
}

void main(void) {
   sem_init      (&generik,  0, 0);
   sem_init      (&generik2, 0, 0);
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   jalankan_trit ();
   beberes_trit  ("Bye Bye Main...");
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

