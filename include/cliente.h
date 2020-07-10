#ifndef CLIENTE_H
#define CLIENTE_H 

#include <iostream>
#include <vector>
#include <estabelecimento.h>
#include <produto.h>
#include <fstream>

class Cliente
{
public:
	Cliente(Estabelecimento *lloja, double lsaldo);
	Estabelecimento *loja;
	double saldo;
	std::vector<Produto> sacola;

	void compra(std::string nome, double preco);
	void verSacola();
	void registro();

	static int clienteQuant;
};


#endif