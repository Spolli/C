#include <stdio.h>
#include <stdlib.h>

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

Nodo * merge_lista_rosi(Nodo * head1, Nodo * head2){
    Nodo *current1 = head1;
    Nodo *current2 = head2;
    Nodo *newList = NULL;
    while(current1 != NULL || current2 != NULL){
        newList = insCoda(newList, current1->val);
        current1 = current1->next;
        newList = insCoda(newList, current2->val);
        current2 = current2->next;
    }
    return newList;
}

/*Work in progress*/
void merge_lista_rosi_same(Nodo * head1, Nodo * head2){
    Nodo *current1 = head1;
    while(head2 != NULL){
        head1->next = head2;
        head1->next->next = current1->next;
        current1 = current1->next;
        head2 = head2->next;
        head1 = head1->next;
    }
}

Nodo * merge_list(Nodo * head1, Nodo * head2){
    int flag = 1;
    Nodo *newNodo = NULL;
    Nodo *current1 = head1;
    Nodo *current2 = head2;
    while(current1 != NULL || current2 != NULL){
        if(flag == 1){
            if(current1 == NULL){
                newNodo = insCoda(newNodo, current2->val);
                current2 = current2->next;
            }
            else{
                newNodo = insCoda(newNodo, current1->val);
                current1 = current1->next;
            }
            flag = 0;
        }
        else{
            if(current2 == NULL){
                newNodo = insCoda(newNodo, current1->val);
                current1 = current1->next;
            }
            else{
                newNodo = insCoda(newNodo, current2->val);
                current2 = current2->next;
            }
            flag = 1;
        }
    }
    return newNodo;
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

int main(){
    int num, i;
    Nodo *root1 = NULL;
    Nodo *root2 = NULL;
    printf("\nCaricamento Lista 1... (inserisci 0 per terminare)");
    root1 = caricamentoLista(root1);
    printf("\nCaricamento Lista 2... (inserisci 0 per terminare)");
    root2 = caricamentoLista(root2);
    printf("\nStampa stampa lista 1...");
    print_list(root1);
    printf("\nStampa stampa lista 2...");
    print_list(root2);

    printf("\nMerge liste...");
    /*
    Nodo *merge_lista = merge_list(root1, root2);
    printf("\nStampa lista merge...");
    print_list(merge_lista);

    printf("\nMerge su lista 1...");
    merge_list_same(root1, root2);
    printf("\nStampa lista merge su lista 1...");
    print_list(root1);
    */
    Nodo *merge_lista = merge_lista_rosi(root1, root2);
    printf("\nStampa lista merge...");
    print_list(merge_lista);

    printf("\nMerge su lista 1...");
    merge_lista_rosi_same(root1, root2);
    printf("\nStampa lista merge su lista 1...");
    print_list(root1);
    return 0;
}
