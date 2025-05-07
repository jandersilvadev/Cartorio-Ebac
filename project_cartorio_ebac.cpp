#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

//Definindo fun��es para deixar simplificado no c�digo
int registro(){ //Fun��o respons�vel por registrar e armazenar os dados do usu�rio
	
	//Definindo a linguagem que ser� utilizada no c�digo para podermos utilizar pontua��es Importante> Lembre sempre de acrescentar a bibl�oteca! <locale.h>
	setlocale(LC_ALL, "Portuguese");
	
	//Inserindo v�riaveis/strings no c�digo
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da inser��o de v�riaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Questionando o usu�rio de qual ser� o CPF cadastrado
	scanf("%s", &cpf); //Recebendo a resposta do usu�rio
	
	strcpy(arquivo, cpf); //Respons�vel por copiar o valor da string cpf para a string arquivo
	
	FILE *file; //Um (*) � uma vari�vel que guarda o endere�o de mem�ria de outra vari�vel.
	file = fopen(arquivo, "w"); //Entra dentro da file e transforma a string/v�riavel "arquivo" em uma pasta com o ("w") w - ( criar )

		
	fprintf(file, cpf); //Salva o valor da variavel "CPF" dentro do arquivo 
	fclose(file); //Fecha a file (arquivo)
	
	file = fopen(arquivo, "a"); //Entra dentro da e informa que ir� adicionar mais uma informa��o a string/v�riavel chamada arquivo com o ("a") a - ( atualizar )
	fprintf(file, ","); //Adiciona uma virgula para deixar o c�digo mais organizado
	fclose(file); //Fecha a file
	
	printf("Digite o nome a ser cadastrado: "); //Questionando o usu�rio qual ser� o NOME cadastrado
	scanf("%s", &nome); //Recebendo a resposta do usu�rio
	
	file = fopen(arquivo, "a");	//Entra dentro da file e informa que vai adicionar mais uma informa��o ao arquivo ("a")
	fprintf(file, nome); //Adicionando a v�riavel NOME dentro da file
	fclose(file); //Fecha a file
	
	file = fopen(arquivo, "a"); //Entra dentro da file e informa que vai adicionar outra informa��o a string arquivo ("a")
	fprintf(file, ","); //Adiciona novamente uma v�rgula para deixar o c�digo mais limpo
	fclose(file); //Fecha a file
	
	printf("Digite o sobrenome a ser cadastrado: "); //Questionando o usu�rio qual SOBRENOME ser� cadastrado
	scanf("%s", &sobrenome); //Recebendo a resposta do usu�rio
	
	file = fopen(arquivo, "a"); //Entra dentro da file e informa que vai adicionar outra informa��o a string arquivo ("a")
	fprintf(file, sobrenome); //Adicionando a v�riavel SOBRENOME dentro da file
	fclose(file); //Fecha a file
	
	file = fopen(arquivo, "a"); //Entra dentro da file e informa que vai adicionar uma nova v�riavel a string(arquivo)
	fprintf(file, ","); //Adiciona uma v�rgula dentro da string
	fclose(file); //Fecha a file
	
	printf("Digite o cargo a ser cadastrado: "); //Questionando o usu�rio qual ser� o CARGO cadastrado
	scanf("%s", &cargo); //Recebendo a resposta do usu�rio
	
	file = fopen(arquivo, "a"); //Abrindo a string(arquivo) e informando que iremos adicionar um novo valor ("a")
	fprintf(file, cargo); //Adicionando a v�riavel cargo a string(arquivo)
	fclose(file); //Fecha a file
	
	printf("\nUsu�rio cadastrado com sucesso! \n\n"); //Informando ao usu�rio que o cadastrado ocorreu com sucesso e dando 2 enters para melhor visualiza��o
	
	system("pause");  //Pausando o sistema para n�o retornar direto ao menu sem avisar o usu�rio
}
int consulta(){ //Fun��o respons�vel por realizar a consulta de usu�rios
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma que ser� usado no c�digo para uso de pontua��es
	
	//Adicionando v�riaveis/strings
	char cpf[40];
	char conteudo[200];
	//Fim das declara��es de v�riaveis/strings
	
	printf("Digite o CPF a ser consultado: "); //Questionando o usu�rio de qual CPF ser� consultado
	scanf("%s", cpf); //Armazenando a resposta do usu�rio
	
	FILE *file; //Chamando o ponteiro denominado de file (*) para a fun��o
	file = fopen(cpf, "r"); //Consultando a string(cpf) que � os mesmos valores da string(arquivo) armazenado no c�digo da fun��o registro)
	
	if(file == NULL){ //Caso o arquivo seja NULL (Inexistente) fa�a o que est� escrito abaixo
		printf("\nN�o foi poss�vel localizar o usu�rio!\n\n"); //Informe ao usu�rio caso o arquivo ser� inexistente ou vazio
	} else { //Se estiver algo dentro, fa�a a formula abaixo
		while(fgets(conteudo, 200, file) != NULL){ //FGETS ir� ler linha por linha da string(file) e armazenar na string(conteudo) at� 200 caracteres enquanto o valor da caracter for diferente de NULL(vazio), caso seja NULL ele ir� parar
			// Separar os campos por v�rgulas
			char *campo = strtok(conteudo, ","); //strtok ir� dividir a string(conteudo) em varias partes, armazenara na vari�vel(campo) cada caracter ou texto antes da virgula
			int contador = 0; //Iniciando a v�riavel contador
			
			char *rotulos[] = {"CPF", "NOME", "SOBRENOME", "CARGO"}; //Criando uma var�avel caracter em modelo de array para armazenar cada nome, ser� exibido junto aos dados da string(campo)
			
			printf("\nEssas s�o as informa��es do usu�rio:\n\n"); //Avisando o usu�rio que logo em seguida ir� aparecer as informa��es do usu�rio
			
			while(campo != NULL && contador < 4){ //Enquanto campo for diferente de NULL e o contador menor que 4 repita
				printf("%s: %s\n", rotulos[contador], campo); //Iremos chamar a array rotulos que nomeamos com CPF, NOME, SOBRENOME, CARGO e pegar o valor que est� dentro de cada array, lembresse que em arrays come�amos com 0 e n�o 1
				campo = strtok(NULL, ","); //Chamando novamente o strtok (Sempre que chamado ele pega a prox�ma cadeia de caracter antes da virgula e registra a usada anteriormente como NULL, por isso informamos NULL antes)
				contador++;  //Aumentando o valor de contador para n�o repetir a mesma numera��o da array(contador) sempre
			}
			
			printf("\n"); //Imprimindo uma linha em branco para separar as informa��es
		}
	}
	
	fclose(file); //Fechando o arquivo para que ele n�o chame a prox�ma fun��o indevidamente
	system("pause"); //Pausando para o usu�rio n�o retornar direto para o menu
}
int deletar(){ //Fun��o respons�vel por deletar o usu�rio
	
	//Definindo a linguagem que ser� utilizada no c�digo para usarmos pontua��es
	setlocale(LC_ALL, "Portuguese");
	
	//Definindo v�riaveis/strings
	char cpf[40];
	//Fim da defini��o de v�rivaveis/strings
	
	printf("Digite o CPF a ser deletado: "); //Questionando o usu�rio qual CPF ser� deletado
	scanf("%s", cpf); //Armazenando a resposta do usu�rio na string CPF
	
	remove(cpf); //Excluindo completamente o arquivo com o n�mero do CPF do nosso banco de dados
	
	FILE *file; //Chamando o arquivo file
	file = fopen(cpf, "r"); //Consultando a string(cpf) com o "r"
	
	if(file == NULL){ //Se n�o possuir um usu�rio registrado ele ir� informar
		printf("Us�ario deletado com sucesso!\n\n"); //Avisando que o usu�rio foi deletado
	}else{ //Caso o usu�rio n�o tenha sido deletado, ele ir� repassar as informa��es abaixo
		printf("N�o foi poss�vel deletar o us�ario!\n\n");
	}
	
	fclose(file); //Sempre feche o arquivo!
	system("pause"); //Pausando o sistema para o usu�rio n�o retornar direto ao menu
}
//Fim das defini��es de fun��es extras

int main(){ 

	//Definindo vari�veis 
	int opcao = 0;
	int laco = 1;
	//Fim das defini��es de vari�veis
	
	//Definindo a linguagem para utiliza��o de caracteres especiais
	setlocale(LC_ALL, "Portuguese"); 
	
	for(laco = 1; laco = 1;){ //Criando um ciclo infinito
		
		system("cls"); //Limpando o CMD
		
		//Inicio do menu
		printf("\n\n\t\t\t\t\t\tCart�rio da EBAC\t\t\n\n");
		printf("Escolha a op��o desejada no nosso painel: \t\t\n\n");
		printf("\t1 - Registrar us�ario\n");
		printf("\t2 - Consultar us�ario\n");
		printf("\t3 - Deletar us�ario\n\n");
		//Fim do menu
		
		//Armazenando a op��o do us�ario
		printf("Por favor, digite a op��o desejada: "); //Questionando o usu�rio qual op��o ele quer consultar
		scanf("%d", &opcao); //Armazenando a resposta do usu�rio
		
		system("cls"); //Limpando o CMD
		
		//In�cio da sele��o
		switch(opcao){ //Substitui o if-else, A estrutura switch permite executar diferentes blocos de c�digo
			case 1: //Caso a resposta do usu�rio seja 1 ele ir� fazer esse case
			registro(); //Chamar� a fun��o registro e far� o que est� dentro dela
			break; //Faz o c�digo parar e n�o come�ar o case de baixo sozinho
			
			case 2: //Caso a resposta do usu�rio seja 2 ele ir� fazer esse case
			consulta(); //Chamar� a fun��o consulta e far� o que est� dentro dela
			break; //Faz o c�digo parar e n�o come�ar o case de baixo sozinho
			
			case 3: //Caso a resposta do usu�rio seja 3 ele ir� fazer esse case
			deletar(); //Chamar� a fun��o deletar e far� o que est� dentro dela
			break; //Faz o c�digo parar e n�o come�ar o case de baixo sozinho
			
			default: //Caso a op��o n�o seja nenhuma das cases informadas ele ir� retornar o c�digo abaixo
			printf("Voc� digitou uma op��o invalida!, tente novamente!\n\n"); //Mensagem enviada para o usu�rio
			break; //Parando o case
			system("pause"); //Pausando o sistema para o usu�rio n�o voltar diretamente ao menu
		}
		//Fim da sele��o
	}
	//Fim do ciclo
}
