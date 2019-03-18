#include <stdio.h>
#include <math.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>
#include "include/denklem.h"


//*TANIMLAR*
double deltax;
double x;
char secim;
double yval;
double eq;
double sonuc;
int ustlim;
int altlim;
int dsayisi;
char dosyaadi[25];
FILE *kayit;
FILE *denk;
FILE *denkx;
FILE *lisans;
//**********


void main()
{
	system("cls"); //konsolu temizle.
	int csayisi;
	for (csayisi = 0; csayisi<1889; csayisi++ ) //1846 karakter boyunca loop atar.
	{
	 printf("-");
     if (csayisi == 832){ //832. karaktere geldiğinde çalıştırır ve işlemler menüsünü yazar.
	 	printf("||-----ISLEMLER-----||");
	 }
	 if (csayisi == 890){
	 	printf("|| A-) INTEGRAL COZ ||"); //58 karakter sonra ilk secenegi yazdirir.
	 }
	 if (csayisi == 948){
	 	printf("|| B-) DOSYADAN COZ ||"); //2. seçenek
	 }
	 if (csayisi == 1006){
	 	printf("|| C-) CIKIS        ||"); //3. seçenek
	 }
	}	
	
	secim = getch(); //seçim belirle
	system("cls"); //konsolu temizle
	
	//menu buyuk ve kucuk harflere duyarlidir.
	switch(secim)
	{
	 case 'A': 
	 case 'a':  //integral fonksiyonuna yönlendirir.
		integralcoz();
	    
	 case 'B':
	 case 'b':
	 	metinparser();
	 	
	 case 'C': //cikis 
	 case 'c':
	 	exit(0);
	 	
	 default: //tanımlanmayan durumlarda yonlendirir.
	 	system("cls");
	 	printf("Giris Gecerli Degil.");
	 	Sleep(250); //1 saniye ara.
	 	system("cls");
	    main(); //main fonksiyonuna geri dondurur.
	}
}


void integralcoz()
{
	dsayisi = 0;
	ustlim = 0;
	altlim = 0;
	sonuc = 0;
	deltax = 0;
	x = 0;
	yval = 0;
	
	time_t t; //tarih yazdir
    time(&t);
	printf("Tarih: %s",ctime(&t));
	
    printf("Alt limit: "); //alt limit girisi
	scanf("%d",&altlim); 
	
	printf("Ust limit: "); //üst limit girisi
	scanf("%d",&ustlim);
	
	printf("Diktortgen sayisi: "); //kutu sayisi girisi
	scanf("%d",&dsayisi);
	
	cozucu(altlim,ustlim,dsayisi); //"cozucu" fonksiyonunu calistirir.
	
	main();//ana menuye gonderir.
}
	
void cozucu(int altlim, int ustlim, int dsayisi)
{
	if (altlim==ustlim) //programin sonsuz donguye girmesini engeller.
	{
		printf("\nAlt limit ve ust limit esit ise sonuc 0'dir.\n");
		Sleep(1000); //1sn bekler
		dsayisi = 0;//degisken sifirlama
	    ustlim = 0;
     	altlim = 0;
        main();
	}
	
	deltax = (floor(ustlim) - floor(altlim))/(floor(dsayisi)); //deltax i tanimlar ve üst limit ve alt limit degerlerinin isleme sokulabilmesi icin integerleri floor ile çevirir.
	
	int n; //dongu sayisini gosterir
	n = 0;
		
	for (x = floor(ustlim); x >= floor(altlim); x = x-deltax) //x değeri alt limite deltax çıkararak yaklaşır. 
	{
	  printf("\n");
	  printf("-----------------------\n");
	  
	  //TEST DIKDORTGENI
      if (n == 0){ 
       printf("* Bu diktortgen toplamda herhangi bir etkiye sahip degildir.\n");
       kayit = fopen("noktalar.txt", "a+"); //Kayit dosyasini "append" modunda acar.
	  }
	  
	  printf("Delta X: %f\n",deltax); //deltax çıktısı
	  printf("X: %f\n",x); //x değeri ciktisi
	  printf("Diktortgen Sayisi: %d\n",n); //diktortgen sayisi ciktisi
	  
	  //DIKDORTGEN OLUSTURMA
	  if (n !=0)
	  {
	   denklem(deltax,x);
	   yval = dnklem; //y degerini ceker.
	   fprintf(kayit, "%f %f\n", x,yval);  //dosyaya yazdirir.
	   printf("Sonuc: %.20f\n",sonuc);
	   
	   //if (n == dsayisi || n == dsayisi-1) //islem sona erdiginde sonucu yazdirir.
	   //{
	  	//printf("Sonuc: %.20f\n",sonuc);
	  	//fclose(kayit); //dosyayi kapat.
	   //}
	   
	  }	 
      n = n+1;
    }
    
    printf("\n-----------------------\n");
    printf("\nEND\n");
    
    time_t tend;//tarih yazdir
    time(&tend);
    printf("Tarih: %s",ctime(&tend));

    printf("Devam etmek icin bir karaktere basiniz.");
    getch(); //karakter bekle
    
    sonuc = 0;//degisken sifirla
    deltax = 0;
    ustlim = 0;
    altlim = 0;
    dsayisi = 0;
    x = 0;
    yval = 0;
}

void metinparser()
{
	printf("Dosya Adi Giriniz: ");
	scanf("%s",&dosyaadi[0]);
	printf("%s\n", dosyaadi);
	denk = fopen(dosyaadi,"r");
    char komutlar[10000][150],buffer[150]; //metinleri buffer ile okur.
    int i=0;
    while(fgets(buffer,150,denk)){
        strcpy(komutlar[i],buffer); //komutlar stringine atar
        if (strstr(komutlar[i], "<DENKLEM>") != NULL) { //eger stringin icinde "<DENKLEM>" bulunuyor ise.
        	char *dnk = strtok(komutlar[i], "<DENKLEM>");
        }
        
        if (strstr(komutlar[i], "<ALT_LIMIT>") != NULL) { //eger stringin icinde "<ALT_LIMIT>" bulunuyor ise.
        
        	char *al = strtok(komutlar[i], "<ALT_LIMIT>"); //"<ALT_LIMIT>" stringinden sonrasini char olarak atar
        	altlim = atoi (al); //"atoi" komutu ile string'i integer cinsine cevirir.
        }
    
        if (strstr(komutlar[i], "<UST_LIMIT>") != NULL) { //eger stringin icinde "<UST_LIMIT>" bulunuyor ise.
        	char *ul = strtok(komutlar[i], "<UST_LIMIT>"); //"<UST_LIMIT>" stringinden sonrasini char olarak atar
        	ustlim = atoi (ul); //"atoi" komutu ile string'i integer cinsine cevirir.
        }
        
        if (strstr(komutlar[i], "<D_SAYISI>") != NULL) { //eger stringin icinde "<D_SAYISI>" bulunuyor ise..
        	char *b = strtok(komutlar[i], "<D_SAYISI>"); //"<D_SAYISI>" stringinden sonrasini char olarak atar
        	dsayisi = atoi (b); //"atoi" komutu ile string'i integer cinsine cevirir.
        }
        
        if (strstr(komutlar[i], "<SON>") != NULL) { //eger stringin icinde "<SON>" bulunuyor ise.
        	cozucu(altlim,ustlim,dsayisi); //solver fonksiyonunu calistirir. 
        }
        i++;
    }
    printf("\n<SON>\n");
    
    getch();
    fclose(denk);
    system("cls");
    return 0;
}

