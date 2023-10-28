/*
 * Copyright (C) 2015-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV19: Sat 28 Oct 2023 10:00
 * REV11: Tue 24 Mar 2020 17:00
 * REV10: Thu 15 Nov 2018 19:00
 * REV02: Tue 18 Apr 2017 15:00
 * REV01: Wed 02 Nov 2016 11:00
 * START: Wed 30 Sep 2015 00:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "99-myutils.h"

volatile int loop  = 6; // display 6 times
volatile int share = 0; // start share=0

// fflush() I/O before sleep() 
void  flushsleep(int ii) {
   fflush(NULL);
   sleep (ii  );
}

// THREAD#1: start share=1000 --> share++
void* thread1 (void* a) {
   printf("THREAD#1-PID[%5.5d]\n", getpid());
   flushsleep(1);
   rehat_acak(100);
   share = 1000;
   while (loop > 0) {
      rehat_acak(100);
      share++;
   }
}

// THREAD#2: start share=2000 --> share--
void* thread2 (void* a) {
   printf("THREAD#2-PID[%5.5d]\n", getpid());
   flushsleep(1);
   rehat_acak(100);
   share = 2000;
   while (loop > 0) {
      rehat_acak(100);
      share--;
   }
}

// THREAD#3: display "share" every 1 second
void* thread3 (void* a) {
   printf("THREAD#3-PID[%5.5d]\n", getpid());
   while (loop-- > 0) {
      printf("---SHARE----+%5.5d+\n", share);
      flushsleep(1);
   }
}

// MAIN: start share=0
void main(void) {
   printf("---MAIN--PID[%5.5d]\n", getpid());
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   jalankan_trit ();
   beberes_trit  ("------------  Done.");
}

/*
# INFO: PTHREAD: See also "99-myutils.c" and "99-myutils.h"
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished
 */

