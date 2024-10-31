/*
Construa um algoritmo que contenha uma lista dinâmica heterogênea 
onde o usuário deverá informar quantidade de disciplinas que ele 
tem e os dados de cada disciplina como: sala, dia da semana, nome 
disciplina e semestre e depois o algoritmo deve imprimir estes 
dados em tela.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct disciplinas {
	int sala,semestre;
	char diaDaSemana[30],nomeDisciplina[50];
	struct disciplina* prox;
}DISCIPLINAS;

int main (void){
	//variaveis
	DISCIPLINAS* inicio = NULL;
	DISCIPLINAS* fim = NULL;
	DISCIPLINAS* aux;
	int qtd_disciplinas;
	
	printf("Quantidade de disciplinas: ");
	scanf("%i",&qtd_disciplinas);
	
	for(int n = 0; n < qtd_disciplinas; n++){
		DISCIPLINAS* lista = (DISCIPLINAS*) malloc(sizeof(DISCIPLINAS));
		
		printf("---------------------------------------\n");
		printf("Disciplina %i\n",qtd_disciplinas);
		printf("Sala de aula: ");		
		scanf("%i",&lista->sala);
		fflush(stdin);
		
		printf("Semestre: ");
		scanf("%i",&lista->semestre);
		fflush(stdin);
		
		printf("Nome da disciplina: ");
		gets(lista->nomeDisciplina);
		fflush(stdin);
		
		printf("Dia da semana: ");
		gets(lista->diaDaSemana);
		fflush(stdin);
		
		
		if(inicio == NULL){
			inicio = lista;
			lista->prox = NULL;
		} else {
			lista->prox = inicio;
			inicio = lista;
		}
	}	
	
	if(inicio == NULL){
		printf("Lista vazia.");
	} else {
		aux = inicio;
		
		while(aux != NULL){
			printf("\n--------------------------------------\n");
			printf("Nome: %s\n",aux->nomeDisciplina);
			printf("Dia da semana: %s\n",aux->diaDaSemana);
			printf("Sala: %i\n",aux->sala);
			printf("Semestre: %i\n",aux->semestre);
			aux = aux->prox;
		}
	}
		
	return 0;
}