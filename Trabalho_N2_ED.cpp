/*

Lista de Exercicios Referente a P1

Turma: ADS MA3

Nome: Lucas Alves Queiroz 	RA: 1680481612002
Nome: Thiago Bussolin		RA: 1680481612011

*/


/*
1.	Escreva uma fun��o recursiva que calcule os juros compostos de um valor. Para isso o programa dever� ler um valor 
inicial, o n�mero de meses e a taxa de juros ao m�s, e passar estes valores � fun��o como par�metros. 
Prot�tipo: double juroscompostos(double valor, double taxa, int meses) 
*/

double juroscompostos (double valor, double taxa, int meses){
	if (meses==0) return valor;	//quando o mes recebido por parametro for 0 retorna o valor
	juroscompostos(valor*(taxa+1), taxa, meses-1); //calcula a taxa sobre o valor atual e envia novamente
												   //para a funcao recursiva o novo valor e reduz 1 mes do calculo
}


/*
2.	Leia palavras de at� 15 caracteres at� que a palavra "fim" seja digitada. 
Grave cada palavra lida (uma por linha)  num arquivo de nome "palavras2.txt".
*/

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








/*
3.	Preencher um vetor de inteiros de tamanho 10 com valores aleat�rios  na faixa de 1 a 10, sem repeti��o. 
N�o � para o usu�rio digitar.	void semRepetidos(int  v[], int tam)
*/

void semRepetidos(int v[], int tam){
	srand(time(NULL));		//Inicializa uma seed global para os randomicos
	int num, aux;			//Variavel para armazenar o int random e o aux para repetidos
	
	for(int i=0;i<tam;i++){
		num=rand()%10+1;	//Gera um numero randomico de 1 a 10
		aux=0;				//0 o valor auxiliar para cada nova comparacao
		
		for(int k=0;k<i;k++)//laco para percorrer o vetor do 0 ate o ponto preenchido
			if(num==v[k])	//verifica se o novo numero gerado ja esta presente no vetor
				aux++;		//caso esteja aumenta o valor da variavel aux
		
		if(aux==0)			//verifica o valor da variavel aux para saber se o numero gerado
			v[i]=num;		//ja estava presente no vetor ou nao, caso ele ja exista reduz a
		else				//variavel i em 1 e roda denovo para ele gerar um novo random, caso
			i--;			//o aux seja 0 ele adiciona o valor random ao vetor.
	}
}

/*
4.	Retorne a soma dos n�s da �rvore. 
 	prot�tipo: int somaNos(Arv *Tree) 
*/

int somaNos(Arv *Tree){
	if (abb_vazia(Tree))//Verifica se chegou no ultimo no da arvore
           return 0;   	//retorna 0 caso o no nao exista
       return Tree->info + somaNos(Tree->esq) + somaNos(Tree->dir); //soma o info do no com a funcao recursiva
	   																//para ambos os lados da arvore.
}