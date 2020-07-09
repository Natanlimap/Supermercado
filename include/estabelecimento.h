#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H 

#include <iostream>
#include <string>
#include <vector>
#include <produto.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>     /* atof */    
#include <iomanip> 

class Estabelecimento
{
public:

	Estabelecimento();

	void listar();
	void venda();
	void caixa();


private:

	std::vector<Produto> produtos;
 	
 	void lerItens();
 	void salvarItens();

};

#endif