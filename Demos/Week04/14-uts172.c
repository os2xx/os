/*
 * Copyright (C) 2017-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2017-2 (midterm)
 * REV04: Thu 26 Oct 2023 20:00
 * REV03: Sun 23 Feb 2020 16:00
 * REV02: Wed 27 Feb 2019 19:00
 * REV01: Thu 12 Apr 2018 20:00
 * START: Mon 16 Oct 2017 21:00
 */

#include <stdio.h>

char* stringChar="HALLO";
char* stringPTR;

void main(void) {
    stringPTR=stringChar;
    printf ("ADDR1: %p VAL: %p STR: %s\n", &stringChar, stringChar, stringChar);
    printf ("ADDR2: %p VAL: %p STR: %s\n", &stringPTR,  stringPTR, stringPTR);
    while (*(++stringPTR) != 0 ) {
         printf ("ADDR3: %p VAL: %p STR: %s\n", &stringPTR,  stringPTR, stringPTR);
    }
    printf ("End of String = %p\n", stringPTR);
}

/*
 * TAKE NOTE (RM)
 * Program ini menggambarkan suatu pointer yang sedang menunjuk string
 * "HALLO" dipindahkan oleh perintah ++stringPTR yang ada di line 20. 
 * 
 * Ketika program ini dieksekusi akan menampilkan sejumlah baris 
 * "AADR3" dimana VAL adalah kata "HALLO" namun huruf pertamanya akan
 * hilang satu persatu. Ini bukti bahwa pointer stringPTR bergerak
 * akibat perintah pada line 20. 
 */
