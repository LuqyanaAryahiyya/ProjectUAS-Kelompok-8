#include "file.h"

// Fungsi garis untuk pemisah tampilan
void garis(){
    printf("================================================================================\n");
}

// Fungsi untuk menampilkan daftar alat
void tampilAlat(){
    FILE *fp = fopen("alat.txt", "r");
    if(!fp){
        printf("Data alat tidak ditemukan.\n");
        return;
    }

    item tool;
    garis();
    printf("%-5s %-20s %-15s %-10s %-10s %-10s\n", 
           "ID", "Nama", "Merek", "Model", "Tahun", "Jumlah");
    garis();

    while(fscanf(fp, "%u|%49[^|]|%49[^|]|%49[^|]|%u|%u\n", &tool.id, tool.nama, tool.merek, tool.model, &tool.tahun, &tool.jumlah) == 6){
        if(tool.jumlah > 0){
            printf("%-5u %-20s %-15s %-10s %-10u %-10u\n", tool.id, tool.nama, tool.merek,  tool.model, tool.tahun, tool.jumlah);
            }
    }

    garis();
    fclose(fp);
}

// Fungsi untuk menambah data alat
void tambahAlat(){
    FILE *fp = fopen("alat.txt", "a");
    if(fp == NULL){
        printf("Gagal membuka file alat.txt!\n");
        return;
    }

    item tool;
    printf("Masukkan ID Alat: ");
    scanf("%u", &tool.Id_Alat);
    getchar();

    printf("Masukkan Nama Alat: ");
    fgets(tool.Nama_Alat, sizeof(tool.Nama_Alat), stdin);
    tool.Nama_Alat[strcspn(tool.Nama_Alat, "\n")] = '\0';

    printf("Masukkan Merek Alat: ");
    fgets(tool.Merek_Alat, sizeof(tool.Merek_Alat), stdin);
    tool.Merek_Alat[strcspn(tool.Merek_Alat, "\n")] = '\0';

    printf("Masukkan Model Alat: ");
    fgets(tool.Model_Alat, sizeof(tool.Model_Alat), stdin);
    tool.Model_Alat[strcspn(tool.Model_Alat, "\n")] = '\0';

    printf("Masukkan Tahun Produksi: ");
    scanf("%u", &tool.Tahun_Produksi);
    printf("Masukkan Jumlah Unit: ");
    scanf("%u", &tool.Jumlah_unit);

    fprintf(fp, "%u|%s|%s|%s|%u|%u\n",
            tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat, tool.Model_Alat,
            tool.Tahun_Produksi, tool.Jumlah_unit);

    fclose(fp);
    printf("Data alat berhasil ditambahkan!\n");
}

// Fungsi untuk mengedit data alat
void editAlat(){
    FILE *fp = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
