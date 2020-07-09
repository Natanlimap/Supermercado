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
			bool existe = false;

			saldo -= preco;

			Produto compra =  Produto(nome, preco);

            for(auto &x: sacola){
                if(x.nome == nome && x.preco == preco){
                    existe = true;
                    x.quantidade++;
                }
            }
            if(!existe){
                sacola.push_back(compra);
            }

		}
	}else{
		std::cout << "Saldo insuficiente" << std::endl;
	}
}
void Cliente::verSacola(){
	
	for(auto e: sacola){
		std::cout << e.quantidade << " de " << e.nome << std::endl;
	}
}