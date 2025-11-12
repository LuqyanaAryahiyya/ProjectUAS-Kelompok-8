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
