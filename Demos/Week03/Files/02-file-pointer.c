/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV06: Sun 17 Sep 2023 08:00
 * REV05: Sun 23 Feb 2020 16:00
 * REV04: Thu 17 Jan 2019 14:00
 * REV03: Wed 29 Aug 2018 20:00
 * REV02: Thu  5 Oct 2017 10:00
 * START: Tue 27 Sep 2016 12:00
 *
# INFO: Compare: File Pointer (FP) vs File Descriptor (FD)
 *
 */

#define	FILE4 "demo-file4.txt"
#include <stdio.h>
#include <stdlib.h>

void main(void) {
   FILE* fp;  
   int   cc;

   printf ("*** Open and listing file %s ***\n\n", FILE4);
   if ((fp=fopen(FILE4, "r")) == NULL) {
      printf("fopen error...\n");
      exit(1);
   }
   while((cc=fgetc(fp)) != EOF) {
      printf("%c", cc);
   }
   printf("\n");
   fclose(fp);
}

/*
 * TAKE NOTE(TA)
 * file tidak terbuka dan akan memberikan output :
 * fopen error...
 * karena file yang ingin kita buka adalah untuk dibaca ("r")
 * maka file nya harus sudah ada (exist)
 */


