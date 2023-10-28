/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV03: Sat 28 Oct 2023 12:00
 * REV02: Sat 11 Apr 2020 17:00
 * REV01: Thu 15 Nov 2018 11:00
 * START: Wed 14 Nov 2018 20:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define MYFLAGS      O_RDWR
#define MYPROTECTION PROT_READ|PROT_WRITE
#define MYVISIBILITY MAP_SHARED
char*  sfile="demo-file.bin";

typedef  struct {
   char  mystring[16];
   int   myint;
   char  ends[2];
} myshare;

void main(void) {
   struct stat fsize;
   int    ssize=sizeof(myshare);
   int    fd=open(sfile,MYFLAGS,S_IRWXU);

   printf("Create mmap()\n");
   fstat(fd, &fsize);
   if (fsize.st_size < ssize) {
      printf("Does %s exist? Size >= %d?\n", sfile, ssize);
      exit(1);
   }
   myshare* mymap=mmap(NULL, ssize, MYPROTECTION, MYVISIBILITY, fd, 0);
   if (mymap == MAP_FAILED) {
      printf("mmap(): FAILED\n");
      exit(1);
   }
   mymap->mystring[0]='X';
   mymap->mystring[1]='Y';
   mymap->mystring[2]='Z';
   mymap->mystring[3]=' ';
   mymap->myint=0x61626364;
   close(fd);
   printf("Please check  file \"%s\"\n", sfile);
}

