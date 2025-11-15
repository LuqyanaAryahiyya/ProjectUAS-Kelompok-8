#include "file.h"

// Menampilkan alat yang tersedia
void totalalat(){
    FILE *fp = fopen("alat.txt", "r"); 
    if(fp == NULL){ 
        printf("File alat.txt tidak ditemukan!\n"); 
        return;
    }
    item tool; // deklarasi variabel bertipe item
    garis();
    printf("%-5s %-20s %-15s %-10s %-10s %-10s\n", "ID", "Nama", "Merek", "Model", "Tahun", "Jumlah"); // Header tabel
    garis();
    while(fscanf(fp, "%u|%49[^|]|%49[^|]|%49[^|]|%u|%u\n", &tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat, tool.Model_Alat, &tool.Tahun_Produksi, &tool.Jumlah_unit) == 6){
        if(tool.Jumlah_unit> 0) { 
            printf("%-5u %-20s %-15s %-10s %-10u %-10u\n", tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat, tool.Model_Alat, tool.Tahun_Produksi, tool.Jumlah_unit);
        }
    }
    garis();
    fclose(fp); // Menutup file
}

// Fungsi menampilkan alat yang dipinjam
void alatdipinjam(){
    FILE *fp = fopen("peminjaman.txt", "r"); // Membuka file peminjaman.txt untuk membaca
    if (fp == NULL) {
        printf("Belum ada data peminjaman.\n");
        return;
