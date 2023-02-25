//GAUSS ELEM�NASYON METODU
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
	column = row; //bu y�ntem kare matrislerde kullan�l�r
	
	double **matris = (double**) malloc(sizeof(double) * row);
	double *kok = (double*) malloc(sizeof(double) * row);
	for(i = 0; i < column; i++){
		matris[i] = (double*) malloc(sizeof(double) * (column+1));
	}
	
	//matrisin elemanlar�n� almak i�in;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d. elemani giriniz: ",iterasyon);
			scanf("%lf",&matris[i][j]);
			iterasyon++;
		}
	}
	
	//sonu� matrisini girmek i�in;
	for(i = 0; i < row; i++){
		for(j = column; j < column+1; j++){
			printf("Sonuc matrisinde %d.elemani giriniz: ",i+1);
			scanf("%lf",&matris[i][j]);
		}
	}
	
	//matrisin ilk eleman� 0 ise ba�ka bir sat�rla yer de�i�tirmek i�in
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
	
	//matrisi ekrana bast�rmak i�in;
	printf("\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column+1; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");
	}
	
	//�st ��gen matris haline getirmek i�in;
	double oran;
	for(i = 0; i < row; i++){
		for(j = i+1; j < column; j++){
			oran = matris[j][i] / matris[i][i];
			for(k = 0; k < column+1; k++){
				matris[j][k] = matris[j][k] - oran*matris[i][k];
			}
		}
	}
	
	//matrisi ekrana bast�rmak i�in;
	printf("\nUst Ucgen Matris:\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column+1; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");
	}
	
	//K�k bulmak i�in;
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
    
   	// Sonsuz ��z�m ve ��z�ms�zl�k durumlar� i�in
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
