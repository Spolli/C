#include <stdio.h>
#include <stdlib.h>

typedef struct structNodo{
  int dato; //albero di valori interi
  struct nodo *Dx; //puntatore al sottoalbero destro
  struct nodo *Sx; //puntatore al sottoalbero sinistro
}Nodo;

void Inorder(Nodo *first){
	if (first != NULL) {
		Inorder(first->Sx);
		printf("%d \t", first->dato);
		Inorder(first->Dx);
    }
}


void Preorder(Nodo *first){
	if (first != NULL) {
        printf("%d \t", first->dato);
		Preorder(first->Sx);
		Preorder(first->Dx);
    }
}


void Postorder(Nodo *first){
	if (first != NULL) {
		Postorder(first->Sx);
		Postorder(first->Dx);
		printf("%d \t", first->dato);
    }
}


int ContaNodi(Nodo *first){
	if(first == NULL)
		return 0;
	else
		return(1 + ContaNodi(first->Sx) + ContaNodi(first->Dx));
}

int ContaFoglie(Nodo *first){
	if(first == NULL)
		return(0);
	else {
		if ((first->Sx == NULL) && (first->Dx == NULL))
			return 1;
		else
			return((ContaFoglie(first->Sx) + ContaFoglie(first->Dx)));
	}
}

int bilanciato(Nodo *first){
	if (first == NULL)
		return 1;
	else {
		if ((first->Sx == NULL) && first->Dx == NULL)
			return 1;
		else {
			if ((first->Sx != NULL) && (first->Dx != NULL))
				return(bilanciato(first->Sx) && bilanciato(first->Dx) );
			else
				return 0;
		}
	}
}


int Ricerca(Nodo *first, int x){
	if (first == NULL)
		return 0;
	else {
		if (x == first->dato)
			return 1;
		else
			return(Ricerca(first->Sx, x) || Ricerca(first->Dx, x));
	}
}


int Altezza_Nodo(Nodo *first){
  int ALTD = 0, ALTS = 0;
	if (first == NULL)
		return -1;
	else {
		ALTS = Altezza_Nodo(first->Sx);
		ALTD = Altezza_Nodo(first->Dx);
		if (ALTS > ALTD)
			return(ALTS + 1);
		else
			return(ALTD + 1);
	}
}

Nodo * Ins_Ord(int E, Nodo *first){
	if (first == NULL) {
		first = malloc(sizeof(Nodo));
		first->dato = E;
		first->Sx = NULL;
		first->Dx = NULL;
		return first;
	}
	else {
		if(E < first->dato) {
			first->Sx = Ins_Ord(E, first->Sx);
			return first;
		}
		else {
			first->Dx = Ins_Ord(E, first->Dx);
			return first;
		}
	}
}

int RicercaBinaria(int x, Nodo *first){
	if (first == NULL)
		return 0;
	else {
		if (x == first->dato)
			return 1;
		else {
			if (x < first->dato)
				return (RicercaBinaria(x, first->Sx));
			else
				return (RicercaBinaria(x, first->Dx));
		}
	}
}

int main(){
    int n, i;
    Nodo *root = NULL;
    for(i = 0; i < 5; i++){
        printf("Inserire il valore: ");
        scanf("%d", &n);
        root = Ins_Ord(root, n);
    }
    Inorder(root);
}
