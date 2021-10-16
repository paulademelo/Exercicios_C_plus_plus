#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <locale>

using namespace std;

/*Exercicio 1)Crie uma estrutura para 
* representar as coordenadas de um ponto
* no plano (posições X e Y). Em seguida,
* declare e leia do teclado um ponto e
* exiba a distância dele até a origem das
* coordenadas, isto é, posição (0, 0).
* Para realizar o cálculo, utilize a fórmula
* a seguir:
* d = raíz quadrada((Xb - Xa)² + (Yb - Ya)²)
* Em que: d = distância entre os pontos A e B
* X = coordenada X em um ponto
* Y = coordenada Y em um ponto
*/
int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	float d;
	
	struct ponto{
		int x;
		int y;
	}p;
	
	cout << "Digite a coordenada x: " << endl;
	cin >> p.x;
	
	cout << "Digite a coordenada y: "<< endl;
	cin >> p.y;
	
	d = sqrt(pow( (p.x-0), 2 )+ pow( (p.y-0), 2) );
	
	cout << "Distância entre o ponto e a origem (x=O, y=0): " << d << endl;
	return 0;
}
