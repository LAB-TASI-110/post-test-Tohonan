#include <stdio.h>
#include <string.h>

int main() {
    int n, i, total_stok = 0;
    char kategori_cari[50];

    // Input jumlah data
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Input deret stok (diabaikan karena input berikutnya yang digunakan)
    for (i = 0; i < n; i++) {
        int temp;
        if (scanf("%d", &temp) != 1) {
            return 1;
        }
    }

    // Input kategori barang yang dicari
    if (scanf("%s", kategori_cari) != 1) {
        return 1;
    }

    // Input data barang (stok dan kategori) dan hitung total
    for (i = 0; i < n; i++) {
        int stok;
        char kategori_input[50];
        if (scanf("%d %s", &stok, kategori_input) != 2) {
            break; 
        }

        if (strcmp(kategori_input, kategori_cari) == 0) {
            total_stok += stok;
        }
    }

    // Output total stok
    printf("%d\n", total_stok);

    return 0;
}