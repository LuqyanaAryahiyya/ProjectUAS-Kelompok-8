#include "file.h"

// Fungsi login membaca data dari file akun.txt
int login(const char *username, const char *password, char *role){
    FILE *file = fopen("akun.txt", "r");  // Buka file akun.txt dalam mode baca
    if(!file){
        printf("Gagal membuka file akun.txt!\n");
        return 0;
    }

    char line[150];
    int found = 0;

    // Baca file baris demi baris
    while(fgets(line, sizeof(line), file)){
        char fileUser[50], filePass[50], fileRole[10];  // Format file: username,password,role
        sscanf(line, "%[^,],%[^,],%s", fileUser, filePass, fileRole);

        // Bandingkan username dan password
        if(strcmp(fileUser, username) == 0 && strcmp(filePass, password) == 0){
            strcpy(role, fileRole);
            found = 1;
            break;
        }
    }

    fclose(file);  // Tutup file
    return found;  // Kembalikan hasil pencarian
}
