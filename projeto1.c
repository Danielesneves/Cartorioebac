#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
		//Inicio da cria��o de vari�veis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da cria��o de vari�veis/string
		
		printf("Digite o cpf a ser cadastrado: "); //Coletando informa��o do usu�rio cpf
		scanf("%s", cpf); //%s refere-se a strnig
		
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
		
		FILE *file; //cria o arquivo no banco de dados que � o computador
		file = fopen(arquivo, "w"); //cria o arquivo na pasta que salvamos o sistema, o "w" significa escrever
		fprintf(file, cpf); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa 
		fprintf(file, ","); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio nome
		scanf("%s", nome); //%s refere-se a strnig
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa 
		fprintf(file, nome); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa 
		fprintf(file, ","); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio sobrenome
		scanf("%s", sobrenome); //%s refere-se a strnig
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa
		fprintf(file, sobrenome);  //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa
		fprintf(file, ",");  //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio cargo
		scanf("%s", cargo); //%s refere-se a strnig
		
		file = fopen(arquivo, "a"); //cria o arquivo na pasta que salvamos o arquivo, o "a" significa
		fprintf(file, cargo); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		system ("pause");
}

int consulta() //Fun��o respons�vel por cconsultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de variaveis/string
	char cpf[40];
	char conteudo [200];
	//final da cria��o de variaveis/string
	
	printf("Digite o cpf a ser consultado: "); //Coletando informa��es do usu�rio cpf consultado
	scanf("%s", cpf); //%s refere-se a strnig
	
	FILE *file; //cria o arquivo no banco de dados que � o computador
	file = fopen(cpf, "r"); //cria o arquivo na pasta que salvamos o sistema,
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o foi localizado!. \n"); //Coletando informa��es do usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Coletando informa��es do usu�rio
		printf("%s", conteudo); //%s refere-se a strnig
		printf("\n\n"); //fun��o de pular linhas
	}
	
	system("pause");
}

int deletar() //Fun��o respons�vel por cconsultar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/string
	char cpf[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��es do usu�rio cpf deletado
	scanf("%s", cpf); //%s refere-se a strnig
	
	remove(cpf); //fun��o de deletar
	
	FILE *file; //cria o arquivo no banco de dados que � o computador
	file = fopen(cpf, "r"); //cria o arquivo na pasta que salvamos o sistema
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //Coletando informa��es do usu�rio 
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	while(laco == 1)
	{
	
		system("cls"); //Respons�vel por limpar a tela
		
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); // Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) //Inicio da sele��o do menu
		{
			case 1:
			registro(); //Chamada de fun��es do registro
			break;
			
			case 2:
			consulta(); //Chamada de fun��es da consulta
			break;
			
			case 3:
			deletar(); //Chamada de fun��es de deletar
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n"); //Coletando informa��es do usu�rio
			system("pause");
			break;
		}//fim da sele��o
		

	}
	
	
	
}
