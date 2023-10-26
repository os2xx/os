/*
 * Copyright (C) 2013-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: An introduction to function scanf().
 * REV05: Thu 26 Oct 2023 19:00
 * REV04: Sun 23 Feb 2020 16:00
 * REV03: Fri 07 Feb 2020 01:00
 * REV02: Tue 28 Aug 2018 13:00
 * START: Tue 01 Jan 2013 00:00
 */

#include <stdio.h> 
#include <stdlib.h> 

void main(void) { 
   int ii; 
   char buf[10];
   printf("Write a string: ");
   scanf("%s",buf);
   printf("Isi buffer = %s\n",buf);
}

/*
 * TAKE NOTE(AII)
 * scanf() reads formatted data from standard input 
 * and then writes the results into the arguments given
 * 
 * the line scanf("%s",buf); will read string inputted by
 * user and write the value to variable buf
 */

