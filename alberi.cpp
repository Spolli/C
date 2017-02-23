#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
	int dato; //albero di valori interi
	struct nodo *Dx; //puntatore al sottoalbero destro
	struct nodo *Sx; //puntatore al sottoalbero sinistro
};

Nodo Albero_Vuoto(){
	return NULL;
}

int valoreNodo(Nodo first){
	if (first == NULL) 
		return 0;
	else 
		return first->dato;
}

Nodo Sinistro(Nodo first){ 
	if (first == NULL) 
		return NULL;
	else 
		return first->Sx;
}

Nodo Destro(Nodo first){ 
	if (first == NULL)
		return NULL;
	else 
		return first->Dx;
}

Nodo Costruisci_Albero(int val, Nodo sx, Nodo dx){
	Nodo first;
	first = new Nodo();
	first->dato = val;
	first->Sx = sx;
	first->Dx = dx;
	return first;
}


void Inorder(Nodo first){
	if (first != NULL) {
		Inorder(Sinistro(first));
		cout<<valoreNodo(first)<<"  ";
		Inorder(Destro(first));
		}
}


void Preorder(Nodo first)
//stampa preorder dell'albero
{
	if (first != NULL) {
		cout<<valoreNodo(first)<<"  ";
		Preorder(Sinistro(first));
		Preorder(Destro(first));
		}
}


void Postorder(Nodo first)
//stampa postorder dell'albero
{
	if (first != NULL) {
		Postorder(Sinistro(first));
		Postorder(Destro(first));
		cout<<valoreNodo(first)<<"  ";
		}
}


int ContaNodi(Nodo first){
	if(first == NULL) 
		return 0;
	else 
		return(1 + ContaNodi(Sinistro(first)) + ContaNodi(Destro(first)));
}

int ContaFoglie(Nodo first){
	if(first == NULL) 
		return(0);
	else {
		if ((Sinistro(first) == NULL) && (Destro(first) == NULL))
			return 1;
		else 
			return(ContaFoglie(Sinistro(first)) + ContaFoglie(Destro(first)));
	}
}

bool bilanciato(Nodo first){
	if (first == NULL)
		return true;
	else {
		if ((Sinistro(first) == NULL) && (Destro(first) == NULL))
			return true;
		else {
			if ((Sinistro(first) != NULL) && (Destro(first) != NULL))
				return(bilanciato(Sinistro(first)) && bilanciato(Destro(first)) );
			else 
				return false;
		}
	}
}


bool Ricerca(Nodo first, int x){
	if (first == NULL)
		return false;
	else {
		if (x == valoreNodo(first))
			return true;
		else
			return(Ricerca(Sinistro(first), x) || Ricerca(Destro(first), x));
	}
}


int Altezza_Nodo(Nodo N){
  int ALTD = 0, ALTS = 0;
	if (N == NULL)
		return -1;
	else {
		ALTS = Altezza_Nodo(Sinistro(N));
		ALTD = Altezza_Nodo(Destro(N));
		if (ALTS > ALTD) 
			return(ALTS + 1);
		else 
			return(ALTD + 1);
	}
}

Nodo Ins_Ord(int E,Nodo first){
	if (first == NULL) {
		first= new Nodo();
		first->dato = E;
		first->Sx = NULL;
		first->Dx = NULL;
		return first;
	}
	else {
		if(E < valoreNodo(first)) {
			first->Sx = Ins_Ord(E, Sinistro(first));
			return first;
		}
		else {
			first->Dx = Ins_Ord(E, Destro(first));
			return first;
		}
	}
}


bool RicercaBinaria(int x,Nodo first){
	if (first == NULL)
		return false;
	else {
		if (x == valoreNodo(first)) 
			return true;
		else {
			if (x < valoreNodo(first))
				return (RicercaBinaria(x, Sinistro(first)));
			else 
				return (RicercaBinaria(x, Destro(first)));
		}
	}
}

int main(){
	Nodo t1, t2, t3, t4;
	int x;
	
	t1 = Costruisci_Albero(2, Albero_Vuoto(), Albero_Vuoto());
	t2 = Costruisci_Albero(1, Albero_Vuoto(), Albero_Vuoto());
	t3 = Costruisci_Albero(7, t1, t2);

	t1 = Costruisci_Albero(4, Albero_Vuoto(), Albero_Vuoto());
	t2 = Costruisci_Albero(9, Albero_Vuoto(), Albero_Vuoto());
	t4 = Costruisci_Albero(3, t1, t2);

	t1=Costruisci_Albero(5,t3,t4);
	/*
	cout<<"\nStampa in Inorder:\n";
	Inorder(t1);

	cout<<"\n\nStampa in Preorder:\n";
	Preorder(t1);

	cout<<"\n\nStampa in Postorder:\n";
	Postorder(t1);
	*/
	cout << "\n\nLa first dell 'albero è : " << valoreNodo(t1);

	cout << "\n\nIl numero totale dei nodi dell'albero è : " << ContaNodi(t1);

	cout << "\n\nIl numero totale delle foglie dell'albero è : " << ContaFoglie(t1);

	cout << "\n\nQuesto albero ha altezza " << Altezza_Nodo(t1) << " (" << Altezza_Nodo(t1) + 1 << " livelli)";

	if (bilanciato(t1)) 
		cout<<"\n\nQuesto albero è perfettamente bilanciato.";
	else 
		cout<<"\n\nQuesto albero non è perfettamente bilanciato.";

	cout << "\n\nInserire un valore da cercare nell'albero : ";
	cin >> x;
	if (Ricerca(t1, x)) 
		cout<<"\n\tValore trovato!!";
	else 
		cout<<"\n\tValore non trovato!!";
 

	t1 = Albero_Vuoto();

	cout<<"\nInserire tutti gli elementi (per terminare inserire 0)\n";
	
    do {
		cout << "\tElemento : ";
		cin >> x;
		t1 = Ins_Ord(x, t1);
	} while (x != 0);
	/*
	cout<<"\nStampa in Inorder:\n";
	Inorder(t1);

	cout<<"\n\nStampa in Preorder:\n";
	Preorder(t1);

	cout<<"\n\nStampa in Postorder:\n";
	Postorder(t1);
	*/
	cout << "\n\nLa first è : " << valoreNodo(t1);

	cout << "\n\nIl numero totale dei nodi dell'albero è : " << ContaNodi(t1);

	cout << "\n\nIl numero totale delle foglie dell'albero è : " << ContaFoglie(t1);

	cout<<"\n\nQuesto albero ha altezza "<<Altezza_Nodo(t1)<<" ("<<Altezza_Nodo(t1)+1<<" livelli)";

	if (bilanciato(t1)) 
		cout<<"\n\nQuesto albero è perfettamente bilanciato.";
	else 
		cout<<"\n\nQuesto albero NON è perfettamente bilanciato.";

	cout<<"\n\nInserire un elemento da cercare con la ricerca dicotomica : ";
	cin>>x;

	if (RicercaBinaria(x,t1)) 
		cout<<"\n\tValore trovato!!";
	else 
		cout<<"\n\tValore non trovato!!";
  return 0;
}
