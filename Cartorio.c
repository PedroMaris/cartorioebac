#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o de memoria
#include <locale.h>// biblioteca de aloca��es de texto por regi�o
#include <string.h>// biblioteca responsavel por cuidr das string

int registro()//fun��o reponsavel por cadastrar os ususarios no sistea
{
	  //inicio cria��o de variaveis/strings
	  char arquivo[40];
	  char cpf[40];
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	  //final da cria��o de variaveis
	  
	  printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
	  scanf("%s", cpf);//responsavel por armazenar as strings
	  
	  strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	  
	  FILE *file; //cria o arquivo
	  file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa write
	  fprintf(file,cpf); //salva o valor da variavel
	  fclose(file); // fecha o arquivo
	  
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
	  scanf("%s",cargo);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file,cargo);
	  fclose(file);
	  	  
	  system("pause");
}

int consulta()
{
	  setlocale(LC_ALL,"portuguese");// definindo a linguage
	  
      char cpf[40];
	  char conteudo[200];
	  
	  printf("Digite o CPF a ser consultado: ");
	  scanf("%s",cpf);
	  
	  FILE *file;
	  file = fopen(cpf,"r");
	  
	  if(file == NULL)
	  {
	  	   printf("Arquivo n�o localizado!.\n");
	  }	
	  
	  while(fgets(conteudo, 200, file) != NULL)
	  {
	  	printf("\nEssas s�o as informa��es do usuario: ");
	  	printf("%s", conteudo);
	  	printf("\n\n");
	  }
	  
	  system("pause");
}

int deletar()

{
	   char cpf[40];
	   
	   printf("Digite o cpf do usuario a ser deletado: ");
	   scanf("%s",cpf);
	   
	   remove(cpf);
	   
	   FILE *file;
	   file = fopen(cpf,"r");
	   
	   if(file == NULL)
	   {
	   	printf("O usu�rio n�o se encontra no sistema!.\n");
	   	system("pause");
	   }
}

int main()
    {
	int opcao=0;// deinindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
	    setlocale(LC_ALL,"portuguese");// definindo a linguage
	    printf("### Cart�rio da EBAC ###\n\n");//come�o do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - registrar nomes\n");// o \t123 vai dar espa�amento
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n");
	    printf("op��o:");//fim do menu
	
	    scanf("%d", &opcao);
	
	    system("cls");//responsavel por limpar atela
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();//chamada de fun��es
			break;
			
			case 2:	
			consulta();
		    break;
		    
		    case 3:
		    deletar();
			break;
			
			default:
			printf("essa op��o n�o est� disponivel\n");
	    	system("pause");
			break;	
		}
	
	
	}
}

