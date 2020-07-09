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
	
	while(1){
	
		std::cout << "1 - compra, 2 - listar estoque, 3 - listar sacola, Finalizar compra " << std::endl;
		std::cin >> action;
		if(action == 0){
			std::cout << "Insira o saldo do novo cliente" << std::endl;
			std::cin >> novoSaldo;
			a =  Cliente(&teste, novoSaldo);
		}
		switch(action){
			
			case 1: 
				
				std::cin >> produto;
				std::cin >> preco;
				a.compra(produto, preco);
				break;
			case 2:
				teste.listar();
			case 3:
				a.verSacola();

		}
	}
	return 0;
}