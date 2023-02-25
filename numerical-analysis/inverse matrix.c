//TERS MATR�S HESABI
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	
	int i,j,k,row,column,iterasyon = 1;
	printf("Satir sayisini giriniz: ");
	scanf("%d",&row);
	column = row; // kare matris i�in
	
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
 	
	// matrisin yan�na birim matrisi ekleme;
	for(i = 0; i < row; i++){
		for(j = 0; j < 2*column; j++){
			if(j >= column)
				matris[i][j] = 0;
			if(j - column == i)
				matris[i][j] = 1;
		}
	}
	
	//girilen matrisi ekrana bast�rma
	printf("\nMatris: \n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");
	}
	
	//matrisin ilk de�eri 0 girilmesin diye;
	if(matris[0][0] == 0){
		printf("Ilk degeri 0 olmayan bir matris giriniz\n");
		return 1;
	}
		
	// �st ��gen matris haline getirme;	
	double oran;
	for(i = 0; i < row; i++){
		for(j = i+1; j < row; j++){
			oran = matris[j][i] / matris[i][i];
			for(k = 0; k < 2*row; k++){	
				matris[j][k] -= oran * matris[i][k];	
			}
 		}	
	}
		
	// k��egen elemanlar�n� 1 yap�p sat�r�n� o orana g�re yeniden d�zenleme; 
	for(i = 0; i < row; i++){
		for(j = i+1; j < 2*row; j++){ // j nin i+1 den ba�lamas�n�n sebebi matrisin �st ��gen haline gelmi� olmas�, k��egenden �nceki elemanlar 0
			if(matris[i][i] != 0)
			matris[i][j] = matris[i][j] / matris[i][i];
		}
		if(matris[i][i] != 0)	
		matris[i][i] /= matris[i][i];
	}
			
	// alt ��gen matris haline getirme;	
	for(i = row-1; i >= 0; i--){
		for(j = i-1; j >= 0; j--){
			oran = matris[j][i] / matris[i][i];
			for(k = 0; k < 2*row; k++){	
				matris[j][k] -= oran * matris[i][k];	
			}
 		}	
	}
		
	//ters matrisi ekrana bast�rma;	
	printf("\nTers matris: \n");	
	for(i = 0; i < row; i++){
		for(j = row; j < 2*row; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");	
	}
	return 0;
}
