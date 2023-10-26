/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2018-1 (midterm)
 * REV04: Thu 26 Oct 2023 20:00
 * REV03: Sun 23 Feb 2020 16:00
 * REV02: Wed 27 Feb 2019 19:00
 * REV01: Wed 03 Oct 2018 19:00
 *
 * The "array"   starts  at 0x601040
 * The "pointer" address is 0x601050
 */

#include <stdio.h>

char  array[]="0123456789ABCDE";
char* pointer=array;
void  main(void) {
   printf("START\n");
   printf("%p\n", &pointer);
   printf("%p\n",  pointer);
   printf("%s\n",  pointer);
   printf("%d\n",  pointer[15]);
   printf("STOP\n");
}


