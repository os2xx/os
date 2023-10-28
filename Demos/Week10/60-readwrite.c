/*
 * Copyright (C) 2005-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06: Sat 28 Oct 2023 12:00
 * REV05: Tue 26 Nov 2019 11:00
 * REV03: Mon 05 Mar 2018 20:00
 * REV02: Mon 02 Oct 2017 16:00
 * REV01: Sun 16 Oct 2016 20:00
 * START: Sat 01 Jan 2005 00:00
 */

#define FILE1 "demo-fileA.txt"

#define  OLOOP 4
#define  ILOOP 40
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

void rwfile (char* fname);
void dirfile(char* dname);
void error  (char* msg);

/* MAIN ============================= */
void main(void) {
   printf("Listing current directory...\n");
   dirfile(".");
   printf("Testing read-write speed...\n");
   rwfile(FILE1);
}
/* DIRFILE ======================= */
void dirfile(char* dname) {
   DIR*            ddir;
   struct dirent*  dp;
   printf("     ");
   ddir = opendir(dname);
   if (ddir != NULL) {
      while ((dp=readdir(ddir))!= NULL)
         printf("%s  ", dp->d_name);
      closedir(ddir);
   }
   printf("\n\n");
}
/* ERROR ========================== */
void error(char* msg){
   perror(msg);
   exit(0);
}
/* RWFILE ========================== */
void rwfile(char* fname) {
   time_t tt;
   int    fd, ii, jj;
   char   buf[] = "Achtung... Achtung... AAAA BBBB CCCC DDDD\n";
   time(&tt);
   for (ii=0;ii<OLOOP;ii++) {
      if ((fd=creat(fname,00644)) < 0 )
         error("RWFILE: can not create file\n");
      for (jj=0;jj<ILOOP;jj++) {
         write(fd,buf,sizeof(buf)-1);
         fsync(fd);
      }
      close(fd);
      putchar('.');
      fflush(NULL);
   }
   tt=time(NULL)-tt;
   putchar('\n');
   printf("Total time: %d seconds\n", (int) tt);
}
