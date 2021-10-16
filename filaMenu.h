#include <iostream>
#define TAM_FILA 10

using namespace std;
typedef int elem;

typedef struct {
			int inicio, fim, total;
			elem itens[TAM_FILA];
} Fila;

void Create(Fila *F);
void Empty(Fila *F);
bool IsEmpty(Fila *F);
bool IsFull(Fila *F);
void Enter(Fila *F, elem *X, int *erro);
elem Out(Fila *F, int *erro);
void Print(Fila *F);

void Create(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;
     return;
}

void Empty(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;

}

bool IsEmpty(Fila *F) {
    if (F->total==0)
       return true;
    else 
		return false;
}

bool IsFull(Fila *F) {
    if (F->total==TAM_FILA)
       return true;
    else 
		return false;
}

void Enter(Fila *F, elem *X, int *erro) {
     if (!IsFull(F)) {
          *erro=0;
          F->total++;
          F->itens[F->fim]=*X;
          F->fim++;
     }
     else *erro=1;
}

// elem X;
elem Out(Fila *F, int *erro) {
    if (!IsEmpty(F)) {
    	*erro=0;
    	elem X;
		X=F->itens[F->inicio];
		if (F->total == 1){// se tiver somente 1 na fila
			F->total=0;
			F->fim=0;
			F->itens[F->fim] = 0;
		}
		else{ // todo mundo da fila dá 1 passo a frente
			F->total--;			   
			for(int i=0; i< F->total; i++){
				F->itens[i] = F->itens[i+1];// 0 <- 1   1 <- 2    2 <- 3
			}
			F->itens[F->fim] = 0;// para não duplicar o último valor no final na fila
			F->fim--;
			return X;
		}	
    }
    else *erro=1;
}

void Print(Fila *F){
	for (int i= F->inicio; i< F->fim; i++) 
		cout << F->itens[i];
	if(F->total == 0)
		cout << "Ninguém na fila." << endl;
}

