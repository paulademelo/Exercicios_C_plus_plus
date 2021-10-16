#define TAM_PILHA 20
using namespace std;

typedef int elem;
typedef struct
{
	int topo;
	elem itens[TAM_PILHA];
}Pilha;

void Create(Pilha *P);
void Push(Pilha *P, elem *X, int *erro);
elem Pop(Pilha *P, int *erro);
bool IsFull(Pilha *P);
bool IsEmpty(Pilha *P);
void Empty(Pilha *P);

void Create(Pilha *P){
	//P = (Pilha*) malloc(sizeof(Pilha));  // CUIDADO: você não quer criar um vetor de Pilhas
	P->topo = -1;
}

bool IsFull(Pilha *P)
{
	if(P->topo == TAM_PILHA-1)
		return true;
	return false;
}

void Push(Pilha *P, elem *X, int *erro)
{
	if(!IsFull(P)){
		P->topo++;
		P->itens[P->topo] = *X;
		*erro = false;
	}
	*erro = true;
}

void Empty(Pilha *P)
{	
	P->topo = -1;
}

bool IsEmpty(Pilha *P)
{
	if(P->topo == -1)
		return true;
	return false;
}

elem Pop(Pilha *P, int *erro)
{
    elem X;
    if(!IsEmpty(P)){
        X = P->itens[P->topo];
        P->topo--;
        return X;
    }

    return X = -1;
}

void Print(Pilha *P){
    int i;
    for(i= P->topo; i > 0; i--) 
        cout << P->itens[i]<<" | ";
    if(i == 0)
        cout << "Ninguém na Pilha." << endl;
}
