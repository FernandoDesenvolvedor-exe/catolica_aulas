/*
Construa um algoritmo que contenha uma lista estática heterogênea 
para guardar dados cadastrais de dez softwares, solicite ao 
usuário digitar, nome, fabricante, tipo de licença e versão. 
*/

typedef struct {
	char nome[50],fabricante[60],tipo_licenca[50];
	float versao;
}LISTA_SOFTWARE;

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main (void){
	//variaveis 
	int i;
	LISTA_SOFTWARE l[TAM];
	
	for(i = 0; i < TAM; i++){
		printf("Nome do software: ");
		gets(l[i].nome);
		fflush(stdin);
		
		printf("Fabricante: ");
		gets(l[i].fabricante);		
		fflush(stdin);
		
		printf("Tipo de licenca: ");
		gets(l[i].tipo_licenca);		
		fflush(stdin);
		
		printf("Versao: ");
		scanf("%f",&l[i].versao);
		fflush(stdin);
	}
	
	for(i = 0; i < TAM; i++){
		printf("------------------------------------------------------------------------------\n");
		printf("Software: %s\t Versao: %.2f\t Fabricante: %s\t Tipo de licenca: %s\t\n",l[i].nome,l[i].fabricante,l[i].fabricante,l[i].tipo_licenca);
		if(i == TAM-1){
			printf("---------------------------------------------------------------------------");
		}
	}
			
	return 0;
}