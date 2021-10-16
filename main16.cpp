#include <iostream>
#include "estrutura_pilha16.h"
#include "FilaMenu.h"
#include <locale>

using namespace std;
/*16) Escreva um método para inverter a ordem dos elementos de uma fila de 10 elementos,
usando uma pilha como estrutura auxiliar. 
*/

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");

	elem elemento;
	Fila Fila1;
	Pilha Pilha1;
	int erro;

	Create(&Fila1);
	Create(&Pilha1);

	for(int i=0; i<3; i++){
		cout << "Digite o "<< i+1 <<"º número para inserir na fila:" << endl;
		cin >> elemento;
		Enter(&Fila1, &elemento, &erro);
		Push(&Pilha1, &elemento, &erro);
	}

	cout << "======== IMPRIMIR FILA ========" << endl;
	for(int i=0; i<3; i++){
		Print(&Fila1);		
		cout << "\n==========================" << endl;
		break;
	}
	
	cout << "======== IMPRIMIR PILHA========" << endl;	
	for(int i=0; i<3; i++){
		cout << Pilha1.itens[i];		
	}
	cout << "\n==========================" << endl;
	
	cout << "======== INVERTER FILA/PILHA ========" << endl;
	for(int i=0; i<3; i++){
		elemento = Pop(&Pilha1, &erro);
		Out(&Fila1, &erro);
		Enter(&Fila1, &elemento, &erro);	
	}
	Print(&Fila1);
	cout << "\n==========================" << endl;
	
	return 0;
}
