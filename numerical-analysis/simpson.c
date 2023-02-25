// SIMPSON 1/3 KURALI
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	double a,b,parca,h,sum;
	int max_us,i;
	printf("En buyuk ussu giriniz: ");
	scanf("%d",&max_us);
	
	// üsler ve katsayýlarý dizide tutma;
	double *katsayi = (double*) malloc(sizeof(double) * (max_us + 1));
	int *usler = (int*) malloc(sizeof(int) * (max_us + 1));
	int j = max_us;
	for(i = 0; i < j; i++){
		usler[i] = max_us;
		max_us--;
	}
	max_us = j;
	
	int n = max_us+1;
	//katsayýlarýn kullanýcýdan alýnmasý
	for(i = 0; i < n; i++){
		printf("%d. ussun katsayisi: ",max_us);
		max_us--;
		scanf("%lf",&katsayi[i]);
	}
	max_us = n-1;
	
	//f(x) in ekrana bastýrýlmasý
	printf("f(x) = ");
	for(i = 0; i < n; i++){
		if(katsayi[i] != 0){
			if(max_us != 0)
				printf("%.1lf*x^%d + ",katsayi[i],max_us);
			else
				printf("%.1lf",katsayi[i]);
			}
		max_us--;
		}
	printf("\n");
	
	// aralýk degerlerinin kullanýcýdan alýnmasý
	printf("Alt siniri giriniz: ");
	scanf("%lf",&a);
	printf("Ust siniri giriniz: ");
	scanf("%lf",&b);
	printf("Parca sayisini giriniz: ");
	scanf("%lf",&parca);
	h = (b-a) / parca;

	// f fonksiyonunun tanýmlanmasý
	double f(double x){
		double p = 0;
		for(i = 0; i < n-1; i++){
			p = p + katsayi[i]*pow(x,usler[i]);
		}
			p += katsayi[n-1];
			return p;
	}
	
	//Simpson 1/3 metodu
	sum = fabs(f(a)) + fabs(f(b));
	j = 1;
	while(j < parca){
		if(j % 2 == 0)
			sum += 2 * fabs(f(a + j*h));
		else
			sum += 4 * fabs(f(a + j*h));
		j++;
	}

	sum *= h / 3;
	printf("\nAlan: %lf",sum);
	return 0;
}
