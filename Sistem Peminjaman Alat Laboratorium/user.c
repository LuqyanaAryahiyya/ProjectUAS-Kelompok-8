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
    }
    garis();
    printf("Daftar alat yang sedang dipinjam:\n");
    garis();
    printf("%-20s %-5s %-20s %-15s\n", "User", "ID", "Nama Alat", "Merek"); // Header tabel
    garis();
    char user[50], nama[50], merek[50];
    unsigned int id;
    while(fscanf(fp, "%49[^|]|%u|%49[^|]|%49[^\n]\n", user, &id, nama, merek) == 4){ // Membaca data peminjaman
        printf("%-20s %-5u %-20s %-15s\n", user, id, nama, merek); // Menampilkan data peminjaman
   }
    garis();
    fclose(fp);
}   

// Fungsi meminjam alat
void minjamalat(const char *username){ 
    FILE *fp = fopen("alat.txt", "r"); 
    FILE *temp = fopen("temp.txt", "w"); 
    FILE *pinjam = fopen("peminjaman.txt", "a"); //membuka file peminjaman untuk menambah data
    if(!fp || !temp || !pinjam){ 
        printf("Gagal membuka file!\n");
        return;
    }
    unsigned int id; // Variabel untuk menyimpan ID alat yang akan dipinjam
    int found = 0; //  untuk menandai apakah alat ditemukan
    item tool;
    printf("Masukkan ID alat yang ingin dipinjam: ");
    scanf("%u", &id); 
    while(fscanf(fp, "%u|%49[^|]|%49[^|]|%49[^|]|%u|%u\n", &tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat, tool.Model_Alat, &tool.Tahun_Produksi, &tool.Jumlah_unit) == 6){
        if(tool.Id_Alat == id){ 
            found = 1; // Menandai bahwa alat ditemukan
            if(tool.Jumlah_unit > 0){
                tool.Jumlah_unit--; // Mengurangi jumlah unit alat
                fprintf(pinjam, "%s|%u|%s|%s\n", username, tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat);
                printf("Berhasil meminjam %s!\n", tool.Nama_Alat);
            }else{
                printf("Stok habis!\n");
            }
        }
        fprintf(temp, "%u|%s|%s|%s|%u|%u\n", tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat, tool.Model_Alat, tool.Tahun_Produksi, tool.Jumlah_unit);
    }
    fclose(fp);
    fclose(temp);
    fclose(pinjam);
    if(found){ // Jika alat ditemukan, perbarui file alat.txt
        remove("alat.txt"); 
        rename("temp.txt", "alat.txt"); 
    }else{
        remove("temp.txt"); 
        printf("ID tidak ditemukan.\n");
    }
}

// Fungsi mengembalikan alat
void balikinalat(const char *username){ // Menerima
    FILE *fp = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *pinjam = fopen("peminjaman.txt", "r");
    FILE *pinjam_temp = fopen("pinjam_temp.txt", "w");
    if(!fp || !temp || !pinjam || !pinjam_temp){
        printf("Gagal membuka file!\n");
        return;
    }
    unsigned int id;
    int found = 0, valid = 0; // found untuk menandai apakah alat ditemukan, valid untuk menandai apakah alat dipinjam oleh user
    item tool;
    printf("Masukkan ID alat yang ingin dikembalikan: ");
    scanf("%u", &id); // Membaca ID alat dari input user

    char file_user[50], nama[50], merek[50]; // Variabel untuk menyimpan data dari file peminjaman
    unsigned int file_id; // Variabel untuk menyimpan ID alat dari file peminjaman

    while(fscanf(pinjam, "%49[^|]|%u|%49[^|]|%49[^\n]\n", file_user, &file_id, nama, merek) == 4){ 
        if(strcmp(file_user, username) == 0 && file_id == id){ // strcmp untuk membandingkan string == 0 berarti sama
            valid = 1; // Menandai bahwa alat ini dipinjam oleh user
        }else{
            fprintf(pinjam_temp, "%s|%u|%s|%s\n", file_user, file_id, nama, merek);
        }
}
    fclose(pinjam);
    fclose(pinjam_temp);
    // Update alat jika valid
    while(fscanf(fp, "%u|%49[^|]|%49[^|]|%49[^|]|%u|%u\n", &tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat, tool.Model_Alat, &tool.Tahun_Produksi, &tool.Jumlah_unit) == 6){
        if(tool.Id_Alat == id){ // Jika alat dengan ID tersebut ditemukan
            found = 1;
            if(valid){
                tool.Jumlah_unit++;
                printf("Berhasil mengembalikan %s!\n", tool.Nama_Alat); 
            }
        }
        fprintf(temp, "%u|%s|%s|%s|%u|%u\n", tool.Id_Alat, tool.Nama_Alat, tool.Merek_Alat, tool.Model_Alat, tool.Tahun_Produksi, tool.Jumlah_unit);
    }
    fclose(fp);
    fclose(temp);
    if(found){
        remove("alat.txt"); 
        rename("temp.txt", "alat.txt"); 
        if(valid){
            remove("peminjaman.txt"); 
            rename("pinjam_temp.txt", "peminjaman.txt");
        }else{
            remove("pinjam_temp.txt"); 
            printf("Alat ini tidak tercatat sebagai alat yang Anda pinjam.\n"); 
        }
    }else{
        remove("temp.txt");
        remove("pinjam_temp.txt");
        printf("ID alat tidak ditemukan.\n");
    }
}
