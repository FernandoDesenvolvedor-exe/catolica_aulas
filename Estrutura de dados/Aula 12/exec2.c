/*
4)	Usando o conceito de fila dinâmicas homogenia, 
crie um algoritmo que simule um caixa de banco onde
é dando prioridade no atendimento de certas pessoas.
*/

#include <stdio.h>
#include <stdlib.h>

int fila[10],inicio = 0; fim = 0;

void inserir(int n);
int remover(void);

int main(void){
	int num;
	
	for(int i = 0; i < 10; i++){
		printf("Digite um numero para fila: ");
		scanf("%i",&num);
		inserir(num);
	}
	
	printf("Digite um numero para ser localizado na fila: ");
	scanf("%i",&num);
	
	int aux;
	do{		
		int aux = remover();
		if(num == aux) printf("Achou o numero - "); 
		printf("fila = %i\n",aux);//imprime o valor localizado, pois a fila sempre aponta pro primeiro indice
	}while(inicio != fim);
	
	return 0;
}

void inserir(int n){
	fila[fim] = n;
	fim++;
}

int remover(void){
	int n = fila[inicio];
	
	for(int i = inicio; i < fim; i++){
		fila[i] = fila[i+1];
	}
	
	fim--;	
	
	return n;
}