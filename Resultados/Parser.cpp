/*
Compilando: g++ -o parser Parser.cpp -std=c++11
Executando: ./parser arq_entrada.txt variavel_saida
Arquivo de saida em: parsed.cpp
Cândido Signorini Moraes 
Outubro/2018
*/

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <map>

using namespace std;
std::map <string,int>Mapa;

int main (int argc, char *argv[]){
	ifstream C50;
	ofstream Parser,CriaArquivo;
	fstream temp;
	string arquivo_saida,linha,variavel,valor,condicao,resultado,proximo="IF";
	char arquivo[100],variavelC[100];
	int tabulacao=0,qtd_tokens=0,pos_buffer=0,pos_2pontos=0,aux=0,lixo=0;
	vector<string> tokens;
	regex expressao { "[\\s:.]" };	//Separa os tokens em ":", "." e espaco
	strcpy(arquivo,argv[1]);			
	strcpy(variavelC,argv[2]);
	string arquivo_entrada(arquivo);			
	C50.open(arquivo);
	arquivo_saida = arquivo_entrada.substr(0,arquivo_entrada.length()-4);
	Parser.open(arquivo_saida+"_parsed.cpp");
	CriaArquivo.open("temp.txt"); 
	CriaArquivo.close(); // Para criar arquivo somente no modo ofstream e eu preciso do arquivo in/out
	temp.open("temp.txt");
	Mapa.clear();

	printf("1\n");

	if(C50.is_open()){
		while(linha !="Decision tree:"){  // O que importa está a partir desta linha
			getline(C50,linha);  
		}
		getline(C50,linha); // Comer espaço
		getline(C50,linha); // Ler primeira linha
		while(linha.size()!=0){
			temp << linha << endl; // Copia texto para arquivo temporário de leitura/escrita
			getline(C50,linha);
		}
		temp.seekg(0); // Retorna ponteiro do arquivo temp para o inicio
		getline(temp,linha); // Lê linha

		printf("2\n");

		do{											
			sregex_token_iterator tokens_begin { linha.begin(), linha.end(), expressao, -1 };
			auto tokens_end = sregex_token_iterator {};
   			for (auto token_it = tokens_begin; token_it != tokens_end; token_it++){
	      		if(*token_it>=48){ // Em ascii, pega somente numeros e letras
	      			tokens.push_back(*token_it); // Separa em tokens
	      			qtd_tokens++;	      					
	      		}
   			}	
   			variavel = tokens[0]; // Atribui tokens
	      	condicao = tokens[1];
	      	valor = tokens[2];
	      	if (qtd_tokens>3){
	      		resultado = tokens[3];	      				
	      	}
	
     		tokens.clear(); // Apaga conteudo dos tokens da linha
      		qtd_tokens=0;
      		pos_buffer=temp.tellg(); // Guarda ponteiro para antes da leitura da linha. Importante depois
       		getline(temp,linha); // Obtem proxima linha      		

			// *** linha atual ***   			
   			if(proximo=="IF") { // proximo = linha tual
   				for(int i=0;i<tabulacao;i++) // Organiza identaçao	  				
   					Parser << "	";
   				Parser << "if (" << variavel << condicao << valor << ") {" << endl;
   			}
   			else if(proximo=="ELSE"){
   				for(int i=0;i<tabulacao;i++) 	  				
   					Parser << "	";
	       		Parser << "else {" << endl;			       				
   			}
	      	if (resultado=="no"){ // Se for falso atribui 0, se for verdadeiro atribui 1
	 			for(int i=0;i<tabulacao+1;i++) 
	      			Parser << "	";
		       	Parser << variavelC << "=" << "0;" << endl;		       			
		    }
	       	else if(resultado=="yes"){
	       		for(int i=0;i<tabulacao+1;i++) 
	      			Parser << "	";
		       	Parser << variavelC << "=" << "1;" << endl;
	       	}
	       	proximo='\0';
	       	resultado='\0';

		     // *** proxima linha ***
	       	 if(Mapa.find(linha)->first==linha && Mapa.size()>0 && linha.length()>1){ // Comparar linha atual com string armazenada no mapa
	       	 // Caso 1: Linha atual é a linha que fecha o if e abre o else (:)
	       	 	for(int i=0;i<tabulacao-Mapa.find(linha)->second;i++){
					for(int j=i;j<tabulacao;j++) // Fechar "{" abertos
						Parser << "	";				
				Parser << "}" << endl;
				}	
       			for(int i=0;i<Mapa.find(linha)->second;i++)
	       	 		Parser << "	";
	       	 	Parser << "}else {"<< endl;
	       	 	tabulacao=Mapa.find(linha)->second; // Atualiza tabulação
	       	 	Mapa.erase(Mapa.find(linha)->first); // Apaga linha do mapa				       					      		    		
	       	}
	       	else if(linha.find(":...")!=-1) { 
	       	// Caso 2: Proxima linha começa com ":..." (if) */
	       		proximo="IF";	       		 	       		
	       		tabulacao++;
	       	}
	       	else if(linha.find(" :")!=-1 || linha.find(":")==0) { 
	       	// Caso 3: Proxima linha começa com ":" (Chave)
	       		pos_2pontos=linha.find(" :");
	       		if(pos_2pontos==-1)  
	       			pos_2pontos=0; // Quando está na primeira posição (0), ele não acha pela primeira pesquisa ("   :"),apenas pela segunda busca(":") 
	       		temp.seekg(pos_buffer); // Retorna ponteiro para antes da linha lida para ser substituida por linha sem ":"
	       		while(linha.find(":")==pos_2pontos || linha.find(" :")==pos_2pontos){ // Retira os ":" das linhas
	       			aux=temp.tellg(); // Guarda ponteiro buffer 
	       			getline(temp,linha); 
	       			temp.seekg(aux); // Restaura ponteiro buffer
	       			//Como vai substituir linha atual tem que voltar ponteiro para sobreescrever a linha atual, não a proxima 
	       			lixo=linha.length(); // Tamanho da linha antiga. Nova linha é menor e deve ter seu conteúdo sobreescrito para não deixar lixo     			   			
	       			temp.seekg(aux);	       			       			
	       			linha = linha.substr(pos_2pontos+1,-1); // Retira ":" da linha
	       			temp << linha;// << endl; // Escreve nova linha no arquivo texto temporario
	       			for(int i=0;i<lixo-linha.length();i++)
	       				temp << " "; // Tira lixo da linha
	       			temp <<"\n";
	       			aux=temp.tellg();
	       			getline(temp,linha);
	       			temp.seekg(aux);	       				       			
	       		}
	       		pos_2pontos=linha.find(" :"); // linha atual também deve ter ":" retirados
	       		lixo=linha.length();
	       		if(pos_2pontos==-1){
	       			if(linha.find(":")==0)
	       				pos_2pontos=0;	
	       		}  	       			       		
	       		if(pos_2pontos>=0){
					linha = linha.substr(pos_2pontos+1,-1); // Retira ":" da linha
	       			temp << linha;
	       			for(int i=0;i<lixo-linha.length();i++)
	       				temp << " "; // Tira lixo da linha
	       			temp <<"\n";
	       		}
	       		Mapa.insert(pair<string,int>(linha,tabulacao-1)); // Insere no Mapa a linha de fechamento do if(:) e a tabulação do momento
	       		temp.seekg(pos_buffer); // Restaura posição ponteiro arquivo
	       		}
    			else if(linha.length()==0){
    				// Há uma linha em branco após as arvores e o conteúdo depois não nos interessa mais
    			}
      			else { 
      			// Caso 4: else
      				proximo="ELSE";
      				for(int i=0;i<tabulacao;i++) // Antes de escrever proxima linha deve se fechar o "}" do if
   						Parser << "	";			       			
       				Parser << "}" << endl;
       			}      			      			
	    }while(!temp.eof());
	    tabulacao++; // O primeiro IF não cai no teste de if, e portanto o incremento da tabulação não é contabilizada
		for(int i=0;i<tabulacao;i++){
			for(int j=i;j<tabulacao-1;j++) // Fechar "{" abertos
				Parser << "	";				
			Parser << "}" << endl;
		}
		printf("3\n");
	}
	else
		cout << "Erro na abertura do arquivo" << endl;
	C50.close(); // Fecha os arquivos
	Parser.close();
	temp.close();
	remove("temp.txt"); // Deleta arquivo temporario
	return 0;
} 
