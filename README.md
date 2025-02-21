# Tek Yönlü Bağlı Liste Günlük Kayıt Uygulamasi

Bu proje, bağlı liste (linked list) kullanarak günlük (log) kayıtları tutan basit bir C programıdır. Kullanıcı, günlük girişleri ekleyebilir ve eklenen girişleri ekrana yazdırabilir.

### Özellikler

1.Yeni günlük kaydı ekleme: Kullanıcı, ekle() fonksiyonunu kullanarak yeni bir günlük girişi ekleyebilir.

2.Günlükleri yazdırma: yazdir() fonksiyonu ile eklenen günlük kayıtları terminalde görüntülenir.

3.Bellek yönetimi: Programın sonunda, dinamik olarak tahsis edilen bellek serbest bırakılır.

4.Bağlı Liste Yapısı: Kayıtlar, bağlı liste veri yapısı kullanılarak yönetilir.

### Gereksinimler

1.GCC veya başka bir C derleyicisi

2.Linux, macOS veya Windows işletim sistemi

3.Temel C programlama bilgisi

### Kullanım

1.Program çalıştırıldığında, önceden tanımlanmış günlük kayıtlarını ekler ve yazdırır.

2.Günlük kayıtları terminalde görüntülenir.

3.Program kapanırken bellek sızıntısını önlemek için tahsis edilen bellek serbest bırakılır.

### Fonksiyonlar

1. ### GunlukKaydi* yeniKayit(const char* mesaj);

Yeni bir günlük kaydı oluşturur ve bellek tahsisi yapar.

2. ### void ekle(GunlukKaydi** bas, const char* mesaj);

Bağlı listenin sonuna yeni bir günlük kaydı ekler.

3. ### void yazdir(GunlukKaydi* bas);

Tüm günlük kayıtlarını ekrana yazdırır.

4. ### int main();

Ana fonksiyon, birkaç örnek günlük kaydı ekleyerek programın çalışma mantığını gösterir.

