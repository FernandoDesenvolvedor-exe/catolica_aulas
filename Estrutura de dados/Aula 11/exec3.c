/*
Construa um algoritmo que contenha uma lista estática homogênea para 
guardar seis números reais, solicite ao usuário os números e 
apresente para ele a média dos números. 
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
	//variáveis
	int i; 
	float soma = 0, lista[6];
	
	for(i = 0; i < 6; i++){
		printf("Digite um número: ");
		scanf("%f",&lista[i]);
		fflush(stdin);
	}
	
	i = 0;
	
	do{		
		soma =+ lista[i];
		i++;
	}while(i < 6);
		
	printf("Media dos numeros e: %f",soma/i);
			
	return 0;
}