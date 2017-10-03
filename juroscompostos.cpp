#include <stdio.h>
#include <stdlib.h>

double juroscompostos (double valor, double taxa, int meses){
	
	if (meses==0) return valor;	//quando o mes recebido por parametro for 0 retorna o valor
	
	juroscompostos(valor*(taxa+1), taxa, meses-1); //calcula a taxa sobre o valor atual e envia novamente
												   //para a funcao recursiva o novo valor e reduz 1 mes do calculo
}

int main(){
	printf("Valor apos juros: %lf", juroscompostos(1000.0, 0.1, 12));
}
