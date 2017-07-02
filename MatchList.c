#include <stdio.h>
#include <stdlib.h>

typedef struct structNodo{
    int value;
    struct structNodo *next;
}Nodo;

int equals(Nodo *ptr1, Nodo *ptr2){
	while(ptr1->next != NULL && ptr2->next != NULL){
		if(ptr1->value != ptr2->value)
			return 1;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return 0;
}

Nodo * insCoda(Nodo *first, int valore){
    Nodo *newNodo = malloc(sizeof(Nodo));
    newNodo->value = valore;
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
            printf("\nValore = %d", p->value);
            p = p->next;
        }
    }
}

int main()
{
    Nodo *ptr1 = NULL;
    Nodo *ptr2 = NULL;
    
    ptr1 = caricamentoLista(ptr1);
    ptr2 = caricamentoLista(ptr2);
    
    printf("\nLista 1...");
    print_list(ptr1);
    printf("\nLista 1...");
    print_list(ptr2);
    
    if(equals(ptr1, ptr2) == 0)
        printf("Le 2 liste sono uguali");
    else
        printf("Le 2 liste sono diverse");
    return 0;
}

