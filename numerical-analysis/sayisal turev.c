#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int max_us,i;
	printf("En buyuk ussu giriniz: ");
	scanf("%d",&max_us);
	
	// �sler ve katsay�lar� dizide tutma;
	float *katsayi = (float*) malloc(sizeof(float) * (max_us + 1));
	int *usler = (int*) malloc(sizeof(int) * (max_us + 1));
	int j = max_us;
	for(i = 0; i < j; i++){
		usler[i] = max_us;
		max_us--;
	}
	max_us = j;
	
	int n = max_us+1;
	//katsay�lar�n kullan�c�dan al�nmas�
	for(i = 0; i < n; i++){
		printf("%d. ussun katsayisi: ",max_us);
		max_us--;
		scanf("%f",&katsayi[i]);
	}	
	max_us = n-1;
	printf("f(x) = ");
	
	//f(x) in ekrana bast�r�lmas�
	for(i = 0; i < n; i++){
		if(katsayi[i] != 0){
			if(max_us != 0)
			printf("%.1f*x^%d + ",katsayi[i],max_us);
			else
			printf("%.1f",katsayi[i]);
		}
	max_us--;
	}
	printf("\n");

	// f fonksiyonunun tan�mlanmas�
	double f(double x){
		double p = 0;
		for(i = 0; i < n-1; i++){
			p = p + katsayi[i]*pow(x,usler[i]);
		}
			p += katsayi[n-1];
			return p;
	}
	
	//h �n ve x in kullan�c�dan al�nmas�
	double h,x;
	printf("h:");
	scanf("%lf",&h);
	printf("x:");
	scanf("%lf",&x);
	
	//Geri farklar ile t�rev
	double gturev =  (f(x) - f(x-h)) / h;
	printf("\nGeri fark ile turev: %lf\n",gturev);
	
	//�leri farklar ile t�rev
	double iturev =  (f(x+h) - f(x)) / h;
	printf("\nIleri fark ile turev: %lf\n",iturev);
	
	//Merkezi farklar ile t�rev
	double mturev =  (f(x+h) - f(x-h)) / (2*h);
	printf("\nMerkezi fark ile turev: %lf\n",mturev);

	return 0;
}
