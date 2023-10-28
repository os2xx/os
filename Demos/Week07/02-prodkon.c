/*
 * Copyright (C) 2011-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV07: Sat 28 Oct 2023 10:00
 * REV06: Tue 24 Mar 2020 17:11:58 WIB 2020
 * REV05: Wed 29 Aug 2018 18:35:33 WIB 2018
 * REV04: Tue 17 Apr 2018 09:31:37 WIB 2018
 * START: Wed 30 Mar 2011 02:13:01 UTC 2011
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

#define P_REHAT 2000
#define K_REHAT 2000
int produk = 0;

void* Produsen (void* a) {
   printf("Produsen siap...\n");
   while (TRUE) {
      printf("P: REHAT ******\n");
      rehat_acak(P_REHAT);
      printf("P: PRODUKSI %d\n", produk);
      enter_buffer  (produk++);
   }
}

void* Konsumen (void* a) {
   printf   ("                        Konsumen siap...\n");
   while (TRUE) {
      printf("                        K: REHAT ******\n");
      rehat_acak(K_REHAT);
      printf("                        K: KONSUMSI %d\n", remove_buffer());
   }
}

int main(int argc, char * argv[])
{
   init_buffer();
   daftar_trit(Produsen);
   daftar_trit(Konsumen);
   jalankan_trit();
   beberes_trit("Selese...");
}


/*
# INFO: Producer - Consumer with PTHREAD.
# INFO:                   Produsen():      the producer.
# INFO:                   Konsumen():      the consumer.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
 */

