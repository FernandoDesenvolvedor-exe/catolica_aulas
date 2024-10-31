/*
Construa um algoritmo que contenha uma lista dinâmica homogênea 
para guardar números digitados pelo usuário, solicite ao usuário 
a quantidade de número e os números e depois os imprima em tela.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	char numero;
	struct lista* prox;
}LISTA;


#define TAM 10

int main (void){
	//variaveis
	LISTA* inicio = NULL;
	LISTA* aux;
	int i;
	
	printf("Tamanho da lista: ");
	scanf("%i",&i);
		
	for(int n = 0; n < i; n++){
		LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
		
		printf("Numero: ");
		scanf("%i",&lista->numero);		
		fflush(stdin);
		
		if(inicio == NULL){
			inicio = lista;
			lista->prox = NULL;
		} else {
			lista->prox = inicio;
			inicio = lista;
		}		
	}
	
	//imperssao de dados
	if(inicio == NULL){
		printf("Lista vazia");
	} else {
		aux = inicio;
		while(aux != NULL){
			printf("%i\n",aux->numero);
			aux=aux->prox;
		}
	}
	
			
	return 0;
}