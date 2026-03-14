#include <stdio.h>
#include <string.h>

struct Menu {
    int id;
    char nama[50];
    int harga;
};

int main() {
    struct Menu daftarMenu[5] = {
        {1, "Nasi Ayam IT Del", 15000},
        {2, "Mie Goreng Kantin", 12000},
        {3, "Es Teh Manis", 5000},
        {4, "Kopi Signature", 8000},
        {5, "Gorengan", 2000}
    };

    int pilihan, jumlah, total = 0, metode;
    char lanjut;

    printf("=== SISTEM KASIR DIGITAL KAFETARIA IT DEL ===\n");
    
    do {
        printf("\nDaftar Menu:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s - Rp %d\n", daftarMenu[i].id, daftarMenu[i].nama, daftarMenu[i].harga);
        }

        printf("\nMasukkan ID Menu yang dipesan: ");
        scanf("%d", &pilihan);
        
        if (pilihan >= 1 && pilihan <= 5) {
            printf("Masukkan Jumlah: ");
            scanf("%d", &jumlah);
            total += daftarMenu[pilihan - 1].harga * jumlah;
        } else {
            printf("ID Menu tidak valid!\n");
        }

        printf("Tambah pesanan lagi? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    printf("\nTotal Transaksi: Rp %d\n", total);
    printf("Pilih Metode Pembayaran:\n");
    printf("1. Cashless (QRIS/Kartu)\n");
    printf("2. Tunai (Cash)\n");
    printf("Pilihan: ");
    scanf("%d", &metode);

    printf("\n==========================================\n");
    printf("TRANSAKSI BERHASIL\n");
    printf("Total Bayar: Rp %d\n", total);
    printf("Metode: %s\n", (metode == 1) ? "Cashless (QRIS/Kartu)" : "Tunai");
    printf("Pesanan diteruskan ke Dapur Kafetaria...\n");
    printf("==========================================\n");

    return 0;
}