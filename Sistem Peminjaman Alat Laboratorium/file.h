#ifndef FILE_H  // Header utama yang berisi struktur data dan deklarasi fungsi
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur akun
typedef struct{
    char username[50];
    char password[50];
    char role[10];
}Akun;

// Struktur alat laboratorium
typedef struct{
    unsigned int Id_Alat;
    char Nama_Alat[50];
    char Merek_Alat[50];
    char Model_Alat[50];
    unsigned int Tahun_Produksi;
    unsigned int Jumlah_unit;
}item;

// Deklarasi fungsi umum
void garis();

// Deklarasi fungsi login
int login(const char *username, const char *password, char *role);

// Deklarasi fungsi admin
void tampilAlat();
void tambahAlat();
void editAlat();
void hapusAlat();

// Deklarasi fungsi user
void totalalat();
void alatdipinjam();
void minjamalat(const char *username);
void balikinalat(const char *username);
void menuUser(const char *username);

#endif
