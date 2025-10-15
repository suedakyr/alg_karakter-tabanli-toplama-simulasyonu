#include <stdio.h>
#include <ctype.h> //isdigit() icin

// Giriş tamponunda fazladan karakter olup olmadığını kontrol eden ve tamponu temizleyen fonksiyon.
// Eğer '\n' öncesinde başka karakter varsa 1 (true), yoksa 0 (false) döner.
    int tamponu_temizle_ve_fazlaligi_kontrol_et() {
    int sonraki_karakter;
    int fazla_girdi_var = 0;

    // Tampondaki ilk karaktere bak
    sonraki_karakter = getchar();

    // Eğer bu karakter yeni satır veya dosya sonu değilse, kullanıcı fazla girdi yapmıştır.
    if (sonraki_karakter != '\n' && sonraki_karakter != EOF) {
        fazla_girdi_var = 1; // Fazla girdi olduğunu işaretle
    }

    // Tamponda yeni satır veya dosya sonuna kadar ne varsa tüketerek temizle
    while (sonraki_karakter != '\n' && sonraki_karakter != EOF) {
        sonraki_karakter = getchar();
    }

    return fazla_girdi_var;
}

// C ile karakter tabanlı toplama simülasyonu
int main() {
    char karakter1, karakter2;
    int sayi1, sayi2, toplam;

    // ---------------------------------------------
    // --- BİRİNCİ GİRDİ İŞLEMİ VE KONTROLLERİ ---
    // ---------------------------------------------
    printf("Lutfen TEK HANELI rakami girin (ornegin '3'): ");

    // NOT: scanf'teki " %c" formatı, baştaki boşlukları (whitespace) atlar.
    // Bu, önceki girdilerden kalabilecek '\n' gibi karakterlerin okunmasını engeller.
    if (scanf("%c", &karakter1) != 1) {
        // Okuma başarısız olursa (örn: Ctrl+D ile EOF gönderilirse)
        return 1;
    }

    // A. Tek Karakter Kısıtlaması Kontrolü
    if (tamponu_temizle_ve_fazlaligi_kontrol_et()) {
        printf("\nUYARI: Birinci girdide YALNIZCA tek bir karakter bekleniyordu.\n");
        printf("Lutfen simule edilen sistemin kisitlamalarina uyun.\n");
        return 1;
    }

    // B. Rakam Karakteri Kontrolü ('A', '#' kontrolü)
    if (!isdigit(karakter1)) {
        printf("\nUYARI:YALNIZCA '0' ile '9' arasindaki bir rakam olmalidir.\n");
        return 1;
    }


    // ---------------------------------------------
    // --- İKİNCİ GİRDİ İŞLEMİ VE KONTROLLERİ ---
    // ---------------------------------------------
    printf("Lutfen ikinci TEK HANELI rakami girin (ornegin '5'): ");
    if (scanf(" %c", &karakter2) != 1) {
        return 1;
    }

    // C. Tek Karakter Kısıtlaması Kontrolü
    if (tamponu_temizle_ve_fazlaligi_kontrol_et()) {
        printf("\nUYARI: Ikinci girdide YALNIZCA tek bir karakter bekleniyordu.\n");
        printf("Lutfen simule edilen sistemin kisitlamalarina uyun.\n");
        return 1;
    }

    // D. Rakam Karakteri Kontrolü ('A', '#' kontrolü)
    if (!isdigit(karakter2)) {
        printf("\nUYARI: Ikinci girdi YALNIZCA '0' ile '9' arasindaki bir rakam karakteri olmalidir.\n");
        return 1;
    }

    // ---------------------------------------------
    // --- İŞLEM ADIMLARI (Tüm Kontroller Başarılı) ---
    // ---------------------------------------------

    // 1. Dönüşüm ve Toplama (Bu kısım C++ ile tamamen aynı)
    sayi1 = karakter1 - '0';
    sayi2 = karakter2 - '0';
    toplam = sayi1 + sayi2;

    // 2. Tek Haneli Kalma Kontrolü (Toplama > 9)
    if (toplam > 9) {
        printf("\nHATA: Toplam (%d), tek haneli rakam sinirini (9) asti.\n", toplam);
        printf("Simulasyon geregi, iki tek haneli rakam toplami 9'u gecemez.\n");
        return 1;
    }

    // 3. Sonucu Karaktere Çevirme ve Çıktı
    char sonuc_karakter = toplam + '0';

    printf("\n--- Simulasyon Sonucu ---\n");
    printf("Girdi Karakterleri: '%c' + '%c'\n", karakter1, karakter2);
    printf("Sonuc Karakteri:    '%c'\n", sonuc_karakter);

    return 0;
}
