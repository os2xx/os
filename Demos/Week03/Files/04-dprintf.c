/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: dprintf() prints to a file descriptor (int fd).
 * REV03: Sun 17 Sep 2023 09:00
 * REV02: Sun 21 Mar 2021 00:00
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
   int filed = open (DEMO, O_APPEND | O_RDWR , 0664);
   if (filed < 0) {
      printf("fopen error...\n");
      exit(1);
   }
   dprintf(filed, "[dprintf] file: %s; descriptor: %d\n", DEMO, filed);
   printf("See also file %s\n", DEMO);
   close(filed); 
}
