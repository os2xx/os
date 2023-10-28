/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV03: Sat 28 Oct 2023 13:00
 * REV02: Wed 25 Mar 2020 16:00
 * REV01: Tue 26 Nov 2019 11:00
 * START: Wed 15 May 2019 12:00

# INFO: UAS 2019-1 (final term)
# INFO:                   To run:   ./75-191

 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILE    "75-os191-demo.txt"
#define STRING1 "AAABBBCCC"
#define STRING2 "DDDEEEFFF"
#define STRING3 "GGGHHHIII"

void main(void) {
   printf("See %s\n", FILE);
   int fd1=open(FILE, 
       O_CREAT|O_TRUNC|O_RDWR, 0644);
   int fd2=open(FILE, 
       O_CREAT|O_TRUNC|O_RDWR, 0644);
   int fd3=open(FILE, 
       O_CREAT|O_TRUNC|O_RDWR, 0644);
   write (fd1,STRING1, 9);
   write (fd2,STRING2, 6);
   write (fd3,STRING3, 3);
   close(fd1);
   close(fd2);
   close(fd3);
}
