//Gauss Seidal Metodu
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 100
void swap(double *a, double *b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

void printMatrix(int row,int column,double matris[size][size]){
	int i,j;
	printf("\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column+1; j++){
			printf("%lf\t",matris[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	int i,j,k,row,column,iterasyon = 1;
	printf("Satir sayisini giriniz: ");
	scanf("%d",&row);
	column = row; // kare matris i�in

	double matris[size][size];
	double *kok = (double*) malloc(sizeof(double) * row);
	double *hata = (double*) malloc(sizeof(double) * row);
	
	//matrisin elemanlar�n� almak i�in;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d. katsayiyi giriniz:",iterasyon);
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
	
	printMatrix(row,column,matris);
	
	// k��egen eleman�n� en b�y�k yapma
	double temp,first,second;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			first = fabs(matris[i][i]);
			second = fabs(matris[j][i]);
			if(first < second){
				for(k = 0; k < row+1; k++){
				    swap(&matris[i][k],&matris[j][k]);
				}
			}
		}
	}
	
	//matrisi ekrana bast�rmak i�in;
	printf("\nDuzenlenmis matris:\n");
	printMatrix(row,column,matris);
	
	//ba�lang�� k�k de�erlerini alma
	for(i = 0; i < row; i++){
		printf("\nx%d: ",i+1);
		scanf("%lf",&kok[i]);
	}
	
	//hata pay�n� kullan�c�dan alma
	double e;
	printf("\nHata payini giriniz: ");
	scanf("%lf",&e);
	
	int maxit = 0,maxiterasyon;
	printf("Iraksama durumu icin gidilecek max iterasyon sayisi(onerilen:60):");
	scanf("%d",&maxiterasyon);
	printf("\n");
	
	for(i = 0; i < row; i++)
		printf("x%d: %.3lf\t |delta x%d|: -\t\t\t",i+1,kok[i],i+1);
	printf("\n");	
	//gauss seidal metodu
	int m = 0,sayac = 0;
	while(sayac < row || maxit == maxiterasyon){
		sayac = 0;
		for(i = 0; i < row; i++){ //k�klerin yeni de�erlerini(sum) bulmak i�in
		double sum = matris[i][column] / matris[i][i];
			for(j = column-1; j >= 0; j--){
				if(i == j)
					j--;	
				sum += ((-1) * matris[i][j] * kok[j]) / matris[i][i];
			}
		
		hata[m] = sum - kok[i]; //yeni de�er olan sum dan eski de�er olan kok[i] yi ��kartarak hata de�erini buldum
		if(hata[m] < 0)
			hata[m] *= (-1);
		if(hata[m] <= e) //hata verilen hata pay�ndan k���k e�itse saya�� artt�rd�m
			sayac++;
		kok[i] = sum; // k�klerin de�erlerini g�ncelledim	
		printf("x%d: %.3lf\t |delta x%d|: %.3lf\t\t",m+1,kok[i],m+1,hata[m]);
		
		m++; //hata dizisine yeni eleman atayabilmek i�in
		if(m == row) // hata dizisinde z den sonra x e geri d�nmek i�in
			m = 0;
		}
		
		maxit++;
		if(maxit == maxiterasyon){
			printf("\n Sonuc degerleri iraksadi\n");
			return 0;
		}	
		printf("\n");
	}
	
	printf("\n");
	for(i = 0; i < row; i++)
		printf("x%d: %.3lf\t",i+1,kok[i]);	
	
	return 0;
}
