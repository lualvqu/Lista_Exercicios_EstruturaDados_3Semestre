#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

int main(){
	int vetor[10];
	semRepetidos(vetor, 10);
	for(int i=0;i<10;i++)
		printf("%d ", vetor[i]);
}
