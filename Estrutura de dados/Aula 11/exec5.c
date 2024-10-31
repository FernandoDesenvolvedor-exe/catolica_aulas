/*
Elabore um algoritmo que leia uma sequência de números, 
armazenando-os numa lista simplesmente encadeada e que, 
em seguida, verifique se a lista linear encadeada está 
ordenada. Suponha que a lista não contenha números repetidos.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int numero;
	struct lista* prox; 
}LISTA;

#define INICIO_SEQ 0
#define FIM_SEQ 10

int main(void){
	LISTA* inicio = NULL;
	LISTA* aux;
	int i, fora_sequencia;
	
	
	for(i = INICIO_SEQ; i < FIM_SEQ; i++){
		LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
		
		if(i == 5){
			lista->numero = 0;
		} else {
			lista->numero = i;	
		}		
		
		if(inicio == NULL){
			inicio = lista;
			lista->prox = NULL;
		} else {
			lista->prox = inicio;
			inicio = lista;
		}
	}
	LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
	lista->numero = 1;
	lista->prox = inicio;
	inicio = lista;
	
	if(inicio == NULL){
		printf("Lista vazia");
	} else {
		aux = inicio;
		
		while(aux != NULL){			
			printf("%i - ",aux->numero);
			
			if(aux->numero < aux->prox->numero){
				printf("Interacao fora de sequencia");
			}
			
			printf("\n");
			
			aux = aux->prox;
		}
	}
	
	return 0;
}
