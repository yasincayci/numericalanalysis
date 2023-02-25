//GAUSS ELEMÝNASYON METODU
#include <stdio.h>
#include <stdlib.h>

void swap(double *a, double *b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	
	int i,j,k,row,column,first,counter = 0,iterasyon = 1;
	
	printf("Satir sayisini giriniz: ");
	scanf("%d",&row);
	column = row; //bu yöntem kare matrislerde kullanýlýr
	
	double **matris = (double**) malloc(sizeof(double) * row);
	double *kok = (double*) malloc(sizeof(double) * row);
	for(i = 0; i < column; i++){
		matris[i] = (double*) malloc(sizeof(double) * (column+1));
	}
	
	//matrisin elemanlarýný almak için;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d. elemani giriniz: ",iterasyon);
			scanf("%lf",&matris[i][j]);
			iterasyon++;
		}
	}
	
	//sonuç matrisini girmek için;
	for(i = 0; i < row; i++){
		for(j = column; j < column+1; j++){
			printf("Sonuc matrisinde %d.elemani giriniz: ",i+1);
			scanf("%lf",&matris[i][j]);
		}
	}
	
	//matrisin ilk elemaný 0 ise baþka bir satýrla yer deðiþtirmek için
	if(matris[0][0] == 0){
		i = 0;
		while(matris[i][0] == 0){
			i++;
			if(matris[i][0] != 0)
			 first = i;
		}
			for(j = 0; j < row; j++){
				swap(&matris[0][j],&matris[first][j]);
			}
	}
	
	//matrisi ekrana bastýrmak için;
	printf("\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column+1; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");
	}
	
	//Üst üçgen matris haline getirmek için;
	double oran;
	for(i = 0; i < row; i++){
		for(j = i+1; j < column; j++){
			oran = matris[j][i] / matris[i][i];
			for(k = 0; k < column+1; k++){
				matris[j][k] = matris[j][k] - oran*matris[i][k];
			}
		}
	}
	
	//matrisi ekrana bastýrmak için;
	printf("\nUst Ucgen Matris:\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column+1; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");
	}
	
	//Kök bulmak için;
	kok[row-1] = matris[row-1][column] / matris[row-1][row-1];
	double sum;
	for(i = row-2; i >= 0; i--){
        sum = 0;
        for(j = row-1; j >= 0; j--){
        	if(i == j)
        		j--;
            sum = sum + matris[i][j] * kok[j];
        }
        kok[i] = (matris[i][row] - sum) / matris[i][i];
    }
    
   	// Sonsuz çözüm ve çözümsüzlük durumlarý için
    for(i = row-1; i <= row-1; i++){
    	for( j = 0; j < row+1; j++){
    		if(matris[i][j] == 0)
    			counter++;
		}
	}
	if(counter == row+1){
        printf("\nkeyfi bilinmeyene gore sonsuz cozum yapilir\n");
        return 0;
        }
    else if(counter == row){
        printf("\nsistemin cozumu yoktur\n");
        return 0;
		}
    
    printf("\n");
	for(i = 0; i < row; i++){
		printf("x%d%: %lf\n",i+1,kok[i]);
	}
	
	return 0;
}
