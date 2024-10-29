#include <stdio.h> 

typedef struct lista { 
    int num; 
    struct lista *prox;
} LISTA; 
 
int main(void){ 
    LISTA *inicio = NULL; 
    LISTA *fim = NULL; 
    LISTA *aux; 
    int i; 

	// entrada de dados na lista 
    for (i = 0; i < 3; i++) { 
        printf("Digite o numero :"); 
        LISTA *l = (LISTA*) malloc(sizeof(LISTA)); 
        scanf("%i",&l->num); 
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
            printf("%i\n",aux->num ); 
            aux = aux->prox; 
        } 
	} 
} 