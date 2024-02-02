#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //bibliotca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
 {
 	//in�cio da cria��o de vari�veis/string(conjunto de vari�veis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string(conjunto de vari�veis)
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo// "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" para atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: " );
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
    file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
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
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" de ler
	
	if(file == NULL)//caso a fun��o n�o exista
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while(enquanto)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		
		token = strtok(conteudo, ","); //token para pular linha. "," est� separando os nomes dentro do arquivo
		printf("CPF: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
	    token = strtok(NULL, ",");
	    printf("Sobrenome: %s\n", token);
	    
	    token = strtok(NULL, ",");
	    printf("Cargo: %s\n", token);
	}
        
	printf("\n");
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	    
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		fclose(file);
		printf("\nUsu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
        
    else if(file != NULL)
	{
		fclose(file);
		printf("\nArquivo deletado!\n\n");
		remove (cpf);
		system("pause");
    }    
        
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //laco � o nome da vari�vel
		
	for(laco=1;laco=1;) //for(fa�a) //programa sempre vai voltar ao in�cio do menu 
	{
	    system("cls"); //limpar tela
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem

        printf("   ##### Cart�rio da EBAC #####\n\n"); //In�cio do menu

        printf(" Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registro de nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Op��o:");//Fim do menu
    
        scanf("%d", &opcao); //Armazenando a escolha do usu�rio //%d n�mero inteiro
    
        system("cls"); //limpa a tela anterior depois de uma a��o
        
        switch(opcao) //Inicio da sele��o do menu
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
    		printf("Essa op��o n�o est� disponivel!\n");
    		system("pause");
    		break;
    			
		} //Fim da sele��o
    
		
    }//fim do FOR de menu
}
