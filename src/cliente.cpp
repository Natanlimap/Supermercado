#include <cliente.h>

int Cliente::clienteQuant;

Cliente::Cliente(Estabelecimento *lloja, double lsaldo){
	this->saldo = lsaldo;
	this->loja = lloja;
	clienteQuant++;
}

void Cliente::compra(std::string nome, double preco){
	if(saldo > preco){
		if(loja->venda(nome, preco)){
			saldo -= preco;
			sacola.push_back(nome);
		}
	}else{
		std::cout << "Saldo insuficiente" << std::endl;
	}
}
void Cliente::verSacola(){
	
	for(auto e: sacola){
		std::cout << e <<std::endl;
	}
}