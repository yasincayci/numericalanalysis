//TERS MATRÝS HESABI
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	
	int i,j,k,row,column,iterasyon = 1;
	printf("Satir sayisini giriniz: ");
	scanf("%d",&row);
	column = row; // kare matris için
	
	double **matris = (double**) malloc(sizeof(double*) * row);
	for(i = 0; i < column; i++){
		matris[i] = (double*) malloc(sizeof(double) * column * 2);
	}
	
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d. elemani giriniz:",iterasyon);
			scanf("%lf",&matris[i][j]);
			iterasyon++;
		}
 	}
 	
	// matrisin yanýna birim matrisi ekleme;
	for(i = 0; i < row; i++){
		for(j = 0; j < 2*column; j++){
			if(j >= column)
				matris[i][j] = 0;
			if(j - column == i)
				matris[i][j] = 1;
		}
	}
	
	//girilen matrisi ekrana bastýrma
	printf("\nMatris: \n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");
	}
	
	//matrisin ilk deðeri 0 girilmesin diye;
	if(matris[0][0] == 0){
		printf("Ilk degeri 0 olmayan bir matris giriniz\n");
		return 1;
	}
		
	// üst üçgen matris haline getirme;	
	double oran;
	for(i = 0; i < row; i++){
		for(j = i+1; j < row; j++){
			oran = matris[j][i] / matris[i][i];
			for(k = 0; k < 2*row; k++){	
				matris[j][k] -= oran * matris[i][k];	
			}
 		}	
	}
		
	// köþegen elemanlarýný 1 yapýp satýrýný o orana göre yeniden düzenleme; 
	for(i = 0; i < row; i++){
		for(j = i+1; j < 2*row; j++){ // j nin i+1 den baþlamasýnýn sebebi matrisin üst üçgen haline gelmiþ olmasý, köþegenden önceki elemanlar 0
			if(matris[i][i] != 0)
			matris[i][j] = matris[i][j] / matris[i][i];
		}
		if(matris[i][i] != 0)	
		matris[i][i] /= matris[i][i];
	}
			
	// alt üçgen matris haline getirme;	
	for(i = row-1; i >= 0; i--){
		for(j = i-1; j >= 0; j--){
			oran = matris[j][i] / matris[i][i];
			for(k = 0; k < 2*row; k++){	
				matris[j][k] -= oran * matris[i][k];	
			}
 		}	
	}
		
	//ters matrisi ekrana bastýrma;	
	printf("\nTers matris: \n");	
	for(i = 0; i < row; i++){
		for(j = row; j < 2*row; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");	
	}
	return 0;
}
