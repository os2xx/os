/*
 * Copyright (C) 2017-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV07: Sat 28 Oct 2023 12:00
 * REV06: Wed 25 Mar 2020 08:00
 * REV05: Wed 29 Aug 2018 18:00
 * REV04: Tue 17 Apr 2018 09:00
 * REV01: Wed 17 May 2017 17:00
 * START: Wed 03 May 2017 12:00
 *
 * sem_init(), sem_wait(), sem_post(): semaphore
 * sleep(X): sleep X seconds
 * daftar_trit(T):  register thread T
 * jalankan_trit(): start all registered threads.
 * beberes_trit():  exit all threads above.  */

#define jmlKIRI     7
#define jmlKANAN    5
#define SLEEP       1000
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"

sem_t   syncModKiri, syncModKanan;
sem_t   syncKiriMod, syncKananMod;
sem_t   mutexCetak;
int     aCetak = 0;

#define aKanan 1
#define aKiri  2

void cetak(char* posisi, int id) {
   sem_wait(&mutexCetak);
   printf("%3.3d %s(%2.2d)\n", aCetak++, posisi, id);
   fflush(NULL);
   sem_post(&mutexCetak);
   rehat_acak(SLEEP);
}

void* Moderator (void* a) {
   int ii;
   while (TRUE) {
      for (ii=0; ii<jmlKIRI;  ii++)
         sem_wait (&syncKiriMod);
      for (ii=0; ii<jmlKANAN; ii++) {
         sem_post (&syncModKanan);
      }
      for (ii=0; ii<jmlKANAN; ii++)
         sem_wait (&syncKananMod);
      for (ii=0; ii<jmlKIRI;  ii++) {
         sem_post (&syncModKiri);
      }
   }
}

void* Kanan (void* a) {
   int id = getADDglobalID(aKanan);
   while (TRUE) {
      sem_wait (&syncModKanan);
      cetak("-+-+-+Kanan", id);
      sem_post (&syncKananMod);
   }
}

void* Kiri (void* a) {
   int id = getADDglobalID(aKiri);
   while (TRUE) {
      cetak("Kiri-+-+-+-", id);
      sem_post (&syncKiriMod);
      sem_wait (&syncModKiri);
   }
}

int main(int argc, char * argv[]) {
   int ii;

   init_globalID();
   sem_init (&syncModKiri,  0, 0);
   sem_init (&syncModKanan, 0, 0);
   sem_init (&syncKiriMod,  0, 0);
   sem_init (&syncKananMod, 0, 0);
   sem_init (&mutexCetak,   0, 1);

   for (ii = 0 ; ii < jmlKANAN; ii++)
      daftar_trit(Kanan);
   for (ii = 0 ; ii < jmlKIRI; ii++)
      daftar_trit(Kiri);
   daftar_trit(Moderator);

   jalankan_trit();
   beberes_trit("Selese...");
}


/*
# INFO: Alternately Left and Right with PTHREAD. 
# INFO:                   Kiri():          one left pthread.
# INFO:                   Kanan():         one right pthread.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
# INFO:                   sem_init():      init a semaphore.
# INFO:                   sem_wait():      wait a semaphore.
# INFO:                   sem_post():      signal a semaphore.
 */

