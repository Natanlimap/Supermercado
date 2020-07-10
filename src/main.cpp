#include <iostream>
#include <estabelecimento.h>
#include <string>
#include <cliente.h>
int main(int argc, char const *argv[])
{
	Estabelecimento teste;
	Cliente a(&teste, 200.00);
	int action;
	std::string produto;
	double preco, novoSaldo;

	std::cout << "Insira o saldo do primeiro cliente" << std::endl;	
	std::cin >> novoSaldo;
	a =  Cliente(&teste, novoSaldo);


	while(1){
	
		std::cout << "1 - compra, 2 - listar estoque, 3 - listar sacola, 0 - Finalizar compra " << std::endl;
		std::cin >> action;
	
		if(action == 0){
			std::cout << "Compra finalizada" << std::endl;
			std::cout << "Deseja adicionar outro cliente? Caso sim digite 4" << std::endl;
			std::cin >> action;
			if(action != 4){
				break;
			}
			std::cout << "Insira o saldo do novo cliente" << std::endl;
			std::cin >> novoSaldo;
			a =  Cliente(&teste, novoSaldo);
			std::cout << "1 - compra, 2 - listar estoque, 3 - listar sacola, Finalizar compra " << std::endl;
			std::cin >> action;

		}
		switch(action){
			
			case 1: 
				
				std::cin >> produto;
				std::cin >> preco;
				a.compra(produto, preco);
				break;
			case 2:
				teste.listar();
				break;
			case 3:
				a.verSacola();
				break;
			default:
				std::cout << "Opcao incorrenta, tente novamente" << std::endl;
				break;
		}

	}
	return 0;
}