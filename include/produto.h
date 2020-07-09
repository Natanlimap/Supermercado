#ifndef PRODUTO_H
#define PRODUTO_H 

#include <iostream>

#include <string>

class Produto{
	public:
	
		Produto();
		std::string nome;
		std::string codigo;
		double preco;
		int quantidade;
		std::string unidadeMedida;

};

#endif