#include <estabelecimento.h>

Estabelecimento::Estabelecimento()
{

	lerItens();

}


void Estabelecimento::lerItens(){

	std::ifstream file; //arquivo 
    std::string line; // linha a ser lida
    file.open("estoque.csv"); // nome do arquivo aberto
  	std::size_t found; //remove ","
  	int count = 0; //preenche os dados sequenciais
  	Produto novoProduto; //produto a ser cadastrado
	std::string aux;
  	std::stringstream stream;
  	char discard;

    if(!(file.is_open())){
        return;
    }
	getline(file, line);
    while(getline(file, line)){
    	do{
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
    				aux = line.substr(4, found-5);
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

void Estabelecimento::listar(){
	for (int i = 0; i < produtos.size(); ++i)
	{
		if(produtos[i].quantidade > 0){
			std::cout << "["<<produtos[i].codigo << "] " << produtos[i].nome << std::endl;;
			std::cout << "R$ "  << std::setprecision(10) << produtos[i].preco << std::endl;
			std::cout << produtos[i].quantidade << " em estoque" << std::endl;
			std::cout << "\n";

		}
	}
}

