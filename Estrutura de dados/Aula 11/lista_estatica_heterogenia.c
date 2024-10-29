#include <stdio.h> 

typedef struct lista { 
    char nome[20]; 
    int idade; 
} Lista; 
 
int main(void){ 
    Lista l[2]; 
    int i;  

    for (i = 0; i < 2; i++) { 
        printf("Digite o %i o nome da lista: ",i+1); 
        scanf ("%s", l[i].nome); 
        fflush(stdin); 

        printf("Digite a %i o idade da lista: ", i+1); 
        scanf("%i", &l[i].idade); 
    } 

    for (i = 0; i < 2; i++) { 
        printf("%s, ",l[i].nome); 
        printf("%i\n",l[i].idade); 
    } 
} 