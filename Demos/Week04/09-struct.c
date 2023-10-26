/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV05: Thu 26 Oct 2023 20:00
 * REV04: Sun 23 Feb 2020 16:00
 * REV03: Tue 28 Aug 2018 18:00
 * REV02: Wed 04 Oct 2017 21:00
 * START: Tue 27 Sep 2016 18:00
 */

#include <stdio.h>

typedef struct {
   char* nama;
   int   umur;
   int   semester;
   char* NIM;
} student;

void printStruct(student* ss) {
   printf("%-10s %11s %3d %2d\n", ss->nama, ss->NIM, ss->umur, ss->semester);
}

student global;
void init(void) {
   global.nama     = "Burhan";
   global.NIM      = "1205000003";
   global.umur     = 10;
   global.semester = 2;
}

void main(void) {
   student mhs = {"Ali", 12, 1, "1205000001"};
   printStruct(&mhs);
   init();
   printStruct(&global);
}

/*
 * TAKE NOTE(BA)
 * Struct atau structur adalah tipe data yang tersedia di C yang memperbolehkan
 * gabungan dari berbagai macam data (Berbeda dengan array yang hanya boleh 1 jenis data)
 * Biasa digunakan sebagai catatan / record. Contohnya seperti catatan data mahasiswa
 * yang terdiri dari nama(char/string), npm(char), umur(int), dan lainnya
 * Line 11-16 mendefinisikan sebuah tipe data struct dengan nama student (berisi char dan int)
 * Line 18 ada method untuk mencetak data pada Struct dan Line 22 adalah global variabel
 * Line 31 membuat variabel mhs dengan tipe data struct (student) dan
 * Line 33 memanggil fungsi init untuk mengisi variabel global (Line 23-28)
 * Line 32 dan 34 akan mencetak data mahasiswa tersebut (nama,NIM,umur,semester)
 */

