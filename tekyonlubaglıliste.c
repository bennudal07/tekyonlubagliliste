#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Günlük kaydı için yapı tanımı (Linked List Node)
typedef struct GunlukKaydi {
    char mesaj[500]; // Günlük mesajı (en fazla 500 karakter)
    struct GunlukKaydi* sonraki; // Bir sonraki kaydın adresi
} GunlukKaydi;

// Yeni bir günlük kaydı oluşturur ve döndürür
GunlukKaydi* yeniKayit(const char* mesaj) {
    GunlukKaydi* kayit = (GunlukKaydi*)malloc(sizeof(GunlukKaydi)); // Bellekten yer ayır
    if (kayit) { // Bellek başarıyla ayrıldı mı kontrol et
        strncpy(kayit->mesaj, mesaj, sizeof(kayit->mesaj) - 1); // Mesajı kopyala
        kayit->mesaj[sizeof(kayit->mesaj) - 1] = '\0'; // Güvenlik için sonuna null karakter ekle
        kayit->sonraki = NULL; // Yeni kaydın sonraki işaretçisini NULL yap
    }
    return kayit; // Yeni kaydı döndür
}

// Günlük girişini listeye ekler
void ekle(GunlukKaydi** bas, const char* mesaj) {
    GunlukKaydi* kayit = yeniKayit(mesaj); // Yeni kayıt oluştur
    if (!kayit) { // Bellek ayrıldı mı kontrol et
        printf("Bellek tahsis hatası!\n");
        return;
    }

    if (*bas == NULL) { // Eğer liste boşsa
        *bas = kayit; // Yeni kayıt baş olarak atanır
    } else {
        GunlukKaydi* mevcut = *bas;
        while (mevcut->sonraki) { // Listenin sonuna kadar ilerle
            mevcut = mevcut->sonraki;
        }
        mevcut->sonraki = kayit; // Yeni kaydı sona ekle
    }
}

// Günlük girişlerini ekrana yazdırır
void yazdir(GunlukKaydi* bas) {
    GunlukKaydi* mevcut = bas;
    while (mevcut) {
        printf("%s\n", mevcut->mesaj); // Günlük mesajını yazdır
        mevcut = mevcut->sonraki; // Sonraki kayda geç
    }
}

// Programın ana fonksiyonu
int main() {
    GunlukKaydi* gunlukListesi = NULL; // Boş bir günlük listesi başlat

    // Örnek günlük girişleri ekle
    ekle(&gunlukListesi, "2025-02-21 10:00:00: Sistem başlatıldı.");
    ekle(&gunlukListesi, "2025-02-21 10:05:00: Kullanıcı giriş yaptı.");
    ekle(&gunlukListesi, "2025-02-21 10:10:00: Hata: Disk dolu.");

    // Günlük kayıtlarını ekrana yazdır
    yazdir(gunlukListesi);

    // Bellek temizleme (Linked List'in tamamını serbest bırak)
    while (gunlukListesi) {
        GunlukKaydi* sonraki = gunlukListesi->sonraki; // Sonraki kaydı sakla
        free(gunlukListesi); // Mevcut kaydı serbest bırak
        gunlukListesi = sonraki; // Listenin başını güncelle
    }

    return 0; // Program başarıyla tamamlandı
}
