#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro () //Fun��o responsalvel por cadastrar os usu�rios no sistema
{
	//Inicio crida��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final crida��o de variaveis/string
	
	printf("Digite o CPF para ser cadastrado: "); //Coletando a informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsalver por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "W"); //Cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor do aquivo
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagen
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir p arquivo \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
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
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
		
	}
		
}

int main()
{
	int opcao=0; // Definindo as vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagen
	
	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio de menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o: "); //fim de menu
	
    	scanf("%d", &opcao);
	
    	system("cls"); //Responsavel por limpar a tela
    	
	    switch(opcao) //Inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada de fun�oes
		    break;
		    
		    case 2:
		    consulta();
			break;
			
			case 3:	
			deletar();
	    	break;
	    	
	    	case 4:
	    		printf("Obrigado por utilizar o sistema!\n");
	    		return 0;
	    		break;
	    	
	    	default:
	    	printf("Essa op��o n�o est� disponivel!\n"); //Fim da sele��o
         	system("pause");
         	break;
		}
   }
}
