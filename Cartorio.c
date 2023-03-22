#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço de memoria
#include <locale.h>// biblioteca de alocações de texto por região
#include <string.h>// biblioteca responsavel por cuidr das string

int registro()//função reponsavel por cadastrar os ususarios no sistea
{
	  //inicio criação de variaveis/strings
	  char arquivo[40];
	  char cpf[40];
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	  //final da criação de variaveis
	  
	  printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuario
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
	  	   printf("Arquivo não localizado!.\n");
	  }	
	  
	  while(fgets(conteudo, 200, file) != NULL)
	  {
	  	printf("\nEssas são as informações do usuario: ");
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
	   	printf("O usuário não se encontra no sistema!.\n");
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
	    printf("### Cartório da EBAC ###\n\n");//começo do menu
	    printf("Escolha a opção desejada no menu:\n\n");
	    printf("\t1 - registrar nomes\n");// o \t123 vai dar espaçamento
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n");
	    printf("opção:");//fim do menu
	
	    scanf("%d", &opcao);
	
	    system("cls");//responsavel por limpar atela
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();//chamada de funções
			break;
			
			case 2:	
			consulta();
		    break;
		    
		    case 3:
		    deletar();
			break;
			
			default:
			printf("essa opção não está disponivel\n");
	    	system("pause");
			break;	
		}
	
	
	}
}

