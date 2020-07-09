#ifndef CLIENTE_H
#define CLIENTE_H 

#include <iostream>
#include <vector>
#include <estabelecimento.h>
class Cliente
{
public:
	Cliente(Estabelecimento *lloja, double lsaldo);
	Estabelecimento *loja;
	double saldo;
	std::vector<std::string> sacola;

	void compra(std::string nome, double preco);
	void verSacola();
	void registro();

	static int clienteQuant;
};


#endif