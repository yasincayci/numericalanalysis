#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	
	int i,j,n,counter = 0;
	printf("Girilecek degisken sayisini giriniz:");
	scanf("%d",&n);
	double *kok = (double*) malloc(sizeof(double) * n);
	double *deger = (double*) malloc(sizeof(double) * n);
	double *delta = (double*) malloc(sizeof(double) * (n-1));
	double *delta0 = (double*) malloc(sizeof(double) * (n-1));
	for(i = 0; i < n; i++){
		printf("%d. kok:",i+1);
		scanf("%lf",&kok[i]);
		printf("f(%lf):",kok[i]);
		scanf("%lf",&deger[i]);
	}
	
	for(i = 1; i < n; i++){
		delta[i-1] = deger[i] - deger[i-1];
	}
	
	i = 1;
	j = 1;
	delta0[0] = delta[0];	
	while(counter < n-2){
		counter = 0;
		while(i < n-1){
			delta[i-1] = delta[i] - delta[i-1];
			i++;
		}
		delta0[j] = delta[0];
		j++;
		n--;
		for(i = 1; i < n; i++){
			if(delta[i-1] == delta[i])
				counter++;
		}
		i = 1;
	}	
	
	// h ý belirlemek için
	double *h = (double*) malloc(sizeof(double) * (j+1)); 
	h[0] = kok[1] - kok[0]; 
	for(i = 1; i < j+1; i++){
		h[i] = h[i-1] * h[0];
	}
	
	//fonksiyonun tanýmlanmasý
	double F(double x){
		int faktoriyel = 1;
		double sum = deger[0];
		double unknown = x - kok[0];
		for(i = 0; i < j; i++){
			faktoriyel = faktoriyel * (i+1);
			if(i != 0)
				unknown = unknown * (x - kok[i]);
			sum += unknown * delta0[i] / (faktoriyel * h[i]);
		}
		return sum;
	}
	
	double x;
	printf("\nHesaplanmasini istediginiz deger:");
	scanf("%lf",&x);
	printf("\nf(%lf): %lf\n",x,F(x));
	return 0;
}
