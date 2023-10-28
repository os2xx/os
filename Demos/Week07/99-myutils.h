/*
 * Copyright (C) 2011-2023 BinKadal, Sdn. Bhd.
 * Feel free to copy and/or modify and/or distribute it, 
 * provided this notice, and the copyright notice, are preserved. 
 * REV05: Sat 28 Oct 2023 10:00
 * REV04: Wed 29 Aug 2018 18:00
 * REV03: Tue 07 Nov 2017 19:00
 * REV02: Mon 07 Nov 2016 14:00
 * START: Wed 30 Mar 2011 02:00
 */

#include <semaphore.h>

#define MAX_THREAD 256
#define MAX_globalID 5
#define BUFFER_SIZE  5
#define TRUE         1
#define FALSE        0

extern sem_t    mutex, db, empty, full, globalIDmutex;

typedef struct {
   int   buffer[BUFFER_SIZE];
   int   in;
   int   out;
   int   count;
} bbuf_t;

void daftar_trit   (void* trit);      // mempersiapkan "trit"
void jalankan_trit (void);            // menjalankan dan menunggu hasil dari
                                      // "daftar_trit"
void beberes_trit  (char* pesan);     // beberes menutup "jalankan_trit"

void rehat_acak    (long max_mdetik); // istirohat acak "0-max_mdetik" (ms)

void init_globalID (void);            // globalID
int getADDglobalID (int id);          // globalID[id]++

void init_buffer   (void);            // init buffer
void enter_buffer  (int entry);       // enter  an integer item 
int remove_buffer  (void);            // remove the item

void init_rw       (void);            // init readers writers
int  startRead     (void);            // start reading
int  endRead       (void);            // end reading
void startWrite    (void);            // start writing
void endWrite      (void);            // end writing

/*
 * TAKE NOTE ()
 */

