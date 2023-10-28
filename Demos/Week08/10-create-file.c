/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV03: Sat 28 Oct 2023 12:00
 * REV02: Sat 11 Apr 2020 17:00
 * REV01: Thu 15 Nov 2018 09:00
 * START: Wed 14 Nov 2018 20:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef  struct {
   char  mystring[16];
   int   myint;
   char  ends[2];
} myshare;

#define MYFLAGS  O_CREAT|O_RDWR
char*   sfile="demo-file.bin";

void main(void) {
   printf("Create shared file \"%s\"\n", sfile);
   int ssize=sizeof(myshare);
   myshare* mymap=malloc(ssize);
   strcpy((char*) mymap,"AAAAAAAAAABBBBBBZZZZ\n");
   int fd=open(sfile,MYFLAGS,S_IRWXU);
   write(fd,mymap,ssize);
   close(fd);
   printf("Please check  file \"%s\"\n", sfile);
}

