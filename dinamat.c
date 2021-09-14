#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "loops.h"
#include "matrix.h"
//creacion de la matriz dinamica...
int **PrimerArray(int Row_A,int Row_ACOL){
	int i,j;
	int **a=NULL;
	a=(int**)malloc(sizeof(int*)*Row_A);
	for(i=0;i<Row_A;i++)
		*(a+i)=(int*)malloc(sizeof(int)*Row_ACOL);
	printf("\nIngrese los elementos del Array:\n");
	fflush(stdout);
	for(i=0;i<Row_A;i++)
		for(j=0;j<Row_ACOL;j++)
			scanf("%d",*(a+i)+j);
	return a;
}

//Matriz de salida
void ArrayFinal(int **a,int Row_A,int Row_ACOL){
	int i,j;
    int k=0;
    printf("\nEl Resultado es:\n");
    printf("\n");
	for(i=0;i<Row_A;i++){
			for(j=0;j<Row_ACOL;j++){

				printf("%d ",*(*(a+i)+j));
				k++;
				if(Row_ACOL==k){
					printf("\n");
					k=0;
				}
			}
	}
    printf("\n");
}

//multiplicando...
int ** SalidaMultiplicada(int **a,int **b,int Row_A,int Row_ACOL,int Row_B,int Row_BCOL){
	int **c;
	int i,j,k;
	if(Row_ACOL!=Row_B){
		printf("\nArray A No se puede multiplicar Array B!");
		exit(0);
	}
	else{
		// Construir matriz C
		c=(int **)malloc(sizeof(int*)*Row_A);// Toma el número de filas en una matriz
		for(i=0;i<Row_A;i++)
		*(c+i)=(int *)malloc(sizeof(int)*Row_BCOL);

		// Inicializa la matriz c y establece los elementos de la matriz c en 0
		for(i=0;i<Row_A;i++)
					for(j=0;j<Row_BCOL;j++)
						*(*(c+i)+j)=0;

		// Calcular c matriz a * b = c;
		for(i=0;i<Row_A;i++)
					for(j=0;j<Row_BCOL;j++)
						for(k=0;k<Row_ACOL;k++)
							*(*(c+i)+j)+=(*(*(a+i)+k))*(*(*(b+k)+j));// k es el signo de la suma
		return c;
	}
}