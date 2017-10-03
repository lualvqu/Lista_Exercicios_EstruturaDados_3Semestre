#include <stdio.h>
#include <string.h>
int main(){
	char input[15+1];					//variavel para receber as entradas de texto
	FILE *arq;							//ponteiro para receber o arquivo
	arq = fopen("palavras2.txt", "w");	//criando o arquivo de texto no modo escrita
	
	do{						
		fflush(stdin);					//limpando buffer
		scanf("%15[^\n]", input);		//lendo uma string de ate 15 caracteres
		if (strcmp(input, "fim")!=0)	//verifica se foi digitado fim para nao gravar o fim no arquivo de texto
			fprintf(arq, "%s\n", input);//escreve a palavra lida no arquivo de texto
	} while(strcmp(input, "fim")!=0);	//finaliza o laco quando o usuario escrever a palavra fim
	
	fclose(arq);						//fecha o arquivo de texto
}
