/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV04: Thu 26 Oct 2023 20:00
 * REV03: Sun 23 Feb 2020 16:00
 * REV02: Thu 04 Oct 2018 20:00
 * START: Wed 03 Oct 2018 19:00
 *
 */

#include <stdio.h>
/* Global Variables */
unsigned char    var_chr='a';
unsigned char*   pt1_chr=&var_chr;
unsigned char**  pt2_chr=&pt1_chr;
unsigned char*** pt3_chr=&pt2_chr;

void main(void) {
   printf("   var_chr=%c,      ADDR=%p\n",
              var_chr, &var_chr);
   printf("  *pt1_chr=%c,     VALUE=%p,     ADDR=%p\n",
             *pt1_chr,   pt1_chr, &pt1_chr);
   printf(" **pt2_chr=%c,  *pt2_chr=%p,    VALUE=%p,  ADDR=%p\n",
            **pt2_chr,  *pt2_chr,  pt2_chr, &pt2_chr);
   printf("***pt3_chr=%c, **pt3_chr=%p, *pt3_chr=%p, VALUE=%p, ADDR=%p\n", 
            ***pt3_chr, **pt3_chr, *pt3_chr,  pt3_chr, &pt3_chr);
}


