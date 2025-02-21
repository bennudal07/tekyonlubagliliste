#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// günlük kaydın yapısı
typedef struct GunlukKaydi {
    char mesaj[500];
    struct GunlukKaydi* sonraki;
} GunlukKaydi;

// yeni günlük giriş oluşturma
GunlukKaydi* yeniKayit(const char* mesaj) {
    GunlukKaydi* kayit = malloc(sizeof(GunlukKaydi));
    if (kayit) {
        strncpy(kayit->mesaj, mesaj, sizeof(kayit->mesaj));
        kayit->sonraki = NULL;
    }
    return kayit;
}

// Günlük girişini ekleme
void ekle(GunlukKaydi** bas, const char* mesaj) {
    GunlukKaydi* kayit = yeniKayit(mesaj);
    if (*bas == NULL) {
        *bas = kayit;
    } else {
        GunlukKaydi* mevcut = *bas;
        while (mevcut->sonraki) {
            mevcut = mevcut->sonraki;
        }
        mevcut->sonraki = kayit;
    }
}

// günlük girişleri yazdırma
void yazdir(GunlukKaydi* bas) {
    GunlukKaydi* mevcut = bas;
    while (mevcut) {
        printf("%s\n", mevcut->mesaj);
        mevcut = mevcut->sonraki;
    }
}


int main() {
    GunlukKaydi* gunlukListesi = NULL;

    ekle(&gunlukListesi, "2025-02-21 10:00:00: Sistem başlatıldı.");
    ekle(&gunlukListesi, "2025-02-21 10:05:00: Kullanıcı giriş yaptı.");
    ekle(&gunlukListesi, "2025-02-21 10:10:00: Hata: Disk dolu.");

    yazdir(gunlukListesi);

    // bellek temizleme
    while (gunlukListesi) {
        GunlukKaydi* sonraki = gunlukListesi->sonraki;
        free(gunlukListesi);
        gunlukListesi = sonraki;
    }

    return 0;
}
