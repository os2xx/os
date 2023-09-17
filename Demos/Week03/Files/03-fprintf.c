/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: fprintf() prints to a stdio stream (FILE* pointer).
 * REV02: Sun 17 Sep 2023 08:00
 * REV01: Sun 23 Feb 2020 16:00
 * START: Mon 28 Jan 2019 10:00
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DEMO "demo-file4.txt"

void main(void) {
   FILE *filep = fopen(DEMO, "aw"); 
   if (filep == NULL) {
      printf("fopen error...\n");
      exit(1);
   }
   fprintf(filep, "[fprintf] file: %s\n", DEMO);
   printf("See also file %s\n", DEMO);
   fclose(filep); 
}

