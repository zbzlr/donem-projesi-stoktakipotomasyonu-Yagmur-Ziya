#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


struct urunBilgi {
	char kategori[20];
	char ad[15];
	char kod[10];
	int fiyat;
	int stokMiktar;
} urun ;

struct tedBilgi {
	char tedNo[15];
	char tedAd[30];
	char adres[50];
	char sehir[15];
} tedarik ;

struct stokGirisiBilgi {
	char tedNo[15];
	char kod[10];
	int alisMiktar;
	int maliyet;
	struct {
		char gun;
		char ay;
		char yil;	
	} tarih;	
} stok ;

void UrunKayit(FILE *pdosya){
	pdosya=fopen("urunbilgi.txt", "a+");
		printf("Urun Kategorisi Giriniz: \n");
			scanf("%s", urun.kategori);
		printf("Urun Adi Giriniz: \n");
			scanf("%s", urun.ad);
		printf("Urun Kodu Giriniz: \n");
			scanf("%s", urun.kod);
		printf("Urun Fiyatini Giriniz: \n");
			scanf("%d", &urun.fiyat);
		printf("Urunun Stok Miktarini Giriniz: \n");
			scanf("%d", &urun.stokMiktar);
		printf("\n\n");
		fprintf(pdosya , "%s\n %s\n %s\n %d\n %d\n", urun.kategori, urun.ad, urun.kod, urun.fiyat, urun.stokMiktar);
	fclose(pdosya);
}
void UrunListe(FILE *pdosya){
	pdosya=fopen("urunbilgi.txt", "r");
	if(pdosya==NULL){
		printf("urunbilgi.txt dosyasi acilmadi!\n");
		exit(1);
	} 
	while (feof(pdosya)==0){
	
	fscanf(pdosya,"%s      %s       %s         %d       %d", urun.kategori, urun.ad, urun.kod, &urun.fiyat, &urun.stokMiktar);
	printf("Urun Kategorisi: %s\n", urun.kategori);
	printf("Urun Adi: %s\n", urun.ad);
	printf("Urun Kodu: %s\n", urun.kod);
	printf("Urun Fiyati: %d\n", urun.fiyat);
	printf("Urunun Stok Miktari: %d\n", urun.stokMiktar); 
	printf("\n\n");
	}	
fclose(pdosya);
}


void main(){
	FILE *pdosya;
	char islem;
	
	do{
		printf("1 . Urun Kayit Islemi\n");
		printf("2 . Urun Listeleme Islemi\n");
		printf("3 . Menuden Cikis\n");
		printf("Gerceklestirmek istediginiz islemi seciniz.\n");
		printf("\n");
		islem=getch();
		if(islem=='1') UrunKayit(pdosya);
		if(islem=='2') UrunListe(pdosya);
	}while(islem!='3');

	
	
	
}
