/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: An introduction to function printf().
 * REV07: Sun 17 Sep 2023 08:00
 * REV06: Fri  7 Feb 2020 01:00
 * REV05: Tue 17 Sep 2019 18:00
 * REV02: Tue 28 Aug 2018 13:00
 * START: Thu 15 Sep 2016 11:00
 */

#include <stdio.h>

void main (void) {
   int   ii   = 74;             // Integer

   printf("(%%d)    ii = (%d)\n",    ii);
   printf("(%%5d)   ii = (%5d)\n",   ii);
   printf("(%%1d)   ii = (%1d)\n",   ii);
   printf("(%%-5d)  ii = (%-5d)\n",  ii);
   printf("(%%5.5d) ii = (%5.5d)\n", ii);
   printf("(%%5.3d) ii = (%5.3d)\n", ii);
   printf("(%%c)    ii = %c\n",      ii);
   printf("(%%x)    ii = %x\n",      ii);
   printf("(%%#x)   ii = %#x\n",     ii);
   printf("(%%X)    ii = %X\n",      ii);
   printf("(%%#X)   ii = %#X\n",     ii);
   printf("(%%o)    ii = %o\n",      ii);
   printf("(%%#o)   ii = %#o\n",     ii);
}

