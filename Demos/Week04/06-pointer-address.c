/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV07: Thu 26 Oct 2023 20:00
 * REV06: Sun 23 Feb 2020 16:00
 * REV05: Tue 28 Aug 2018 18:00
 * REV04: Tue 03 Oct 2017 21:00
 * START: Fri 23 Sep 2016 15:00
 */

#include <stdio.h>
#define HEAD1 "VARIABLE  +++  VALUE +++ +CHR+ +++ ADDRESS  +++ +PTS TO+\n"
#define HEAD2 "!!! !!!!! ptrcopy++; ptrcopy++; ptrcopy++; ... !!!!! !!!\n"

void main(void) {
   unsigned char   varchr0='a';
   unsigned char*  ptrchr0=&varchr0;
   unsigned char*  ptrcopy=(char *) &ptrchr0;
   printf(HEAD1);
   printf("varchr0 = %#14X = %c  %16p\n",   varchr0, varchr0,  &varchr0);
   printf("ptrchr0 = %14p   %19p %#8.2X\n", ptrchr0, &ptrchr0, *ptrchr0);

   printf(HEAD2);
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
}

/*
 * TAKE NOTE(RL)
 * this program wants you to see what will happen
 * if a variable pointer get added
 */

