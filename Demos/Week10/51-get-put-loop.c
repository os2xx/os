/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * TAKE NOTE(AII)
 * getchar() reads a single character from the standard 
 * input stream and writes it to cc
 * putchar(char) writes a character (an unsigned char) 
 * specified by the argument char to stdout
 *
 * this program will continue to read character from stdin 
 * until EOF, that is, no more input from a stream
 * EOF is defined in stdio.h (and is usually -1). 
 * On linux, ctrl+d signals EOF, and on windows it's ctrl+z.
 *
 * REV06: Sat 28 Oct 2023 12:00
 * REV05: Tue 26 Nov 2019 11:00
 * REV04: Wed 27 Feb 2019 19:00
 * REV03: Wed 29 Aug 2018 20:00
 * REV01: Mon 02 Oct 2017 16:00
 * START: Mon 26 Sep 2016 18:00
 */

#include <stdio.h>

void main(void) {
   int cc; 
   while((cc = getchar()) != EOF) { 
      putchar(cc); 
   }
}
