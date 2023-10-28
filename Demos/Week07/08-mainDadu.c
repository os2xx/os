/*
 * Copyright (C) 2012-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV07: Sat 28 Oct 2023 10:00
 * REV05: Mon 11 Feb 2019 16:00
 * REV03: Tue 17 Apr 2018 09:00
 * REV01: Wed 02 Nov 2016 11:00
 * REV00: Wed 30 Sep 2015 00:00
 * START: Fri 30 Mar 2012 02:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"

#define P_REHAT  400
#define K_REHAT 2000
#define WINpoint  12

sem_t	mutex1;
	
int	idmaster=0;
int	winner=0;
int     nplayers=0;

void* Dice (void* a) {
   int dadu;
   printf("The Dice is ready...\n");
   while (TRUE) {
      rehat_acak(P_REHAT);
      dadu=(random() % 6) + 1;
      printf("Dice value %d\n", dadu);
      enter_buffer  (dadu);
      if (winner !=0) {
         while (nplayers > 0) {
            enter_buffer  (dadu);
            enter_buffer  (dadu);
            enter_buffer  (dadu);
            sleep(1);
         }
         break;
      }
   }
}

void* Player (void* a) {
   int id, prev=0, total=0;
   sem_wait (&mutex1);
   id=idmaster++;
   nplayers++;
   sem_post (&mutex1);
   printf   ("                        Player %d is ready...\n",id);
   while (total < WINpoint) {
      rehat_acak(K_REHAT);
      prev   = total;
      total += remove_buffer();
      if (winner !=0) break;
      printf("                        Player %d's points: %2d [plus %d] \n", 
                                      id, total, total-prev);
   }
   sem_wait (&mutex1);
   if (winner != 1)
      printf("                        Player %d WINS!!!! (%d)\n", id, total);
   winner = 1;
   printf("                        Player %d EXIT\n", id);
   nplayers--;
   sem_post (&mutex1);
}

int main(int argc, char * argv[]) {
   printf("The first player -- with more than %d points -- wins **** ****\n", WINpoint);
   sleep(1);
   sem_init (&mutex1, 0, 1);
   init_buffer();
   daftar_trit(Dice);
   daftar_trit(Player);
   daftar_trit(Player);
   daftar_trit(Player);
   daftar_trit(Player);
   daftar_trit(Player);
   jalankan_trit();
   beberes_trit("Done...");
}


/*
# INFO: Rolling the Dics with PTHREADs. 
# INFO:                   Player():        one pthread for each player.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
# INFO:                   sem_init():      init a semaphore.
# INFO:                   sem_wait():      wait a semaphore.
# INFO:                   sem_post():      signal a semaphore.
 */

