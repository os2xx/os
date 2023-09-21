/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: sprintf() prints to a character string pointer (char* string).
 * REV02: Sun 17 Sep 2023 09:00
 * REV01: Sun 23 Feb 2020 16:00
 * START: Mon 28 Jan 2019 10:00
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define STRING      "This is a string"
#define LONG_STRING "Is this a long long long long string?"

char string_array[256];

void main(void) {
   sprintf(string_array, "%s\n", STRING);
   printf("%s", string_array);
   sprintf(string_array, "%s\n", LONG_STRING);
   printf("%s", string_array);
   string_array[7]=0;
   printf("%s\n", string_array);
}

