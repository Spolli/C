#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct structNodo{
    int val;
    struct structNodo *next;
}Nodo;

Nodo * insCoda(Nodo *first, int valore){
    Nodo *newNodo = malloc(sizeof(Nodo));
    newNodo->val = valore;
    newNodo->next = NULL;
    if(first == NULL)
        first = newNodo;
    else{
        Nodo *p = first;
        while(p->next != NULL)
            p = p->next;
        p->next = newNodo;
    }
    return first;
}

Nodo * caricamentoLista(Nodo *root){
    int n;
    Nodo *head = root;
    do{
        printf("\nInserisci il valore: ");
        scanf("%d", &n);
        if(n != 0)
            head = insCoda(head, n);
    }while(n != 0);
    return head;
}

void print_list(Nodo * head) {
    if(head == NULL)
        printf("\nLista vuota!");
    else{
        Nodo *p = head;
        while(p != NULL){
            printf("\nValore = %d", p->val);
            p = p->next;
        }
    }
}

int lenght(Nodo * head){
  if(head == NULL)
      return 0;
  else{
      Nodo *p = head;
      int counter = 0;
      while(p != NULL){
          counter++;
          p = p->next;
      }
      return counter;
  }
}

int soglia(Nodo * head, int x){
  if(head == NULL)
      return 0;
  else{
      Nodo *p = head;
      int sum = 0;
      while(p != NULL){
          if(p->val >= x){
            sum += p->val;
          }
          p = p->next;
      }
      return sum;
  }
}

int main() {
  Nodo *root = NULL;
  /*
  //Caricamneto lista a mano
  root = caricamentoLista(root);
  print_list(root);
  */
  /******************************************************************/
  //Caricamento lista automatico
  srand(time(NULL));
  int i;
  /*
  int element;
  printf("\nInserire il numero di elementi da caricare = ");
  scanf("%d", &element);
  */
  for (i = 0; i < rand(); i++) {
    root = insCoda(root, rand());
  }
  print_list(root);
  int lunghezza = lenght(root);
  printf("\nLa lunghezza della lista e' = %d", lunghezza);
  int x;
  printf("\nInserire la soglia da calcolare = ");
  scanf("%d", &x);
  int somma = soglia(root, x);
  printf("\nLa somma dei valori maggiori o uguali a %d e' = %d", x, somma);
  return 0;
}
