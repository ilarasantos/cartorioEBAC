#include <stdio.h> // biblioteca de comunicação com o usuário. Pasta que deve ser chamada
#include <stdlib.h> // biblioteca de alocação de memória. Variável de texto ou numero SEM CARACTERES ESPECIAIS, tipo acento 
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // FILE chama a função que já existe. Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //read, apenas lê o arquivo, pois se trata da consulta
	
	if(file == NULL)
	{
		printf("Não foi possível encontrar o CPF. \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) 
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não existe no sistema. \n");
		system("pause");
		
	}
	
}


int main () 
	{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
		{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 
	
		printf ("### Cartório da EBAC ###\n\n"); 
		printf ("Escolha a opção que deseja no menu a seguir: \n\n"); 
		printf ("\t1 - Novo registro \n"); 
		printf ("\t2 - Consultar nome \n");
		printf ("\t3 - Deletar registro \n\n"); 
		printf ("\t4 - Sair do sistema \n\n");
		printf ("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazena a escolha do usuário
		
		system("cls"); //comando responsável por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1: //esses : abre uma chave
			registro(); //chama a função
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema \n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível.\n");
			system("pause");
		} //fim da seleção das opções do menu
		
		}
	}
