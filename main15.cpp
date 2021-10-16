#include <iostream>
#include "estrutura_pilha15.h"
#include <locale>
using namespace std;
/*15) Implemente no m�todo main(...),
* um programa que leia 20 n�meros de um vetor, tenha tr�s
* pilhas (P1, P2 e P3) e proceda, para cada um deles, como segue:
* - se o n�mero for par, insira-o na pilha P1;
* - se o n�mero lido for �mpar, insira na pilha P2;
* - se positivo, retirar da pilha P2;
* - se negativo, retirar da pilha P1.
* - Ao final, imprima cada uma das pilhas P1 e P2.
*/
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	elem elemento;
	int erro;
	int vetor[20];
	Pilha Pilha1, Pilha2, Pilha3;

	Create(&Pilha1);
	Create(&Pilha2);
	Create(&Pilha3);

	for(int i=0; i<20; i++){
		cout << "Digite o "<< i+1 << "� n�mero: " << endl;
		cin >>vetor[i];
	}

	for(int i=0; i<= 20; i++){
		// vetor par
		if(vetor[i] % 2 == 0){
			// verifica se ele � positivo
			if (vetor[i]>=0){
				elemento = vetor[i];
				Push(&Pilha1, &elemento, &erro);	
			}
			else{
				// retira se negativo
				elemento = vetor[i];
				Push(&Pilha1, &elemento, &erro);
				Pop(&Pilha1,&erro);
			}
		}
		// verifica se �mpar
		else if(vetor[i] % 2 != 0){

			if(vetor[i]> 0){
				elemento = vetor[i];
				Push(&Pilha2, &elemento, &erro);
			}
			else{
				elemento = vetor[i];
				Push(&Pilha2, &elemento, &erro);
				Pop(&Pilha2, &erro);
			}
		}
	}
		cout << "Valores pares da pilha 1:" << endl;
		Print(&Pilha1);
		cout << "\n";

		cout << "Valores �mpares da pilha 2:" << endl;
		Print(&Pilha2);

	return 0;
}
