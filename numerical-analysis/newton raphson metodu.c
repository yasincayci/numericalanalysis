#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

int main(){
	
	int x,max_us,i,iterasyon = 1;
	double a,b,xn,x1,hata = DBL_MAX;
	int control;
	printf("En buyuk ussu giriniz: ");
	scanf("%d",&max_us);
	
	// üsler ve katsayýlarý dizide tutma;
	float *katsayi = (float*) malloc(sizeof(float) * (max_us + 1));
	float *katsayi2 = (float*) malloc(sizeof(float) * (max_us + 1));
	int *usler = (int*) malloc(sizeof(int) * (max_us + 1));
	int *usler2 = (int*) malloc(sizeof(int) * (max_us + 1));
	int j = max_us;
	for(i = 0; i < j; i++){
		usler[i] = max_us;
		usler2[i] = usler[i]-1;
		max_us--;
	}
	max_us = j;
	int n = max_us+1;
	//katsayýlarýn kullanýcýdan alýnmasý
	for(i = 0; i < n; i++){
		printf("%d. ussun katsayisi: ",max_us);
		max_us--;
		scanf("%f",&katsayi[i]);
	}
	for(i = 0; i < n; i++){
		katsayi2[i] = katsayi[i];
	}	
	max_us = n-1;
	printf("f(x) = ");
	//f(x) in ekrana bastýrýlmasý
	for(i = 0; i < n; i++){
		if(katsayi[i] != 0){
			if(max_us != 0)
			printf("%.1f*x^%d + ",katsayi[i],max_us);
			else
			printf("%.1f",katsayi[i]);
		}
	max_us--;
	}
	printf(" = 0\n");

	// aralýk degerlerinin kullanýcýdan alýnmasý
	printf("Araliklari giriniz: ");
	scanf("%lf %lf",&a,&b);
	printf("Aralik: [%lf,%lf]\n",a,b);
	
	// hata payýnýn kullanýcýdan alýnmasý
	double e;
	printf("Hata payini giriniz: ");
	scanf("%lf",&e);
	
	// f fonksiyonunun tanýmlanmasý
	double f(double x){
		double p = 0;
		for(i = 0; i < n-1; i++){
			p = p + katsayi[i]*pow(x,usler[i]);
		}
			p += katsayi[n-1];
			return p;
	}
	
	//turev alma fonksiyonu
	double turev(double x){
		double m = 0;
		for(i = 0; i < n-1; i++){
			katsayi2[i] = katsayi2[i] * (usler2[i] + 1);
			usler2[i] = 0; // türev fonk cagirildiginda katsayinin degismemesi icin
		}
		katsayi2[n-1] = 0;
		for(i = 0; i < n-1; i++){
			m = m + katsayi2[i]*pow(x,usler[i]-1);
		}
		return m;
	}
/*	// aralýk deðerleri çarpýmýnýn negatif olmamasýnýn kontrolü
	if(f(a)*f(b) > 0){
		printf("Verilen degerlerde xn olup olmadigi kesin degil\n");
		return 1;
	}
	*/
	//baslangýç deðerini belirleme(x0)
	printf("Baslangic kokunu girmek istiyorsaniz 9 girin: ");
	scanf("%d",&control);
	if(control == 9){
		printf("Baslangic koku: ");
		scanf("%lf",&xn);
	}
	else{
		if(a < b) //kökü kullanýcý vermezse aralýklardaki küçük olan deðerden baþla
		xn = a;
		else
		xn = b;
	}
	// newton raphson metodu
	while(hata > e){
		x1 = xn - (f(xn) / turev(xn)); //yeni kökü belirlemek için
		hata = (x1 - xn);
		if(hata < 0)
			hata = hata * (-1);
		printf("\n%d. iterasyondaki hata degeri: %lf \n  x1 : %lf\n xn : %lf\n",iterasyon,hata,x1,xn);
		xn = x1;
		/*if(f(x1) == hata)
			hata = e;*/
		iterasyon++;
	}
	printf("xn = x1");
	printf("\n%d. iterasyonda sonuca ulasildi, xn = %lf ,f(xn) = %lf",iterasyon-1,x1,f(xn));
	return 0;
}
