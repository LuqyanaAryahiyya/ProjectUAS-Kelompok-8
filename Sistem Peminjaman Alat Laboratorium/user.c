#include "file.h"

// Menampilkan alat yang tersedia
void totalalat(){
    FILE *fp = fopen("alat.txt", "r"); 
    if(fp == NULL){ 
        printf("File alat.txt tidak ditemukan!\n"); 
        return;
    }
    item tool; // deklarasi variabel bertipe item
