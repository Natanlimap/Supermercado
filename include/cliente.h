#ifndef CLIENTE_H
#define CLIENTE_H 

#include <iostream>
#include <vector>

class Cliente
{
public:
	Cliente();
	~Cliente();
	
	float saldo;
	std::vector<std::string> sacola;

	void compra();
	void verSacola();
	void registro();
	
};


#endif