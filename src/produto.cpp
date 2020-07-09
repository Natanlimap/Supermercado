#include <produto.h>

Produto::Produto()
{

}
Produto::Produto(std::string rnome, double rpreco)
{

	this->nome = rnome;
	this->preco = rpreco;
	this->quantidade = 1;
}
