#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Günlük kaydý yapýsý
typedef struct GunlukKaydi {
    char mesaj[256]; // Günlük mesajý
    struct GunlukKaydi* sonraki; // Sonraki elemaný iþaret eden gösterici
} GunlukKaydi;

// Yeni günlük giriþi oluþturma fonksiyonu
GunlukKaydi* yeniGunlukKaydiOlustur(const char* mesaj) {
    GunlukKaydi* yeniKayit = (GunlukKaydi*)malloc(sizeof(GunlukKaydi));
    if (yeniKayit != NULL) {
        strncpy(yeniKayit->mesaj, mesaj, sizeof(yeniKayit->mesaj));
        yeniKayit->sonraki = NULL;
    }
    return yeniKayit;
}

// Günlük giriþini baðlý listeye ekleme fonksiyonu
void gunlukKaydiEkle(GunlukKaydi** bas, const char* mesaj) {
    GunlukKaydi* yeniKayit = yeniGunlukKaydiOlustur(mesaj);
    if (*bas == NULL) {
        *bas = yeniKayit;
    } else {
        GunlukKaydi* mevcut = *bas;
        while (mevcut->sonraki != NULL) {
            mevcut = mevcut->sonraki;
        }
        mevcut->sonraki = yeniKayit;
    }
}

// Günlük giriþlerini yazdýrma fonksiyonu
void gunlukKayitlariniYazdir(GunlukKaydi* bas) {
    GunlukKaydi* mevcut = bas;
    while (mevcut != NULL) {
        printf("%s\n", mevcut->mesaj);
        mevcut = mevcut->sonraki;
    }
}

// Ana fonksiyon
int main() {
    GunlukKaydi* gunlukListesi = NULL;

    // Örnek günlük giriþleri ekleyelim
    gunlukKaydiEkle(&gunlukListesi, "2025-02-21 10:00:00: Sistem baþlatýldý.");
    gunlukKaydiEkle(&gunlukListesi, "2025-02-21 10:05:00: Kullanýcý giriþ yaptý.");
    gunlukKaydiEkle(&gunlukListesi, "2025-02-21 10:10:00: Hata: Disk dolu.");

    // Günlük giriþlerini yazdýr
    gunlukKayitlariniYazdir(gunlukListesi);

    // Belleði temizleme (gerekirse)
    GunlukKaydi* mevcut = gunlukListesi;
    while (mevcut != NULL) {
        GunlukKaydi* sonraki = mevcut->sonraki;
        free(mevcut);
        mevcut = sonraki;
    }

    return 0;
}
