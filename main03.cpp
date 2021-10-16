#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <cstring>

using namespace std;

typedef struct funcionario{
	int idFunc = 0;
	float salario;
	string nome;
	string departamento;
	string cargo;
}f;
	
typedef struct cargo{
	int idCargo;
	string nomeCargo;
}c;

typedef struct departamento{
	int idDepart;
	string nomeDepart;
}d;

// limpa a tela do console
void limpaTela(void) {
	system("cls");
}

int menu() {
	limpaTela();

	int op;

	// Menu principal
		cout << "\n ======== CADASTROS ========" << endl;
		cout << " 1 - Cadastrar Funcionário" << endl;
		cout << " 2 - Cadastrar Departamento" << endl;
		cout << " 3 - Cadastrar Cargo" << endl;
		cout << " 4 - Imprimir Cadastros" << endl;
		cout << " 5 - Sair" << endl;
		cout << " ==========================" << endl;

		cout << "\n Digite a opção desejada:\n";
		cin >> op;
	return op;
}

// função para cadastro de funcionario
void cadastrarFunc(f* arrayFunc, int qtdFunc) {
	
	cout << "\n ====== CADASTRAR FUNCIONÁRIO ====== \n\n";
	for(int i=0; i < qtdFunc; i++){
		cout << "Digite o id: " << endl;
		cin >> arrayFunc[i].idFunc;

		cout << "Digite o nome:" << endl;
		cin >> arrayFunc[i].nome;

		cout << "Digite o salário: " << endl;
		cin >> arrayFunc[i].salario;

		cout << "Digite o cargo: " << endl;
		cin >> arrayFunc[i].cargo;

		cout << "Digite o departamento: " << endl;
		cin >> arrayFunc[i].departamento;
	}
}

// função para cadastro de departamento
void CadastrarDep(d* arrayDep, int qtdDep) {
	cout << "\n ====== CADASTRAR DEPARTAMENTO ====== \n\n";
	for(int i=0; i < qtdDep; i++){

		cout << "Digite o id:" << endl;
		cin >> arrayDep[i].idDepart;

		cout << "Digite o nome do departamento: " << endl;
		cin >> arrayDep[i].nomeDepart;
		cout << " ===================================" << endl;	
	}
}

// função para cadastro de departamento
void CadastrarCargo(c* arrayCargo, int qtdCargo) {
	cout << "\n ====== CADASTRAR CARGO ====== \n\n";
	for(int i=0; i < qtdCargo; i++){

		cout << "Digite o id:" << endl;
		cin >> arrayCargo[i].idCargo;

		cout << "Digite o nome do departamento: " << endl;
		cin >> arrayCargo[i].nomeCargo;
	}
}

// função de impressão de todos os convidados
void lista(f *arrayFunc, int qtdFunc) {
	cout << "====== FUNCIONÁRIOS CADASTRADOS ====== \n\n" ;

	for(int i = 0; i < qtdFunc; i++) {
		cout << "ID: "<< arrayFunc[i].idFunc << " | " ;
		cout << "Nome: " << arrayFunc[i].nome << " | " ;
		cout << "Salário: R$" << arrayFunc[i].salario << " | " ;
		cout << "Cargo " << arrayFunc[i].cargo  << " | " ;
		cout << " Departamento: " << arrayFunc[i].departamento << " | \n \n" ;
		cout << " ====================================================" << endl;
	}

	cout << "\n ================= FIM DA LISTA ================= \n\n";
}


int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	string resposta;
	int qtdFunc, qtdDep, qtdCargo, opcao;
	
	cout << "Quantos funcionários deseja cadastrar?" << endl;
	cin >> qtdFunc;
	
	f arrayFunc[qtdFunc];
	
	cout << "Quantos cargos deseja cadastrar? " << endl;
	cin >> qtdCargo;
	c arrayCargo[qtdCargo];
	
	
	cout << "Quantos departamentos deseja cadastrar?" << endl;
	cin >> qtdDep;
	d arrayDep[qtdDep];	
	
	do{
		limpaTela();
		opcao = menu();
		
		switch(opcao) {
		case 1:{
			limpaTela();
			cadastrarFunc(arrayFunc, qtdFunc);
				
			break;
		}

			case 2:
				limpaTela();
				CadastrarDep(arrayDep, qtdDep);
			break;
	
			case 3:
				limpaTela();

				CadastrarCargo(arrayCargo, qtdCargo);
			break;
		
			case 4:{
				limpaTela();
				lista(arrayFunc, qtdFunc);
				break;
			}

			case 5:
				limpaTela();
				cout << "\n Obrigado por utilizar nosso aplicativo!\n\n";
				return 0;
			break;
	
		}
		cout << "Deseja Continuar? (S/N)" << endl;
		cin >> resposta;
		cout << endl;
	
		system("pause");
	} while(resposta == "S" || resposta == "s");	
}
