/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV04: Sat 28 Oct 2023 13:00
 * REV03: Sun 03 May 2020 09:00
 * REV02: Wed 25 Mar 2020 17:00
 * REV01: Tue 17 Dec 2019 20:00
 * START: Mon 16 Dec 2019 15:00

# INFO: UAS 2019-2 (final term)
# INFO:                   To run:   ./76-192

 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE    "76-os192-demo.txt"

void main(void) {
   printf("See %s\n", FILE);
   printf ("OUT=%d\n", STDOUT_FILENO);
   close(STDOUT_FILENO);
   int fd1 = open (FILE, O_RDWR | 
              O_CREAT | O_TRUNC, 0644);
   int fd2 = dup2(fd1, 9);
   printf(         "A\n"); 
   fprintf(stdout, "B\n"); 
   dprintf(fd2,    "fd1=%d\nfd2=%d\n", 
                            fd1, fd2);
}

