#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

//Definindo funções para deixar simplificado no código
int registro(){ //Função responsável por registrar e armazenar os dados do usuário
	
	//Definindo a linguagem que será utilizada no código para podermos utilizar pontuações Importante> Lembre sempre de acrescentar a biblíoteca! <locale.h>
	setlocale(LC_ALL, "Portuguese");
	
	//Inserindo váriaveis/strings no código
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da inserção de váriaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Questionando o usuário de qual será o CPF cadastrado
	scanf("%s", &cpf); //Recebendo a resposta do usuário
	
	strcpy(arquivo, cpf); //Responsável por copiar o valor da string cpf para a string arquivo
	
	FILE *file; //Um (*) é uma variável que guarda o endereço de memória de outra variável.
	file = fopen(arquivo, "w"); //Entra dentro da file e transforma a string/váriavel "arquivo" em uma pasta com o ("w") w - ( criar )

		
	fprintf(file, cpf); //Salva o valor da variavel "CPF" dentro do arquivo 
	fclose(file); //Fecha a file (arquivo)
	
	file = fopen(arquivo, "a"); //Entra dentro da e informa que irá adicionar mais uma informação a string/váriavel chamada arquivo com o ("a") a - ( atualizar )
	fprintf(file, ","); //Adiciona uma virgula para deixar o código mais organizado
	fclose(file); //Fecha a file
	
	printf("Digite o nome a ser cadastrado: "); //Questionando o usuário qual será o NOME cadastrado
	scanf("%s", &nome); //Recebendo a resposta do usuário
	
	file = fopen(arquivo, "a");	//Entra dentro da file e informa que vai adicionar mais uma informação ao arquivo ("a")
	fprintf(file, nome); //Adicionando a váriavel NOME dentro da file
	fclose(file); //Fecha a file
	
	file = fopen(arquivo, "a"); //Entra dentro da file e informa que vai adicionar outra informação a string arquivo ("a")
	fprintf(file, ","); //Adiciona novamente uma vírgula para deixar o código mais limpo
	fclose(file); //Fecha a file
	
	printf("Digite o sobrenome a ser cadastrado: "); //Questionando o usuário qual SOBRENOME será cadastrado
	scanf("%s", &sobrenome); //Recebendo a resposta do usuário
	
	file = fopen(arquivo, "a"); //Entra dentro da file e informa que vai adicionar outra informação a string arquivo ("a")
	fprintf(file, sobrenome); //Adicionando a váriavel SOBRENOME dentro da file
	fclose(file); //Fecha a file
	
	file = fopen(arquivo, "a"); //Entra dentro da file e informa que vai adicionar uma nova váriavel a string(arquivo)
	fprintf(file, ","); //Adiciona uma vírgula dentro da string
	fclose(file); //Fecha a file
	
	printf("Digite o cargo a ser cadastrado: "); //Questionando o usuário qual será o CARGO cadastrado
	scanf("%s", &cargo); //Recebendo a resposta do usuário
	
	file = fopen(arquivo, "a"); //Abrindo a string(arquivo) e informando que iremos adicionar um novo valor ("a")
	fprintf(file, cargo); //Adicionando a váriavel cargo a string(arquivo)
	fclose(file); //Fecha a file
	
	printf("\nUsuário cadastrado com sucesso! \n\n"); //Informando ao usuário que o cadastrado ocorreu com sucesso e dando 2 enters para melhor visualização
	
	system("pause");  //Pausando o sistema para não retornar direto ao menu sem avisar o usuário
}
int consulta(){ //Função responsável por realizar a consulta de usuários
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma que será usado no código para uso de pontuações
	
	//Adicionando váriaveis/strings
	char cpf[40];
	char conteudo[200];
	//Fim das declarações de váriaveis/strings
	
	printf("Digite o CPF a ser consultado: "); //Questionando o usuário de qual CPF será consultado
	scanf("%s", cpf); //Armazenando a resposta do usuário
	
	FILE *file; //Chamando o ponteiro denominado de file (*) para a função
	file = fopen(cpf, "r"); //Consultando a string(cpf) que é os mesmos valores da string(arquivo) armazenado no código da função registro)
	
	if(file == NULL){ //Caso o arquivo seja NULL (Inexistente) faça o que está escrito abaixo
		printf("\nNão foi possível localizar o usuário!\n\n"); //Informe ao usuário caso o arquivo será inexistente ou vazio
	} else { //Se estiver algo dentro, faça a formula abaixo
		while(fgets(conteudo, 200, file) != NULL){ //FGETS irá ler linha por linha da string(file) e armazenar na string(conteudo) até 200 caracteres enquanto o valor da caracter for diferente de NULL(vazio), caso seja NULL ele irá parar
			// Separar os campos por vírgulas
			char *campo = strtok(conteudo, ","); //strtok irá dividir a string(conteudo) em varias partes, armazenara na variável(campo) cada caracter ou texto antes da virgula
			int contador = 0; //Iniciando a váriavel contador
			
			char *rotulos[] = {"CPF", "NOME", "SOBRENOME", "CARGO"}; //Criando uma varíavel caracter em modelo de array para armazenar cada nome, será exibido junto aos dados da string(campo)
			
			printf("\nEssas são as informações do usuário:\n\n"); //Avisando o usuário que logo em seguida irá aparecer as informações do usuário
			
			while(campo != NULL && contador < 4){ //Enquanto campo for diferente de NULL e o contador menor que 4 repita
				printf("%s: %s\n", rotulos[contador], campo); //Iremos chamar a array rotulos que nomeamos com CPF, NOME, SOBRENOME, CARGO e pegar o valor que está dentro de cada array, lembresse que em arrays começamos com 0 e não 1
				campo = strtok(NULL, ","); //Chamando novamente o strtok (Sempre que chamado ele pega a proxíma cadeia de caracter antes da virgula e registra a usada anteriormente como NULL, por isso informamos NULL antes)
				contador++;  //Aumentando o valor de contador para não repetir a mesma numeração da array(contador) sempre
			}
			
			printf("\n"); //Imprimindo uma linha em branco para separar as informações
		}
	}
	
	fclose(file); //Fechando o arquivo para que ele não chame a proxíma função indevidamente
	system("pause"); //Pausando para o usuário não retornar direto para o menu
}
int deletar(){ //Função responsável por deletar o usuário
	
	//Definindo a linguagem que será utilizada no código para usarmos pontuações
	setlocale(LC_ALL, "Portuguese");
	
	//Definindo váriaveis/strings
	char cpf[40];
	//Fim da definição de várivaveis/strings
	
	printf("Digite o CPF a ser deletado: "); //Questionando o usuário qual CPF será deletado
	scanf("%s", cpf); //Armazenando a resposta do usuário na string CPF
	
	remove(cpf); //Excluindo completamente o arquivo com o número do CPF do nosso banco de dados
	
	FILE *file; //Chamando o arquivo file
	file = fopen(cpf, "r"); //Consultando a string(cpf) com o "r"
	
	if(file == NULL){ //Se não possuir um usuário registrado ele irá informar
		printf("Usúario deletado com sucesso!\n\n"); //Avisando que o usuário foi deletado
	}else{ //Caso o usuário não tenha sido deletado, ele irá repassar as informações abaixo
		printf("Não foi possível deletar o usúario!\n\n");
	}
	
	fclose(file); //Sempre feche o arquivo!
	system("pause"); //Pausando o sistema para o usuário não retornar direto ao menu
}
//Fim das definições de funções extras

int main(){ 

	//Definindo variáveis 
	int opcao = 0;
	int laco = 1;
	//Fim das definições de variáveis
	
	//Definindo a linguagem para utilização de caracteres especiais
	setlocale(LC_ALL, "Portuguese"); 
	
	for(laco = 1; laco = 1;){ //Criando um ciclo infinito
		
		system("cls"); //Limpando o CMD
		
		//Inicio do menu
		printf("\n\n\t\t\t\t\t\tCartório da EBAC\t\t\n\n");
		printf("Escolha a opção desejada no nosso painel: \t\t\n\n");
		printf("\t1 - Registrar usúario\n");
		printf("\t2 - Consultar usúario\n");
		printf("\t3 - Deletar usúario\n\n");
		//Fim do menu
		
		//Armazenando a opção do usúario
		printf("Por favor, digite a opção desejada: "); //Questionando o usuário qual opção ele quer consultar
		scanf("%d", &opcao); //Armazenando a resposta do usuário
		
		system("cls"); //Limpando o CMD
		
		//Início da seleção
		switch(opcao){ //Substitui o if-else, A estrutura switch permite executar diferentes blocos de código
			case 1: //Caso a resposta do usuário seja 1 ele irá fazer esse case
			registro(); //Chamará a função registro e fará o que está dentro dela
			break; //Faz o código parar e não começar o case de baixo sozinho
			
			case 2: //Caso a resposta do usuário seja 2 ele irá fazer esse case
			consulta(); //Chamará a função consulta e fará o que está dentro dela
			break; //Faz o código parar e não começar o case de baixo sozinho
			
			case 3: //Caso a resposta do usuário seja 3 ele irá fazer esse case
			deletar(); //Chamará a função deletar e fará o que está dentro dela
			break; //Faz o código parar e não começar o case de baixo sozinho
			
			default: //Caso a opção não seja nenhuma das cases informadas ele irá retornar o código abaixo
			printf("Você digitou uma opção invalida!, tente novamente!\n\n"); //Mensagem enviada para o usuário
			break; //Parando o case
			system("pause"); //Pausando o sistema para o usuário não voltar diretamente ao menu
		}
		//Fim da seleção
	}
	//Fim do ciclo
}
