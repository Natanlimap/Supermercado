#include <estabelecimento.h>

Estabelecimento::Estabelecimento()
{
	
	lerItens();

}


void Estabelecimento::lerItens()
{

	std::ifstream file; //arquivo 
    std::string line; // linha a ser lida
    file.open("estoque.csv"); // nome do arquivo aberto
  	std::size_t found; //remove ","
  	int count = 0; //preenche os dados sequenciais
  	Produto novoProduto; //produto a ser cadastrado
	std::string aux;
  	std::stringstream stream;
  	char discard;

    if(!(file.is_open()))
    {
        return;
    }
	getline(file, line);
    while(getline(file, line))
    {
    	do
    	{
    		found = line.find_first_of(",");

    		switch(count){
    			
    			case 0:
    				novoProduto.codigo = line.substr(0, found);
    				line = line.substr(found + 1, std::string::npos);
    				count++;

    				break;
    			
    			case 1:
    			    found = line.find_first_of(",");
    				novoProduto.nome = line.substr(0, found);
    				line = line.substr(found + 1, std::string::npos);
    				count++;
    				break;
    			
    			case 2:
    			    found = line.find_first_of(",");
    				novoProduto.unidadeMedida = line.substr(0, found);
    				line = line.substr(found + 1, std::string::npos);
    				count++;
    				break;
    			
    			case 3:
    			    found = line.find_first_of(",");
    				stream.clear();
    				aux = line.substr(3, found-3);
    				stream << aux;
    				stream >> novoProduto.preco;
    				line = line.substr(found+1, std::string::npos);
    				count++;
    				break;
    			
    			case 4:
    			    found = line.find_first_of(",");
					stream.clear();
    				stream << line;
    				stream >> novoProduto.quantidade;
    				count = 0;
    				produtos.push_back(novoProduto);
    				
    				break;


    		}

    	}while(found!=std::string::npos);


    }

}

void Estabelecimento::listar()
{
	for(auto e: produtos){
		if(e.quantidade > 0)
		{
			std::cout << "["<<e.codigo << "] " << e.nome << std::endl;;
			std::cout << "R$ "  << std::fixed<< std::setprecision(2) << e.preco << std::endl;
			std::cout << e.quantidade << " em estoque" << std::endl;
			std::cout << "\n";
		}

	}

}


bool Estabelecimento::venda(std::string codigo)
{
    bool existe = false;
	
    for(auto &e: produtos){
	
    	if(codigo == e.codigo && e.quantidade > 0)
		{
            Produto produtoVendido = e;
            produtoVendido.quantidade = 1;
			e.quantidade--; 

            existe = false;

            for(auto &x: vendas){
                if(x.codigo == codigo){
                    existe = true;
                    x.quantidade++;
                }
            }
            if(!existe){
                vendas.push_back(produtoVendido);
            }

            escreverArquivo("caixa.csv", vendas);
            escreverArquivo("estoque.csv", produtos);
			std::cout << "Venda efetuada" << std::endl;
			return true;
		}
	}
    std::cout << "Produto nao encontrado ou estoque esgotado" << std::endl;

    return false;


}

bool Estabelecimento::venda(std::string nome, double preco){
    if(venda(converteParaCodigo(nome, preco))){
        return true;
    }
    return false;
}

std::string Estabelecimento::converteParaCodigo(std::string nome, double preco){
    for(auto e: produtos){
        if(nome == e.nome && preco == e.preco){
            return e.codigo;
        }
    }
}



void Estabelecimento::escreverArquivo(std::string filename, std::list<Produto> lista){
	std::ofstream file; //arquivo 
    std::string line; // linha a ser lida
    file.open(filename); // nome do arquivo aberto
    file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

    for(auto e: lista){
    	file << e.codigo << ","<< e.nome  <<","<< e.unidadeMedida << ",R$ " <<e.preco << "," << e.quantidade << std::endl;
    }

    file.close();

}

