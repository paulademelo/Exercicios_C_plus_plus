#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <locale>

using namespace std;

/*Exerc�cio 2) Usando a estrutura Ret�ngulo do
* exerc�cio anterior, fa�a um programa
* que declare e leia uma estrutura
* Ret�ngulo e um Ponto, e informe se
* esse ponto est� ou n�o dentro do ret�ngulo.
*/

struct ponto{
		int x;
		int y;
};
	
struct retangulo{
		struct ponto pS;
		struct ponto pI;
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Portuguese");
	
	struct retangulo ret;
	struct ponto pt;

	
	cout << "Calcular ponto superior esquerdo"<<endl;
	cout << "Digite a coordenada x: " << endl;
	cin >> ret.pS.x;
	
	cout << "Digite a coordenada y: "<< endl;
	cin >> ret.pS.y;
	cout << "=================================" <<endl;
	
	cout << "Calcular ponto inferior direito"<<endl;
	cout << "Digite a coordenada x: " << endl;
	cin >> ret.pI.x;
	
	cout << "Digite a coordenada y: "<< endl;
	cin >> ret.pI.y;
	cout << "=================================" <<endl;
	
	if ((pt.x >= ret.pS.x && pt.x <= ret.pI.x) && (pt.y <= ret.pS.y && pt.y >= ret.pI.y)) 
		cout << "O ponto est� dentro do retangulo.\n\n";
	else
		cout << "O ponto n�o est� dentro do retangulo.\n\n";
	
	return 0;
}
