#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloc��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro(){
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser registrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a uma string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" serve para voc� escrever
	fprintf(file,cpf); // salva o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" serve para adicionar algo ao arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser registrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser registrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file); //importante para por o que tu quer por na area em branco
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //importante para por a v�rgula
	
	printf("Digite o cargo a ser registrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){
	  setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" serve para ler o arquivo
	
	if(file == NULL){
		printf("N�O foi possivel consultar arquivo.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
    char cpf[40];
    printf("Digite o CPF do us�rio a ser DELETADO: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL){
    	printf("Usu�rio N�O se encontra no sistema.\n");
    	system("pause");
	}
    
}

int main(){
	int opcao=0; //definindo vari�veis
	int x=1;
	
	for(x=1;x=1;){
	
	system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem	
	   printf("=> Cart�rio da EBAC <=\n\n"); 
	   printf("Escolha a op��o desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - DELETAR nomes\n");
	   printf("\t4 - SAIR\n\n");
	   printf("Op��o:");
	
	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	system("cls"); //responsavel por limpar o sistema
	
	switch(opcao){
		case 1:
		registro();
	    break;
	    
	    case 2:
	    consulta();
    	break;
    	
    	case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por usar.\n\n");
		printf("Aperte ENTER\n");
		return 0;
		break;
        
		default:
		printf("Essa op��o N�O est� disponivel!!!\n"); //sele��es
	    system("pause");	
    	break;	
	 }
	
  
   }


}
