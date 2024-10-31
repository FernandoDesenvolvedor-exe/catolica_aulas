/*
Faça um algoritmo que leia duas sequências de nomes de pessoas
e armazene-os em duas listas simplesmente encadeadas L1 e L2,
respectivamente. Em seguida, o programa deve criar uma terceira
lista encadeada, contendo os nomes comuns às duas listas e
mostrar a lista resultante.
Exemplo:
- L1 = Joana, Laura, Sérgio, Fábio.
- L2 = Anita, Joaquim, Fábio, Joana, Pedro, Sílvia.
- L3 = Joana, Fábio.
R.:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct pessoas {
	char nome[50];
	struct pessoas* prox;
}PESSOAS;

int getSizePessoas(PESSOAS* lista);

int main(void){
	//variaveis
	PESSOAS* L1 = NULL;
	PESSOAS* L2 = NULL;
	PESSOAS* L3 = NULL;
	PESSOAS* aux1;
	PESSOAS* aux2;	
	PESSOAS* aux3;	
	int i, op, qtd_lista;
	
	
	do{
		printf("1 - Insere Lista 1\n");
		printf("2 - Insere Lista 2\n");
		printf("3 - Cria Lista 3\n");
		printf("4 - Imprime Listas\n");
		printf("5 - Sair\n");
		printf("opcao: ");		
		scanf("%i",&op);
		
		system("cls");	
		
		switch(op){
			case 1:
				printf("tamanho da lista 1: ");
				scanf("%i",&qtd_lista);
				fflush(stdin);
				
				for(i = 0; i < qtd_lista; i++){
					PESSOAS* pessoa = (PESSOAS*) malloc(sizeof(PESSOAS));
					printf("Pessoa %i: ",i+1);
					gets(pessoa->nome);
					fflush(stdin);
					
					if(L1 == NULL){
						L1 = pessoa;
						pessoa->prox = NULL;
					} else {
						pessoa->prox = L1;
						L1 = pessoa;
					}
				}
				system("cls");	
				
				break;
			case 2:
				printf("tamanho da lista 2: ");
				scanf("%i",&qtd_lista);
				fflush(stdin);
				
				for(i = 0; i < qtd_lista; i++){
					PESSOAS* pessoa = (PESSOAS*) malloc(sizeof(PESSOAS));
					printf("Pessoa %i: ",i+1);
					gets(pessoa->nome);
					
					if(L2 == NULL){
						L2 = pessoa;
						pessoa->prox = NULL;
					} else {
						pessoa->prox = L2;
						L2 = pessoa;
					}
				}				
				system("cls");	
				
				break;
			case 3:
				if(L1 == NULL){
					printf("Lista 1 está vazia!");
				} else if (L2 == NULL){
					printf("Lista 2 está vazia!");
				} else {
					
					if(getSizePessoas(L1) < getSizePessoas(L2)){
						
						aux1 = L1;
						aux2 = L2;
						
						while(aux1 != NULL){
							while(aux2 != NULL){
								if(aux1->nome == aux2->nome){
									PESSOAS* pessoa = (PESSOAS*) malloc(sizeof(PESSOAS));
									strcpy(pessoa->nome,aux2->nome);
									
									if(L3 == NULL){
										pessoa->prox = NULL;
										L3 = pessoa;
									} else {
										pessoa->prox = L3;
										L3 = pessoa;
									}
								}
								
								aux2 = aux2->prox;
							}
							
							aux1 = aux1->prox;
						}									
						
					} else {
						aux1 = L1;
						aux2 = L2;
						
						while(aux2 != NULL){
							while(aux1 != NULL){
								if(aux1->nome == aux2->nome){
									PESSOAS* pessoa = (PESSOAS*) malloc(sizeof(PESSOAS));
									strcpy(pessoa->nome,aux1->nome);
									if(L3 == NULL){
										pessoa->prox = NULL;
										L3 = pessoa;
									} else {
										pessoa->prox = L3;
										L3 = pessoa;
									}
								}
								
								aux1 = aux1->prox;
							}
							
							aux2 = aux2->prox;
						}
					}
				}	
				system("cls");
				
				break;
			case 4:
				if(L3 == NULL){
					printf("Lista 3 está vazia");
				} else {
					aux3 = L3;
					
					while(aux3 != NULL){
						printf("Nome: %s", aux3->nome);
						aux3 = aux3->prox;
					}
				}
				
				break;
			case 5:
				break;
			default:
				break;
		}
		
		
	}while(op != 5);
	
	return 0;
}

int getSizePessoas(PESSOAS* lista){
	PESSOAS* aux;
	
	if(lista == NULL){
		return 0;
	} else {		
		aux = lista;
		int cont; 
		
		while(aux != NULL){
			cont++;
			aux = aux->prox;
		}
		
		return cont;
	}	
}