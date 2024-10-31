#include <stdio.h>
#include <locale.h>

//Definindo da lista simplesmente encadeada
    
typedef struct lista {
    int num;
    struct lista *prox;
} LISTA;


int main (void){
	setlocale(LC_ALL, "Portuguese");
	
	// a lista está vazia, logo, inicio têm o valor null, inicio conterá o endereço do primeiro elemento da lista
	LISTA *inicio = NULL;
	// fim conterá o endereço do último elemento da lista
    LISTA *fim = NULL;
    // aux é um auxiliar
    LISTA *aux;
    // anterior é um auxiliar
    LISTA *anterior;
    
    LISTA *l;
    
    int i, op, numero, achou;
    
	do {
		system("cls");
        printf("MENU DE OPÇÕES\n\n");
        printf("1 - Inserir no início da lista\n");
        printf("2 - Inserir no final da lista\n");
        printf("3 - Imprimindo toda a lista\n");
        printf("4 - Remover da lista\n");
        printf("5 - Esvaziar a lista\n");
        printf("6 - Sair\n\n");
        printf("Digite sua opção: ");
        scanf("%i", &op);
        fflush(stdin);
        system("cls");
        
        switch(op){
        	case 1:
        		l = (LISTA*) malloc(sizeof(LISTA));
        		printf("Digite o número a ser inserido no início da lista: ");
				
        		scanf("%i",&l->num);
        		fflush(stdin);

				if (inicio == NULL) {
					// a lista esta vazia e o elemento inserido será o primeiro e o último da lista
            		inicio = l;
            		fim = inicio;
            		l->prox = NULL;
        		} else {
            		l->prox = inicio;
            		inicio = l;
       			}
       			
       			printf("Número inserido no início da lista!!\n");
       			getch();
        		break;
        	case 2:
        		printf("Digite o número a ser inserido no fim da lista: ");
                l = (LISTA*) malloc(sizeof(LISTA));
        		scanf("%i",&l->num);
        		fflush(stdin);
        		
                if (inicio == NULL) {
                    // a lista estava vazia e o elemento inserido será o primeiro e o último
                    inicio = l;
            		fim = inicio;
            		l->prox = NULL;
            	} else {
            		fim->prox = l;
            		fim = l;
            		fim->prox = NULL;
            	}
                printf("Número inserido no fim da lista!!");
                getch();
                break;
            case 3:
            	 if (inicio == NULL) {
                    // a lista está vazia
                    printf("Lista vazia!!\n");
                } else {
                    // a lista contém elementos e estes serão mostrados do início ao fim
                    printf("\nConsultando toda a lista\n");
                    aux = inicio;
                    while (aux != NULL) {
                        printf("%i,  ",aux->num);
                        aux = aux->prox;
                    }
                }
                getch();
            	break;
            case 4:
            	if (inicio == NULL) {
                    // a lista está vazia
                    printf("Lista vazia!!\n");
                } else {
                    // a lista contém elementos e o elmento a ser removido deve ser digitado
                    printf("\nDigite o elemento a ser removido: ");
                    scanf("%i",&numero); 
                    // todos as ocorrências da lista, iguais ao número digitado serão removidas
                    aux = inicio;
                    anterior = NULL;
                    achou = 0;
                    while (aux != NULL) {
                        if (aux->num == numero) {
                            // o número digitado foi encontrado na lista e será removido
                            achou = achou + 1;
                            if (aux == inicio) {
                                // o número a ser removido é o primeiro da lista
                                inicio = aux->prox;
                                aux = inicio;
                            } else if (aux == fim) {
                                // o número a ser removido é o último da lista
                                anterior->prox = NULL;
                                fim = anterior;
                                aux = NULL;
                            } else {
                                // o número a ser removido está no meio da lista
                                anterior->prox = aux->prox;
                                aux = aux->prox;
                            }
                        } else {
                            anterior = aux;
                            aux = aux->prox;
                        }
                    }
                    if (achou == 0) {
                        printf("Número não encontrado\n");
                    } else if (achou == 1) {
                        printf("Número removido 1 vez");
                    } else {
                        printf("Numero removido %i vezes",achou);
                    }
                }
                getch();
            	break;
            case 5:
                if (inicio == NULL) {
                    // a lista está vazia
                    printf("Lista vazia!!\n");
                } else {
                    // a lista será esvaziada
                    inicio = NULL;
                    printf("Lista esvaziada");
                }
                getch();
            	break;
            case 6:
            	printf("Saíndo...");
            	getch();
            	break;
        	default:
        		printf("Opção inválida!!\n");
            	getch();
            	system("cls");
        		break;
		}
    } while (op != 6);
}
