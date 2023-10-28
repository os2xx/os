/*
 * Copyright (C) 2011-2023 BinKadal, Sdn. Bhd.
 * provided this notice, and the copyright notice, are preserved. 
 * REV06: Sat 28 Oct 2023 12:00
 * REV05: Mon 13 Apr 2020 08:00
 * REV03: Wed 29 Aug 2018 18:00
 * REV02: Tue 07 Nov 2017 20:00
 * REV01: Wed 02 Nov 2016 11:00
 * START: Wed 30 Mar 2011 02:00
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "99-myutils.h"

sem_t    mutex, db, empty, full, globalIDmutex;

/* TRIT ***************************************************/
int       jumlah_trit = 0;

void*     trits  [MAX_THREAD];
pthread_t trit_id[MAX_THREAD];

void daftar_trit(void *trit) {
   if(jumlah_trit >= MAX_THREAD) {
      printf("\n ERROR MAX daftar_trit %d\n",jumlah_trit);
      exit(1);
   }
   trits[jumlah_trit++] = trit;
}

void jalankan_trit(void){
   int ii;
   for (ii=0;ii<jumlah_trit;ii++) {
      if(pthread_create(&trit_id[ii], NULL, trits[ii], NULL)) {
         printf("\n ERROR pthread_creat: %d\n",ii);
         exit(1);
      }
   }
   for (ii=0;ii<jumlah_trit;ii++){
      if(pthread_join(trit_id[ii], NULL)) {
         printf("\n ERROR pthread_join: %d\n",ii);
         exit(1);
      }
   }
}

void beberes_trit(char* pesan) {
   if (pesan != NULL)
      printf("%s\n",pesan);
   fflush(NULL);
   pthread_exit(NULL); // will wait until all threads terminate.
}

/* REHAT **********************************************/
int  pertamax    = TRUE;

void rehat_acak(long max_mdetik) {
   struct timespec tim;
   long            ndetik;
  
   if (pertamax) {
      pertamax = FALSE;
      srandom((unsigned int) time (NULL));
   }
   ndetik      = random() % max_mdetik;
   tim.tv_sec  = ndetik   / 1000L;
   tim.tv_nsec = ndetik   % 1000L * 1000000L;
   nanosleep(&tim,NULL);
} 

/* globalID ********************************************* */

int globalID[MAX_globalID];

void init_globalID (void) {
   sem_init (&globalIDmutex, 0, 1);
   for (int ii=0; ii<MAX_globalID; ii++) {
      globalID[ii]=0;
   }
}

int getADDglobalID (int id) {
   sem_wait (&globalIDmutex);
   int ii=globalID[id]++;
   sem_post (&globalIDmutex);
   return ii;
}

/* BOUNDED BUFFER *****************************************/
bbuf_t buf;

void init_buffer(void) {
   buf.in    = 0;
   buf.out   = 0;
   buf.count = 0;
   sem_init   (&mutex, 0, 1);
   sem_init   (&empty, 0, BUFFER_SIZE);
   sem_init   (&full,  0, 0);
}

void enter_buffer(int entry) {
   sem_wait(&empty);
   sem_wait(&mutex);
   buf.count++;
   buf.buffer[buf.in] = entry;
   buf.in = (buf.in+1) % BUFFER_SIZE;
   sem_post(&mutex);
   sem_post(&full);
}

int remove_buffer(void) {
   int item;
   sem_wait(&full);
   sem_wait(&mutex);
   buf.count--;
   item = buf.buffer[buf.out];
   buf.out = (buf.out+1) % BUFFER_SIZE;
   sem_post(&mutex);
   sem_post(&empty);
   return item;
}

/* READERS WRITERS ****************************************/
int readerCount;

void init_rw(void) {
   readerCount = 0;
   sem_init   (&mutex,  0, 1);
   sem_init   (&db,     0, 1);
}

int startRead(void) {
   sem_wait(&mutex);
   if (++readerCount == 1 )
      sem_wait(&db);
   sem_post(&mutex);
   return readerCount;
} 

int endRead(void) {
   sem_wait(&mutex);
   if (--readerCount == 0 )
      sem_post(&db);
   sem_post(&mutex);
   return readerCount;
} 

void startWrite(void) {
   sem_wait(&db);
}

void endWrite(void) {
   sem_post(&db);
}

/*
 * TAKE NOTE()
 */

