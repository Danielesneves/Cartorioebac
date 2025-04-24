#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	
		//Inicio da criação de variáveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da criação de variáveis/string
		
		printf("Digite o cpf a ser cadastrado: "); //Coletando informação do usuário cpf
		scanf("%s", cpf); //%s refere-se a strnig
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das strings
		
		FILE *file; //cria o arquivo no banco de dados que é o computador
		file = fopen(arquivo, "w"); //cria o arquivo na pasta que salvamos o sistema, o "w" significa escrever
		fprintf(file, cpf); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa 
		fprintf(file, ","); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário nome
		scanf("%s", nome); //%s refere-se a strnig
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa 
		fprintf(file, nome); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa 
		fprintf(file, ","); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário sobrenome
		scanf("%s", sobrenome); //%s refere-se a strnig
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa
		fprintf(file, sobrenome);  //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa
		fprintf(file, ",");  //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário cargo
		scanf("%s", cargo); //%s refere-se a strnig
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa
		fprintf(file, cargo); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		system ("pause");
}

int consulta() //Função responsável por cconsultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da criação de variaveis/string
	char cpf[40];
	char conteudo [200];
	//final da criação de variaveis/string
	
	printf("Digite o cpf a ser consultado: "); //Coletando informações do usuário cpf consultado
	scanf("%s", cpf); //%s refere-se a strnig
	
	FILE *file; //cria o arquivo no banco de dados que é o computador
	file = fopen(cpf, "r"); //cria o arquivo na pasta que salvamos o sistema,
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não foi localizado!. \n"); //Coletando informações do usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); //Coletando informações do usuário
		printf("%s", conteudo); //%s refere-se a strnig
		printf("\n\n"); //função de pular linhas
	}
	
	system("pause");
}

int deletar() //Função responsável por cconsultar os usuários no sistema
{
	//inicio da criação de variaveis/string
	char cpf[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informações do usuário cpf deletado
	scanf("%s", cpf); //%s refere-se a strnig
	
	remove(cpf); //função de deletar
	
	FILE *file; //cria o arquivo no banco de dados que é o computador
	file = fopen(cpf, "r"); //cria o arquivo na pasta que salvamos o sistema
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n"); //Coletando informações do usuário 
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	while(laco == 1)
	{
	
		system("cls"); //Responsável por limpar a tela
		
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); // Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) //Inicio da seleção do menu
		{
			case 1:
			registro(); //Chamada de funções do registro
			break;
			
			case 2:
			consulta(); //Chamada de funções da consulta
			break;
			
			case 3:
			deletar(); //Chamada de funções de deletar
			break;
			
			default:
			printf("Essa opção não está disponível!\n"); //Coletando informações do usuário
			system("pause");
			break;
		}//fim da seleção
		

	}
	
	
	
}
