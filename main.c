#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "loops.h"
#include "matrix.h"
#include <string.h>
#define COLS 5 // i
#define ROWS 3 // j
#define NOMBRE_ARCHIVO "peliculasFavoritasESD135_2021 - peliculasFavoritasESD135_2021.csv"
#define LONGITUD_MAXIMA_CADENA 1000
int filas, cols;


int main(int argc, char **argv){

    //[DECLARACION DE VARIABLES]
    int i = 0, j = 0;
    int Mat1[3][3];
    int Mat3[3][3];
    int Mat5[ROWS][COLS];
    int Mat4[3][3];
    int opcion, mainmenu=1;
    printf("┌───────────────────────────────────────┐\n");
    printf("│      PRIMER PARCIAL ESD135 UES        │\n");
    printf("│                                       │\n");
    printf("└───────────────────────────────────────┘\n");
    printf("\n");
    printf("╔═══════════════════════════════════════╗\n");
    printf("║  1-Matriz Transpuesta 5X3             ║\n");
    printf("║  2-Multiplicacion Matricez 2X3 3X3    ║\n");
    printf("║  3-Multiplicacion de una Matriz[]x[]  ║\n");
    printf("║  4-Leer Archivo CSV.                  ║\n");
    printf("║  0-Salir                              ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    scanf("%d",&opcion);
    while(mainmenu==1){
        if((opcion !=1) & (opcion !=2) & (opcion !=3) & (opcion !=4) & (opcion !=5)){mainmenu=0;}
        switch(opcion){
            case 1:
            printf("\n***Matriz Transpuesta %dX%d***\n",COLS,ROWS);
                LOOPMe(i,ROWS){
                LOOPMe(j,COLS){printf("\nIngrese el valor [%d][%d] de la Matriz ",i+1,j+1);
                scanf("%d",&Mat5[i][j]);}}//end fors
                printf("\n\t");
                printf("Se almacenó la siguiente matriz\n");
                LOOPMe(i,ROWS){printf("\n");
                LOOPMe(j,COLS){printf("%3d",Mat5[i][j]);}}
                printf("\n");
                printf("\n**Aplicando Algoritmo de Transposicion...\n");
                printf("\n");
                /*se cambian de posicion las variables que definen las columnas y filas segun el algoritmo de transposicion
                que cambia las columnas por las filas si era una matriz de 4x2 pasa a ser de 2x4*/
                LOOPMe(j,COLS){printf("\n");
                LOOPMe(i,ROWS){printf("%3d",Mat5[i][j]);}}
                printf("\n");
                printf("\n5-Salir\n");
                scanf("%d",&opcion);
                break;
						case 2:
            printf("\n***Multiplicacion Matricez [2X3] x [3X3]***\n");
                printf("Primera Matriz - [2x3]\n");
                LOOPEQ(i,2) {//filas
                LOOPEQ(j,3) {//columnas
                printf("\n Introducir el valor de [%d][%d] : ",i,j);
                scanf("%d",&Mat1[i][j]);}}
                printf("Se almacenó la siguiente matriz\n");
                LOOPEQ(i,2) {printf("\n");
                LOOPEQ(j,3) {printf("%3d",Mat1[i][j]);}}
                printf("\n");
                printf("\nSegunda Matriz [3x3]\n");
                LOOPEQ(i,3) {
                LOOPEQ(j,3) {
                printf("\n Introducir el valor de [%d][%d] : ",i,j);
                scanf("%d",&Mat3[i][j]);}}
                printf("Se almacenó la siguiente matriz\n");
                LOOPEQ(i,3) {printf("\n");
                LOOPEQ(j,3) {printf("%3d",Mat3[i][j]);}}
                printf("\n");
                printf("\n Resultado...\n");
                LOOPEQ(i,2) {
                LOOPEQ(j,3) {Mat4[i][j] = (Mat1[i][1]*Mat3[1][j])+(Mat1[i][2]*Mat3[2][j])+(Mat1[i][3]*Mat3[3][j]);}}
                LOOPEQ(i,2) {printf("\n");
                LOOPEQ(j,3) {printf(" %3d ",Mat4[i][j]);}printf("\n");}printf("\n");
                printf("\n5-Salir\n");
                scanf("%d",&opcion);
                break;
					  case 3:
            printf("\n***Multiplicacion de una Matriz[]x[]***\n");
                int Row_A,Row_ACOL;
                int Row_B,Row_BCOL;
                int**a,**b,**c;
                // Arreglar un
                printf("Ingrese las filas y columnas del Array A: separados por espacio F C\n");
                fflush(stdout);
                scanf("%d %d",&Row_A,&Row_ACOL);
                a = PrimerArray(Row_A,Row_ACOL);
                // Matriz b
                printf("Ingrese las filas y columnas del Array B: separados por espacio F C\n");
                fflush(stdout);
                scanf("%d %d",&Row_B,&Row_BCOL);
                b = PrimerArray(Row_B,Row_BCOL);
                // Matriz c
                c = SalidaMultiplicada(a,b,Row_A,Row_ACOL,Row_B,Row_BCOL);
                ArrayFinal(c,Row_A,Row_BCOL);

                //printf("Memory Allocated at: %x\n",ArrayDim);

                printf("5-Salir\n");
                scanf("%d",&opcion);
                break;
            case '4': ;
				FILE *archivo = fopen(NOMBRE_ARCHIVO, "r"); // Modo lectura
				char bufer[LONGITUD_MAXIMA_CADENA];         // Aquí vamos a ir almacenando cada línea
					while (fgets(bufer, LONGITUD_MAXIMA_CADENA, archivo)){
						// Aquí, justo ahora, tenemos ya la línea. Le vamos a remover el salto
						strtok(bufer, "\n");
						// La imprimimos, pero realmente podríamos hacer cualquier otra cosa
						printf("La línea es: '%s'\n", bufer);
						llenarMatriz(60, 7);
			break;
					case 5:					
					Carnet(",NULL");
					break;
            case 0:
                printf("Adiós\n");
                opcion = 0; mainmenu = 0;
                break;

                default:
                printf("\n **Opcion nó valida**\n\a");
                opcion = 0; mainmenu = 0;
            }
        }
    }
    return 0;
}

int** llenarMatriz(int f, int c) {
  filas = f;
  cols = c;
  int **matriz = malloc(f*sizeof(int));
  for (int i = 0; i < f; i++) {
    matriz[i] = malloc(c*sizeof(int));
  		for (int j = 0; j < c; j++) {
        matriz[i][j] = '%s', bufer;
      }
  }
  return matriz;
}
char *Carnet(char Carnet){
	const char carnet = "JG11008";
	return carnet;

}
int** leerMatriz(char *fileName) {
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	char linea[80];
	fgets(linea, 79, fp); 
	char *token = strtok(linea, " ");//10 6
	filas = atoi(token);
	token = strtok(NULL, " ");
	cols = atoi(token);
	int **matriz = malloc(filas*sizeof(int));
	for (int i = 0; i < filas; i++) {
		matriz[i] = malloc(cols*sizeof(int));
		fgets(linea,79, fp);
		token = strtok(linea, " ");
		matriz[i][0] = atoi(token);
		for (int j = 1; j < cols; j++) {
			token = strtok(NULL, " ");
			matriz[i][j] = atoi(token);
		}
	}
	fclose(fp);
	return matriz;
}