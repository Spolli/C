#include <stdio.h>
#include <stdlib.h>

typedef struct structNodo{
    int val;
    struct structNodo *next;
}Nodo;

Nodo * push(Nodo *first, int valore){
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

Nodo * merge_list(Nodo * head1, Nodo * head2){
    int flag = 1;
    Nodo *newNodo = NULL;
    Nodo *current1 = head1;
    Nodo *current2 = head2;
    while(current1 != NULL || current2 != NULL){
        if(flag == 1){
            newNodo = push(newNodo, current1->val);
            current1 = current1->next;
            flag = 0;
        }
        else{
            newNodo = push(newNodo, current2->val);
            current2 = current2->next;
            flag = 1;
        }
    }
    return newNodo;
}

void merge_list_same(Nodo * head1, Nodo * head2){
    int flag = 1;
    while(head1 != NULL || head2 != NULL){
        if(flag == 1){
            //current1->val = current1->val;
            //current1->next = current1->next;
            head1 = head1->next;
            flag = 0;
        }
        else{
            head1->val = head2->val;
            head1 = head1->next;
            head2 = head2->next;
            flag = 1;
        }
    }
}
/*
Nodo * caricamentoLista(Nodo *root){
    Nodo *head = root;
    int num;
    do{
        printf("\nInserisci il valore: ");
        scanf("%d", &num);
        push(head, num);
    }while(num != 0);
    return head;
}
*/

int main(){
    int num, i;
    Nodo *root1 = NULL;
    Nodo *root2 = NULL;
    //root2 = malloc(sizeof(Nodo));
    //root1 = malloc(sizeof(Nodo));
    printf("\nCaricamento Lista 1... (inserisci 0 per terminare)");
    for(i = 0; i < 5; i++){
        printf("\nInserire il valore: ");
        scanf("%d", &num);
        root1 = push(root1, num);
    }
    printf("\nCaricamento Lista 2... (inserisci 0 per terminare)");
    for(i = 0; i < 5; i++){
        printf("\nInserire il valore: ");
        scanf("%d", &num);
        root2 = push(root2, num);
    }
    printf("\nStampa stampa lista 1...");
    print_list(root1);
    printf("\nStampa stampa lista 2...");
    print_list(root2);

    printf("\nMerge liste...");
    Nodo *merge_lista = merge_list(root1, root2);
    printf("\nStampa lista merge...");
    print_list(merge_lista);

    printf("\nMerge su lista 1...");
    merge_list_same(root1, root2);
    printf("\nStampa lista merge su lista 1...");
    print_list(root1);
    return 0;
}
