#include <stdio.h> 

int main(void){ 
    // variáveis primitiva em um vetor 
    int i, lista[10]; 

    for (i=0;i<10;i++){ 
        printf("Digite o numero %i o da lista: ",i+1); 
        scanf("%i", &lista[i]); 
        fflush(stdin); 
    } 

    for (i=0;i<10;i++){ 
        printf("%i, ",lista[i]); 
    } 
} 