#include <stdio.h>
#include <stdlib.h>

void prodVett(int vetS[], int *vetD[], int n){
	int i;
	for(i = 0; i < n; i++){
		vetS[i] *= (int)vetD[i];
	}
}

int * sommaVett(int vetS[], int *vetD[], int n){
	int i;
	int *vetSomma;
	vetSomma = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++){
		vetSomma[i] = vetS[i] + vetD[i];
	}
	return vetSomma;
}

void stampaStatica(int vett[], int n){
	int i;
	for(i = 0; i < n; i++){
        printf("\n");
		printf("%d. Elemento = %d", i + 1, vett[i]);
	}
}

void stampaDinamica(int *vett[], int n){
	int i;
	for(i = 0; i < n; i++){
        printf("\n");
		printf("%d. Elemento = %d", i + 1, vett[i]);
	}
}

int main() {

	int n, i;

	printf("Numero elementi dei vettori: ");
	scanf("%d", &n);

	int *vetDin;
	int vetStatic[n];
	vetDin = malloc(n * sizeof(int));

	printf("\nCaricamento valori nell'vettore dinamico...");
	for(i = 0; i < n; i++) {
		printf("\nInserisci elemento a[%d]: ", i);
		scanf("%d", &(vetDin[i]));
	}

	printf("\nInserimento valori nell'vettore statico...");
	for(i = 0; i < n; i++) {
		printf("\nInserisci elemento vet[%d]: ", i);
		scanf("%d", &(vetStatic[i]));
	}

	printf("\nStampa vettore dinamico...");
	stampaDinamica(vetDin, n);
    printf("\nStampa vettore statico...");
	stampaStatica(vetStatic, n);
	int *p = sommaVett(vetStatic, vetDin, n);
    printf("\nStampa vettore dopo somma...");
	stampaDinamica(p, n);
    printf("\nStampa vettore dopo prodotto...");
	prodVett(vetStatic, vetDin, n);
	stampaStatica(vetStatic, n);
	return 0;
}
