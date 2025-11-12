#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *input, *output;
    char kata[100], baris[200], kosaKata[1000][100];
    int n = 0, cari;

    input = fopen("lirik.txt", "r");        //Membuka file lirik.txt
    output = fopen("kosa-kata.txt", "w");   //Membuka file kosa-kata.txt
    
    if (input == NULL|| output == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    fgets(baris, sizeof(baris), input);     //Membaca judul
    fprintf(output, "%s", baris);  

    while (fgets(baris, sizeof(baris), input)) {
        int i = 0, j = 0;

        while (baris[i] != '\0') {
            char c = tolower(baris[i]);
            if ((c >= 'a' && c <= 'z') || c == '\'') {      //Menyimpan huruf dan tanda '
                kata[j] = c;
                j++;
            } 
            else if (j > 0) {
                kata[j] = '\0';
                cari = 0;

                for (int k = 0; k < n; k++) {               //Mengecek kata yang sudah pernah muncul
                    if (strcmp(kosaKata[k], kata) == 0) {
                        cari = 1;
                        break;
                    }
                }
                if (cari == 0) {
                    strcpy(kosaKata[n], kata);
                    n++;
                }
                j = 0;
            }
            i++;
        }
    }

    for (int i = 0; i < n; i++) {               //Menulis daftar kata ke file output
        fprintf(output, "%s=\n", kosaKata[i]);
    }

    fclose(input);          //Menutup file lirik.txt
    fclose(output);         //Menutup file kosa-kata.txt
    printf("Program berhasil, silahkan cek file kosa-kata.txt\n");
    return 0;
}
