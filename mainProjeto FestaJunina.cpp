		#include <iostream>
		#include <locale>
		#include <string>
		#include <stdlib.h>		
		
/* PROJETO “FESTA JUNINA”
* Criar um projeto em linguagem C++ para gerenciar os convidados
* para sua Festa Junina. O programa deve permitir ao usuário realizar as seguintes tarefas:
* Incluir um novo convidado (Nome, Telefone, Prato) 
* Pesquisar pelo nome 
* Imprimir a lista de convidados O projeto deverá conter as seguintes características: 
* Um Menu com as opções acima (Utilizar Switch/Case).
* Os dados devem ser armazenados em uma Matriz.
* A quantidade de linhas(convidados) da matriz deve ser definida pelo usuário.
* O sistema deve verificar se a lista de convidados(matriz) está cheia antes de cadastrar um novo contato
* Crie uma função com o nome de Lista_Cheia().
* O sistema deve verificar se o Prato já existe na lista e se existir mostrar uma mensagem.
* Crie uma função com o nome de Consulta_Prato().
* O Menu deve apresentar uma opção SAIR que finalizará o sistema.
*/		
		using namespace std;
		
		int quantidadeConvidados;
		int codConvidado;
		int contadorConvidados;
		int op;		
		
		string listaConvidados[2000][3];
		
		bool lista_cheia(){
			if(contadorConvidados < quantidadeConvidados){
				return false;
			}else{
				return true;
			}
			return lista_cheia();
		}
		
		bool consulta_prato(string consulta_prato){
			
			bool verificacao;
			
			for(int i=0; i< codConvidado; i++){
				if(consulta_prato == listaConvidados[i][2]){
					cout << "Não pode cadastrar prato já cadastrado!" << endl;
					verificacao = true;
				}else{
					verificacao = false;
				}
			}
			return verificacao;		
		}
		
		void adicionarConvidado(){
			char resposta;
			
		do{			
			if(lista_cheia() == false){
				system("cls");	
				cin.ignore();	
				cout << "******* Adicionar novo convidado *******" << endl;
				cout << "Digite o nome:" << endl;
				getline(cin, listaConvidados[codConvidado][0]);
				cout << "Digite o telefone: " << endl;
				getline(cin, listaConvidados[codConvidado][1]);
			
				do{
					cout << "Digite o prato que o convidado irá levar: "<< endl;
					getline(cin, listaConvidados[codConvidado][2]);
				}while(consulta_prato(listaConvidados[codConvidado][2]) != false);
				
				contadorConvidados++;
				codConvidado++;
			
				if(lista_cheia() == false){
					cout << "Deseja cadastrar novo convidado? s/n" << endl;
					cin >> resposta;				
				}
					
			} else{
					cout << "A lista está cheia." << endl;
					cout << "| #USEMÁSCARA |" << endl;
					resposta= 'N';
			}
		
			}while( toupper(resposta) =='S');
		}
		
		void pesquisarConvidado(string nomeConvidado){
			
			string nome;
					for(int i=0; i< quantidadeConvidados; i++){
					int encontraConvidado = listaConvidados[i][0].find(" ");
					nome = listaConvidados[i][0].substr(0,encontraConvidado);			
				
					if(nome == nomeConvidado){
						cout << "Nome do cidadão: " << listaConvidados[i][0] << endl;						
						cout << "Telefone: " << listaConvidados[i][1] << endl;
						cout << "Prato: " << listaConvidados[i][2] << endl;
						
						break;
					}
					else{
						cout << "Nome não encontrado " << endl;
					}	
				}
		}
		
		void processarDadoDeEntrada(){
			
			string nomeConvidado;
			char resposta;
			
		do{
			cout << "Qual nome deseja pesquisar?" << endl;
			cin >> nomeConvidado;
		
			pesquisarConvidado(nomeConvidado);
			
			cout << "Deseja realizar nova pesquisa? s/n" << endl;
			cin >> resposta;
		
			}while(toupper(resposta) == 'S');		
		}
		
		void imprimirConvidado(){
			
				for(int i=0; i< quantidadeConvidados; i++){
				cout << "********** Convidado "<< i+1 <<" **********" << endl;
				cout <<"Nome: " << listaConvidados[i][0] <<endl;
				cout <<"Telefone: " << listaConvidados[i][1] << endl;
				cout <<"Prato: " << listaConvidados[i][2] << endl;
				cout << "******************************" << endl;	
				}					
		}
		
		void sair(){
			cout << "Obrigada por utilizar nosso app :D";
			exit(3);	
		}
		
		int menu(){
					cout << "************ ARRAIÁ DSM 2021 *************" << endl;
					cout << "| 1 - Adicionar novo convidado		 |" << endl;
					cout << "| 2 - Pesquisar                          |" << endl;
					cout << "| 3 - Imprimir lista                     |" << endl;
					cout << "| 4 - Sair                               |" << endl;
					cout << "******************************************" << endl;					
					
					cout << "Digite a opção desejada:" << endl;
					cin >> op;
					
			return op;		
		}
		
		int main() {	
			setlocale(LC_ALL,"Portuguese");
			
			system("cls");
			
			if(op == 0){
				cout << "Quantos convidados estarão presentes na festa? " << endl;
				cin >> quantidadeConvidados;
			}
			
			menu();
			
			switch(op){
				
				case 1:
					adicionarConvidado();
				break;
				
				case 2:
					processarDadoDeEntrada();		
				break;
				
				case 3:
					imprimirConvidado();		
				break;
				
				case 4:
					sair();
				break;				
			}
			system("pause");	
			return main();
		}
