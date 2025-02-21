#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// G�nl�k kayd� yap�s�
typedef struct GunlukKaydi {
    char mesaj[256]; // G�nl�k mesaj�
    struct GunlukKaydi* sonraki; // Sonraki eleman� i�aret eden g�sterici
} GunlukKaydi;

// Yeni g�nl�k giri�i olu�turma fonksiyonu
GunlukKaydi* yeniGunlukKaydiOlustur(const char* mesaj) {
    GunlukKaydi* yeniKayit = (GunlukKaydi*)malloc(sizeof(GunlukKaydi));
    if (yeniKayit != NULL) {
        strncpy(yeniKayit->mesaj, mesaj, sizeof(yeniKayit->mesaj));
        yeniKayit->sonraki = NULL;
    }
    return yeniKayit;
}

// G�nl�k giri�ini ba�l� listeye ekleme fonksiyonu
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

// G�nl�k giri�lerini yazd�rma fonksiyonu
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

    // �rnek g�nl�k giri�leri ekleyelim
    gunlukKaydiEkle(&gunlukListesi, "2025-02-21 10:00:00: Sistem ba�lat�ld�.");
    gunlukKaydiEkle(&gunlukListesi, "2025-02-21 10:05:00: Kullan�c� giri� yapt�.");
    gunlukKaydiEkle(&gunlukListesi, "2025-02-21 10:10:00: Hata: Disk dolu.");

    // G�nl�k giri�lerini yazd�r
    gunlukKayitlariniYazdir(gunlukListesi);

    // Belle�i temizleme (gerekirse)
    GunlukKaydi* mevcut = gunlukListesi;
    while (mevcut != NULL) {
        GunlukKaydi* sonraki = mevcut->sonraki;
        free(mevcut);
        mevcut = sonraki;
    }

    return 0;
}
