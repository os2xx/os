/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * TAKE NOTE (AII)
 * getchar() reads a single character from the standard input
 * stream and writes it to cc
 * putchar(char) writes a character (an unsigned char)
 * specified by the argument char to stdout
 *
 * REV05: Sat 28 Oct 2023 12:00
 * REV04: Tue 26 Nov 2019 11:00
 * REV03: Wed 29 Aug 2018 20:00
 * REV02: Thu 05 Oct 2017 10:00
 * START: Mon 26 Sep 2016 18:00
 */

#include <stdio.h>

void main (void) {
   int cc = getchar(); 
   putchar(cc); 
   putchar('\n');
}

