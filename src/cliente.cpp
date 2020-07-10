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
            registro();
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

void Cliente::registro(){
	std::ofstream file; //arquivo 
    std::string line; // linha a ser lida
    file.open("cliente_" + std::to_string(clienteQuant - 1 )); // nome do arquivo aberto
    
    for(auto e: sacola){
		file << e.quantidade << " de " << e.nome << std::endl;
    }

    file.close();


}