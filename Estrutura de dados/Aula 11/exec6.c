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

void imprimeLista(PESSOAS* lista);
int getSizePessoas(PESSOAS* lista);
PESSOAS* inserir (PESSOAS* l, char nome[]);

int main(void){
	//variaveis
	PESSOAS* L1 = NULL;
	PESSOAS* L2 = NULL;
	PESSOAS* L3 = NULL;
	PESSOAS* aux1;
	PESSOAS* aux2;	
	PESSOAS* aux3;	
	int i, op, qtd_lista;
	char nome[50];
	
	
	do{
		printf("1 - Insere Lista 1\n");
		printf("2 - Insere Lista 2\n");
		printf("3 - Cria Lista 3\n");
		printf("4 - Imprime Listas\n");
		printf("5 - Sair\n");
		printf("opcao: ");		
		scanf("%i",&op);
		fflush(stdin);
		
		system("cls");	
		
		switch(op){
			case 1:
				printf("Nome: ");
				gets(nome);
				fflush(stdin);
				
				L1 = inserir(L1, nome);
				system("cls");	
				
				break;
			case 2:
				printf("Nome: ");
				gets(nome);
				fflush(stdin);
				
				L2 = inserir(L2, nome);
				system("cls");		
				
				break;
			case 3:
				if(L1 == NULL){
					printf("Lista 1 está vazia!\n");
				} else if (L2 == NULL){
					printf("Lista 2 está vazia!\n\n");
				} else {
					
					if(getSizePessoas(L1) < getSizePessoas(L2)){
						
						aux1 = L1;
						aux2 = L2;
						
						while(aux1 != NULL){
							while(aux2 != NULL){
								if(!strcmp(aux1->nome,aux2->nome)){
									PESSOAS* pessoa = (PESSOAS*) malloc(sizeof(PESSOAS));
									strcpy(pessoa->nome,aux1->nome);
									
									if(strcmp(pessoa->nome,'\0')){
										if(L3 == NULL){
											L3 = pessoa;
											pessoa->prox = NULL;
										} else {
											pessoa->prox = L3;
											L3 = pessoa;
										}
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
								if(!strcmp(aux1->nome,aux2->nome)){
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
				
				break;
			case 4:				
				printf("L1: \n");
				imprimeLista(L1);
				printf("L2: \n");
				imprimeLista(L2);
				printf("L3: \n");
				imprimeLista(L3);
				
				break;
			case 5:
				break;
			default:
				break;
		}
		
		
	}while(op != 5);
	
	return 0;
}

void imprimeLista(PESSOAS* lista){
	PESSOAS* aux_func;
	
	if(lista == NULL){
		printf("Lista está vazia");
	} else {
		aux_func = lista;
		
		while(aux_func != NULL){
			printf("Nome: %s\n", aux_func->nome);
			aux_func = aux_func->prox;
		}
	}
	printf("\n\n");
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

PESSOAS* inserir (PESSOAS *l, char nome[]){
	PESSOAS *aux;
	PESSOAS *novo = (PESSOAS*) malloc(sizeof(PESSOAS));
	strcpy(novo->nome, nome);
	novo->prox = NULL;
	
	if (l == NULL) {
        l = novo;
    } else {
        aux = l;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return l;
}