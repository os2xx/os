/*
 * Copyright (C) 2021-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV00 Wed 24 Nov 2021 15:50:00 AM WIB
 * START Wed 24 Nov 2021 08:17:37 AM WIB
 */

#include <stdio.h>
#include <unistd.h>
#define  STRING1 "AAAAXBBBBXCCCCX"
#define  STRING2 "DDDDY"
#define  STRING3 "EEEEZ"
#define  FILE1   "61-dupdemo-demo.txt"
typedef  FILE*   FILEP;

void main(void) {
    FILEP fp1=fopen(FILE1,"w+");
    FILEP fp2=fopen(FILE1,"w+");
    FILEP fp3=fdopen(dup(fileno(fp2)),"w+");
    fprintf(fp1,"%s", STRING1);
    fprintf(fp2,"%s", STRING2);
    fprintf(fp3,"%s", STRING3);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
