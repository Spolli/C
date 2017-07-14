#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float media(int righe, int colonne, int matrix[righe][colonne]){
  float media = 0.0f;
  int i, j;
  for (i = 0; i < colonne; i++) {
    for (j = 0; j < righe; j++) {
      if(i == j){
        printf("\nL'indice delle righe e delle colonne sono uguali = %d", matrix[i][j]);
      }
      media += matrix[i][j];
    }
  }
  return media / (righe*colonne);
}

void stampa(int righe, int colonne, int matrix[righe][colonne]){
  int i, j;
  for (i = 0; i < colonne; i++) {
    for (j = 0; j < righe; j++) {
      printf("\nMatrix[%d][%d] = %d", i, j, matrix[i][j]);
    }
  }
}

int main()
{
    int colonne = 10, righe = 10;
    int matrix[righe][colonne];
    int num;
    int i, j;
    for (i = 0; i < colonne; i++) {
      for (j = 0; j < righe; j++) {
        printf("\nValore in posizione[%d][%d] = ", i, j);
        scanf("%d", &num);
        matrix[i][j] = num;
      }
    }
    /*
    //Inserimento automatico numero nella matrice
    srand(time(NULL));
    for (i = 0; i < colonne; i++) {
      for (j = 0; j < righe; j++) {
        matrix[i][j] = rand();
      }
    }
    */
    stampa(righe, colonne, matrix);
    float app = media(righe, colonne, matrix);
    printf("\nLa media e' = %f", app);
    return 0;
}
