// REGULA FALSI METHOD
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

int main(){
	
	int x,max_us,i,iterasyon = 1;
	double a,b,x1,hata = DBL_MAX;
	
	printf("En buyuk ussu giriniz: ");
	scanf("%d",&max_us);
	
	// üsler ve katsayýlarý dizide tutma;
	float *katsayi = (float*) malloc(sizeof(float) * (max_us + 1));
	int *usler = (int*) malloc(sizeof(int) * (max_us + 1));
	int j = max_us;
	for(i = 0; i < max_us; i++){
		usler[i] = j;
		j--;
	}
	
	int n = max_us+1;
	//katsayýlarýn kullanýcýdan alýnmasý
	for(i = 0; i < n; i++){
		printf("%d. ussun katsayisi: ",max_us);
		max_us--;
		scanf("%f",&katsayi[i]);
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
	// aralýk deðerleri çarpýmýnýn negatif olmamasýnýn kontrolü
	if(f(a)*f(b) > 0){
		printf("Verilen degerlerde kok olup olmadigi kesin degil\n");
		return 1;
	}
	
	// regula falsi metodu
	while(hata > e){
		hata = (a - b) / pow(2,iterasyon);
		if(hata < 0)
			hata = hata * (-1);
		printf("%d. iterasyondaki hata degeri: %lf, a = %lf, b = %lf, f(%lf) = %lf, f(%lf) = %lf\n",iterasyon,hata,a,b,a,f(a),b,f(b));
		x1 = (a*f(b) - b*f(a)) / (f(b) - f(a)); //yeni kökü belirlemek için
		if(f(a)*f(x1) <= 0)
			b = x1;
		else if(f(b)*f(x1) <= 0)
			a = x1;
		if(f(x1) == hata)
			hata = e;
		iterasyon++;
		printf("  x1 : %lf, f(%lf) : %lf\n",x1,x1,f(x1));
	}
	printf("kok = x1");
	printf("\n%d. iterasyonda sonuca ulasildi, kok = %lf",iterasyon-1,x1);
	return 0;
}
