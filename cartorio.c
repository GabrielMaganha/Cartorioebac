#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //bibliotca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//função responsável por cadastrar os usuários no sistema
 {
 	//início da criação de variáveis/string(conjunto de variáveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string(conjunto de variáveis)
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo// "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
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
	
	if(file == NULL)//caso a função não exista
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while(enquanto)
	{
		printf("\nEssas são as informações do usuário: \n");
		
		token = strtok(conteudo, ","); //token para pular linha. "," está separando os nomes dentro do arquivo
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	    
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		fclose(file);
		printf("\nUsuário não se encontra no sistema!\n\n");
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
	int opcao=0; //Definindo variáveis
	int laco=1; //laco é o nome da variável
		
	for(laco=1;laco=1;) //for(faça) //programa sempre vai voltar ao início do menu 
	{
	    system("cls"); //limpar tela
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem

        printf("   ##### Cartório da EBAC #####\n\n"); //Início do menu

        printf(" Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registro de nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Opção:");//Fim do menu
    
        scanf("%d", &opcao); //Armazenando a escolha do usuário //%d número inteiro
    
        system("cls"); //limpa a tela anterior depois de uma ação
        
        switch(opcao) //Inicio da seleção do menu
        {
        	case 1:
        	registro();//chamada de funçôes
    	    break;
    	    
    	    case 2:
    	    consulta(); 
        	break;
        	
        	case 3:
			deletar();
    		break;
    		
    		default:
    		printf("Essa opção não está disponivel!\n");
    		system("pause");
    		break;
    			
		} //Fim da seleção
    
		
    }//fim do FOR de menu
}
