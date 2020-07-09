#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H 

#include <iostream>
#include <string>
#include <vector>
#include <list>

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
	bool venda(std::string codigo);
	bool venda(std::string nome, double preco);

	void caixa();
	std::list<Produto> produtos;


	private:

	std::list<Produto> vendas;

	std::string converteParaCodigo(std::string nome,double preco);

 	void lerItens();
 	void salvarCaixa();
 	void escreverArquivo(std::string filename, std::list<Produto> lista);
};

#endif