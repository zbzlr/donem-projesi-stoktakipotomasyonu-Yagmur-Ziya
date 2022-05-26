#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define menuYazdir printf("1 . Urun Kayit Islemi\n2 . Urun Listeleme Islemi\n3 . Tedarikci Bilgisi Sorgulama Islemi\n4 . Urun Bilgisi Sorgulama Islemi\n5 . Menuden Cikis\nGerceklestirmek istediginiz islemi seciniz.\n\n");

struct urunBilgi {
    char kategori[20];
    char ad[15];
    int kod;
    int fiyat;
    int stokMiktar;
    int tedNo;
    char tarih[12];

} urunler[15] ;

struct tedBilgi {
    int tedNo;
    char tedAd[60];
    char adres[50];
    char sehir[15];
} tedarik[5] ;

void UrunKayit(FILE *pdosya, int kaydedilecekIndex){

        printf("Urun Kategorisi Giriniz: \n");
        scanf("%s", urunler[kaydedilecekIndex].kategori);
        printf("Urun Adi Giriniz: \n");
        scanf("%s", urunler[kaydedilecekIndex].ad);
        printf("Urun Kodu Giriniz: \n");
        scanf("%d", &urunler[kaydedilecekIndex].kod);
        printf("Urun Fiyatini Giriniz: \n");
        scanf("%d", &urunler[kaydedilecekIndex].fiyat);
        printf("Urunun Stok Miktarini Giriniz: \n");
        scanf("%d", &urunler[kaydedilecekIndex].stokMiktar);
        printf("Tedarikci No Giriniz: \n");
        scanf("%d",&urunler[kaydedilecekIndex].tedNo);
        printf("Lutfen Tarihi(gg.aa.yyyy) Giriniz: \n");
        scanf("%s",urunler[kaydedilecekIndex].tarih);
        printf("\n\n");

            pdosya = fopen("urunbilgi.txt","a+");
            fprintf(pdosya , "%s %s %d %d %d %d %s", urunler[kaydedilecekIndex].kategori, urunler[kaydedilecekIndex].ad, urunler[kaydedilecekIndex].kod, urunler[kaydedilecekIndex].fiyat, urunler[kaydedilecekIndex].stokMiktar,urunler[kaydedilecekIndex].tedNo,urunler[kaydedilecekIndex].tarih);
            fclose(pdosya);
            kaydedilecekIndex++;

        printf("Urun Basariyla Kaydedildi...\n\n");

        menuYazdir;
}

void UrunListe() {
    int k = 0;

    while (urunler[k].fiyat != 0) {
        printf("Urun Adi---> %s\nUrun Kodu--->%d\n\n\n", urunler[k].ad, urunler[k].kod);
        k++;
    }
        menuYazdir;
}

void tedarikciListele(FILE *pdosya){

    char isim[20],soyisim[20];
    int i=0,k=0;

    pdosya = fopen("tedBilgi.txt","r+");
            if(pdosya==NULL){printf("\nSistemde Kayitli Tedarikci Bulunamadi\n");
            }
            else {
                while (feof(pdosya) == 0) {
                    fscanf(pdosya, "%d %s %s %s %s\n", &tedarik[i].tedNo, isim, soyisim, tedarik[i].adres, tedarik[i].sehir);
                    strcat(isim, soyisim);
                    strcpy(tedarik[i].tedAd, isim);
                    i++;
                }
    fclose(pdosya);

                for(;k<i;k++){
                    printf("**%d.Tedarikci**\n",k+1);
                    printf("Tedarikci Adi:%s\n",tedarik[k].tedAd);
                    printf("Tedarikci No:%d\n",tedarik[k].tedNo);
                    printf("Tedarikci Sehir ve Adres:%s %s\n\n",tedarik[k].sehir,tedarik[k].adres);
                }
            }
        menuYazdir;
}

void urunBilgisiSorgula(){
    int urunKodu,i;

        printf("Sorgulamak Istediginiz Urunun Kodunu Giriniz:");
        scanf("%d",&urunKodu);

        for(i=0;i<10;i++){
            if (urunler[i].kod == urunKodu) {
                printf("\n\nUrun Adi: %s\nUrun Kategorisi: %s\nUrun Fiyati: %d\nStokta Bulunan Urun Sayisi: %d\nTedarikci No: %d \nStok Giris Tarihi: %s\n\n\n",
                       urunler[i].ad, urunler[i].kategori, urunler[i].fiyat, urunler[i].stokMiktar,urunler[i].tedNo,urunler[i].tarih);
                break;
            }
        }
        if(urunler[i].kod!=urunKodu) printf("Urun Bulunamadi...\n\n");
        menuYazdir;
}

void main(){
    FILE *purunbilgi;
    FILE *ptedbilgi;
    char islem;
    int j=0;

        printf("Firmamizin Stok Takip Otomasyonuna Hosgeldiniz...\n\nBaslamak Icin Herhangi Bir Tusa Basin...\n\n\n");
        getch();

            purunbilgi = fopen("urunbilgi.txt", "r+");
            if(purunbilgi==NULL){
                printf("urunbilgi.txt dosyasi acilmadi!\n");
                exit(1);
            }

        while (feof(purunbilgi)==NULL){
            fscanf(purunbilgi,"%s %s %d %d %d %d %s", urunler[j].kategori, urunler[j].ad, &urunler[j].kod, &urunler[j].fiyat, &urunler[j].stokMiktar,&urunler[j].tedNo,urunler[j].tarih);
            j++;
        }
        fclose(purunbilgi);
        j--;

        menuYazdir;

            do {
                islem = getch();

                    if (islem == '1') UrunKayit(purunbilgi, j);
                    if (islem == '2') UrunListe();
                    if (islem == '3') tedarikciListele(ptedbilgi);
                    if (islem == '4') urunBilgisiSorgula();
                }while (islem != '5');

        printf("Sistemden Cikis Yapildi...");
        getch();

}