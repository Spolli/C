#include <stdio.h>
#include <stdlib.h>

float media_riga(int righe, int colonne, int matrix[righe][colonne], int x){
    int i;
    int media = 0;
    for(i = 0; i < colonne; i++){
        media += matrix[x][i];
    }
    return media / colonne;
}

void fillMatrix(int righe, int colonne, int matrix[righe][colonne]){
  int i, j;
  for (i = 0; i < righe; i++) {
    for (j = 0; j < colonne; j++) {
      printf("Inserire valore in posizione [%d][%d]: ", i, j);
      scanf("%d\n", &matrix[i][j]);
    }
  }
}

int main() {
  int righe, colonne, x;
  printf("\nInserire le righe: ");
  scanf("%d", &righe);
  printf("\nInserire le colonne: ");
  scanf("%d", &colonne);
  int matrix[righe][colonne];
  fillMatrix(righe, colonne, matrix);
  printf("\nInserire la riga a cui si vuole fare la media: ");
  scanf("%d", &x);
  printf("\nMedia della riga %d: %f", x, media_riga(righe, colonne, matrix, x));
  return 0;
}
