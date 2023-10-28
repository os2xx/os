/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV08: Sat 28 Oct 2023 13:00
 * REV07: Wed 25 Mar 2020 16:00
 * REV06: Tue 26 Nov 2019 11:00
 * REV03: Sun 16 Dec 2018 22:00
 * START: Thu 12 Dec 2018 19:00

# INFO: UAS 2018-2 (final term)
# INFO:                   To run:   ./74-182

 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FLAGS O_RDWR|O_CREAT|O_TRUNC
#define MODES 0644

#define FILE3 "74-os182-demo3.txt"
#define FILE4 "74-os182-demo4.txt"

void main(void) {
   printf("See %s and %s\n", FILE3, FILE4);
   int fd3 = open (FILE3,FLAGS,MODES);
   int fd4 = open (FILE4,FLAGS,MODES);
   dprintf(fd3, "fd%d\n", fd3);
   dprintf(fd4, "fd%d\n", fd4);
   close(STDOUT_FILENO); // STDOUT = 1
   int fd1 = dup(fd3);
   close(STDERR_FILENO); // STDERR = 2
   int fd2 = dup(fd4);
   dprintf(fd1, "fd%d\n", fd1);
   dprintf(fd2, "fd%d\n", fd2);
   close (fd1);
   close (fd2);
   close (fd3);
   close (fd4);
}
