/*
1)	Faça um algoritmo que localize um termo em uma pilha estática homogenia, 
lembre-se de usar o conceito de pilha para fazer este algoritmo, devem ser 
desempilhados os termos para chegar ao termo desejado.
*/

#include <stdio.h>

void empilhar(int n);
void desempilhar(void);

int topo = 0, pilha[10];

int main(void){
	int valor,i;
	
	for(i = 0; i < 10; i++){
		printf("Digitem o numero %i: ",i);
		scanf("%i",&valor);
		empilhar(valor);
	}	
	
	printf("Digite o valor a procurar: ");
	scanf("%i",&valor);
			
	while(valor != pilha[topo]) {
		desempilhar();
	}
		
	printf("Valor esta localizado no indice %i",topo);
	
	return 0;
}

void empilhar(int n){
	pilha[topo] = n;
	topo++;
}

void desempilhar(void){
	topo--;
}