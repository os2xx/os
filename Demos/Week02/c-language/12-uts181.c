/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2018-1 (midterm)
 * REV04: Thu 26 Oct 2023 19:00
 * REV03: Fri 07 Feb 2020 01:00
 * REV02: Thu 17 Jan 2019 13:00
 * START: Mon 30 Apr 2018 10:00
 */

#include <stdio.h>

void main(void) {
   char string[]="HALLO";
   printf("START\n");
   printf("%s\n",  string);
   printf("%c\n", *string);
   printf("%c\n",  string[1]);
   printf("STOP\n");
}

