/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 You are free to SHARE (copy and 
 redistribute the material in any medium
 or format) and to ADAPT (remix, 
 transform, and build upon the material 
 for any purpose, even commercially).
 This program is distributed in the hope 
 that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied 
 warranty of MERCHANTABILITY or FITNESS 
 FOR A PARTICULAR PURPOSE.

 * REV06: Sat 28 Oct 2023 12:00
 * REV05: Wed 25 Mar 2020 12:00
 * REV04: Mon 28 Oct 2019 21:00
 * REV03: Wed 29 Aug 2018 20:00
 * START: Wed 18 Apr 2018 19:00

# INFO: UAS 2018-1 (final term)
# INFO:                   To run:   ./50-181 

 */

// DO NOT USE THE SAME SEMAPHORE NAME!!!!
// Replace "demo" with your own SSO name.
#define SEM_COUNT1      "/count-1-demo"
#define SEM_COUNT2      "/count-2-demo"
#define SEM_MUTEX       "/mutex-demo"
#define SEM_SYNC        "/sync-demo"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

// Shared Memory: R/W with no name.
#define PROT    (PROT_READ | PROT_WRITE)
#define VISIBLE (MAP_ANON  | MAP_SHARED)

#define LOOP    2
#define BUFSIZE 1

sem_t*  ctr_prod;
sem_t*  ctr_cons;
sem_t*  mutex;
sem_t*  ssync;
int*    product;

// WARNING: NO ERROR CHECK! ////////////
void flushprintf(char* str,int ii) {
   printf("%s [%d]\n", str, ii);
   fflush(NULL);
}

void init(void) {
   product  = mmap(NULL, sizeof(int), 
                   PROT, VISIBLE, 0, 0);
   *product = 0;
   ctr_prod = sem_open(SEM_COUNT1, 
              O_CREAT, 0600, BUFSIZE);
   ctr_cons = sem_open(SEM_COUNT2, 
              O_CREAT, 0600, 0);
   mutex    = sem_open(SEM_MUTEX, 
              O_CREAT, 0600, 1);
   ssync    = sem_open(SEM_SYNC, 
              O_CREAT, 0600, 0);
}

void producer (void) {
   sem_wait(ssync);
   flushprintf("PRODUCER  PID",getpid());
   for (int loop = 0; loop < LOOP; loop++) {
      sem_wait(ctr_prod);
      sem_wait(mutex);
      flushprintf("PRODUCT  ",++(*product));
      sem_post(mutex);
      sem_post(ctr_cons);
   }
   wait(NULL);
}

void consumer (void) {
   flushprintf("CONSUMER  PID",getpid());
   sem_post(ssync);
   for (int loop = 0; loop < LOOP; loop++) {
      sem_wait(ctr_cons);
      sem_wait(mutex);
      flushprintf("CONSUME  ", *product);
      sem_post(mutex);
      sem_post(ctr_prod);
   }
}

// WARNING: NO ERROR CHECK! ////////////
void main(void) {
   flushprintf("STARTING  PID", getpid());
   init();
   if (fork()) producer (); //Parent
   else        consumer (); //Child
   sem_unlink(SEM_COUNT1);
   sem_unlink(SEM_COUNT2);
   sem_unlink(SEM_SYNC);
   sem_unlink(SEM_MUTEX);
   flushprintf("STOP HERE PID", getpid());
}

//       1         2         3         4
// 4567890123456789012345678901234567890

/*
 * TAKE NOTE (RMS)
 * TESTED ON WSL Windows 10:
 
 $ ./50-181
 STARTING  PID [252]
 CONSUMER  PID [253]
 PRODUCER  PID [252]
 PRODUCT   [1]
 CONSUME   [1]
 PRODUCT   [2]
 CONSUME   [2]
 STOP HERE PID [253]
 STOP HERE PID [252]
 $

 */

