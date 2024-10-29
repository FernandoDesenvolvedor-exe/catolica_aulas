#include <stdio.h> 

typedef struct lista { 
    char nome[20]; 
    int idade; 
    struct lista *prox; 
} LISTA;

int main(void){ 
    LISTA *inicio = NULL; 
    LISTA *fim = NULL; 
    LISTA *aux; 
    int i; 

	// entrada de dados na lista 
    for (i = 0; i < 3; i++) { 
    	LISTA *l = (LISTA*) malloc(sizeof(LISTA)); 
        printf("Digite o nome : "); 
		scanf("%s",l->nome); 		
        fflush(stdin); 
        
        printf("Digite o idade : "); 
		scanf("%i",&l->idade); 
        fflush(stdin); 

		if (inicio == NULL) { 
            inicio = l; 
            fim = inicio; 
            l->prox = NULL; 
        } else { 
            l->prox = inicio; 
            inicio = l; 
        } 
    } 
    
    // impressão dos dados da lista  
    if (inicio == NULL) { 
        printf("Lista vazia!!\n"); 
    } else { 
        aux = inicio; 
        while (aux != NULL) { 
            printf("%s, ",aux->nome ); 
            printf("%i\n",aux->idade ); 
            aux = aux->prox; 
        } 
	}
} 