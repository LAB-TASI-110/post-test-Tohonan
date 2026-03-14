#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char code[4];
  char name[20];
  int cost_per_kg;
  bool is_outside_island;
} CityInfo;

int main() {
  CityInfo cities[] = {
    {"MDN", "Medan", 8000, false},
    {"BLG", "Balige", 5000, false},
    {"JKT", "Jakarta", 12000, true},
    {"SBY", "Surabaya", 13000, true}
  };
  int num_cities = sizeof(cities) / sizeof(CityInfo);

  char city_code[4];
  float butet_weight;

  printf("Masukkan data pengiriman (Kota Tujuan Berat Butet):\n");
  printf("(Gunakan format 'KODE BERAT', akhiri dengan 'END 0')\n");

  while (true) {
    if (scanf("%3s %f", city_code, &butet_weight) != 2) {
      break; 
    }

    if (strcmp(city_code, "END") == 0) {
      break; 
    }

    int city_index = -1;
    for (int i = 0; i < num_cities; i++) {
      if (strcmp(cities[i].code, city_code) == 0) {
        city_index = i;
        break;
      }
    }

    if (city_index != -1) {
      float ucok_weight = (3.0 / 2.0) * butet_weight;
      float total_weight = butet_weight + ucok_weight;
      long total_cost = (long)(total_weight * cities[city_index].cost_per_kg);

      char *promo_info = "";
      bool gets_discount = total_weight > 10;
      bool gets_insurance = cities[city_index].is_outside_island;

      if (gets_discount && gets_insurance) {
        promo_info = "Diskon 10% & Asuransi Gratis";
        total_cost = (long)(total_cost * 0.9);
      } else if (gets_discount) {
        promo_info = "Diskon 10%";
        total_cost = (long)(total_cost * 0.9);
      } else if (gets_insurance) {
        promo_info = "Asuransi Gratis";
      }

      printf("\n--- Detail Pengiriman ---\n");
      printf("Kota Tujuan: %s (%s)\n", cities[city_index].name, cities[city_index].code);
      printf("Berat Paket Butet: %.2f kg\n", butet_weight);
      printf("Berat Paket Ucok: %.2f kg\n", ucok_weight);
      printf("Total Berat: %.2f kg\n", total_weight);
      printf("Total Ongkos Kirim: Rp %ld\n", total_cost);
      if (strlen(promo_info) > 0) {
        printf("Promo Diperoleh: %s\n", promo_info);
      } else {
        printf("Promo Diperoleh: -\n");
      }
      printf("--------------------------\n");

    } else {
      printf("Kode kota tidak valid.\n");
    }
  }

  return 0;
}