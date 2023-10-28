/*
 * Copyright (C) 2011-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06: Sat 28 Oct 2023 10:00
 * REV05: Tue 24 Mar 2020 17:00
 * REV04: Wed 29 Aug 2018 18:00
 * REV03: Tue 17 Apr 2018 09:00
 * REV00: Wed 30 Sep 2015 00:00
 * START: Wed 30 Mar 2011 02:00
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

#define R_REHAT 4000
#define R_READ  4000
#define R_JUMLAH   4

#define W_REHAT 2000
#define W_WRITE 2000
#define W_JUMLAH   3

#define aReader 0
#define aWriter 1

void* Reader (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aReader);
   printf   ("                        READER %d: SIAP  ******\n", my_ID);
   while (TRUE) {
      printf("                        READER %d: REHAT ******\n", my_ID);
      rehat_acak(R_REHAT);
      printf("                        READER %d: MAU  MEMBACA\n", my_ID);
      printf("                        ***** JUMLAH PEMBACA %d\n", startRead());
      printf("                        READER %d:=SEDANG==BACA\n", my_ID);
      rehat_acak(R_READ);
      printf("                        READER %d: SELESAI BACA\n", my_ID);
      printf("                        ***** SISA PEMBACA %d\n", endRead());
   }
}

void* Writer (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aWriter);
   printf   ("WRITER %d: SIAP  *******\n", my_ID);
   while (TRUE) {
      printf("WRITER %d: REHAT *******\n", my_ID);
      rehat_acak(W_REHAT);
      printf("WRITER %d: MAU   MENULIS\n", my_ID);
      startWrite();
      printf("WRITER %d:=SEDANG==NULIS\n", my_ID);
      rehat_acak(W_WRITE);
      endWrite();
      printf("WRITER %d: SELESAI NULIS\n", my_ID);
   }
}

int main(int argc, char * argv[])
{
   int ii;
   init_rw();
   init_globalID();
   for (ii = 0 ; ii < R_JUMLAH; ii++)
      daftar_trit(Reader);
   for (ii = 0 ; ii < W_JUMLAH; ii++)
      daftar_trit(Writer);
   jalankan_trit();
   beberes_trit("Selese...");
}

/*
# INFO: Readers - Writers with PTHREAD.
# INFO:                   Reader():        a Reader.
# INFO:                      startRead():  the Reader starts   reading.
# INFO:                      endRead():    the Reader finishes reading.
# INFO:                   Write():         a Writer.
# INFO:                      startWrite(): the Writer starts   writing.
# INFO:                      endWrite():   the Writer finishes writing.
# INFO:                   rehat_acak():    random stop.
# INFO:                   daftar_trit():   register a pthread.
# INFO:                   jalankan_trit(): run the registered pthread(s).
# INFO:                   beberes_trit():  finished.
 */

