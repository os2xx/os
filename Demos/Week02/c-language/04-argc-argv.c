/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: Abount variables "argv" and "argc" in function main().
# INFO:                   run with an argument: ./04-argc-argv arg1 arg2 arg3
 * REV05: Thu 26 Oct 2023 19:00
 * REV04: Fri 07 Feb 2020 01:00
 * REV03: Tue 10 Dec 2019 07:00
 * REV02: Tue 28 Aug 2018 13:00
 * START: Tue 13 Sep 2016 12:00
 *
 * TAKE NOTE(BA)
 * In the beginning this program defined a main method with argc and argv as parameters
 * ARGC (argument counter) is represents the number of things that you entered into the 
 * command line when running this program on a terminal
 * ARGV (argument vector) is an array that holds the string values of the things that 
 * were entered on the command line when running this program
 * When you run this program, line 14 will print the value of argument on your command
 * (integer) line to console and line 17 will print the value of variable argv (char) 
 * on your console
 * Example : type it to run this program
 * OUTPUT (below) :
 * The value of argc    is 2
 * =============================================
 * The value of argv[0] is ./04-argc-argv
 * The value of argv[1] is test
 * =============================================
 */

#include <stdio.h>
void main(int argc, char *argv[]) {
   printf("The value of argc    is %d\n", argc);
   printf("=============================================\n");
   for (int ii=0; ii < argc; ii++) {
      printf("The value of argv[%d] is %s\n", ii, argv[ii]);
   }
   printf("=============================================\n");
}

