#include "file.h"  // Sudah mencakup semua #include dan deklarasi fungsi

// Menu untuk admin
void menuAdmin(){
    int pilih;
    do{
        garis();
        printf("MENU ADMIN LAB INFORMATIKA\n");
        garis();
        printf("1. Lihat semua alat\n");
        printf("2. Tambah alat\n");
        printf("3. Edit alat\n");
        printf("4. Hapus alat\n");
        printf("5. Keluar\n");
        garis();
        printf("Pilih menu: ");
        scanf("%d", &pilih);
        getchar();

        switch(pilih){
            case 1: tampilAlat(); 
            break;
            case 2: tambahAlat(); 
            break;
            case 3: editAlat(); 
            break;
            case 4: hapusAlat(); 
            break;
            case 5:
            printf("Keluar dari menu admin...\n");
            break;
            default:
            printf("Pilihan tidak valid!\n");
        }
    }while(pilih != 5);
}

// Fungsi menu untuk user
void menuUser(const char *username){ // Menerima username sebagai parameter
    int pilihan;
    do{
        garis();
        printf("MENU USER LAB INFORMATIKA\n");
        garis();
        printf("1. Lihat daftar alat\n");
        printf("2. Pinjam alat\n");
        printf("3. Kembalikan alat\n");
        printf("4. Lihat alat yang sedang dipinjam\n");
        printf("5. Keluar\n");
        garis();
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
            totalalat();
            break;
            case 2:
            minjamalat(username);
            break;
            case 3:
            balikinalat(username);
