#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct noLista{

    char valor;

    struct noLista *anterior, *proximo;
} NOLISTA;

typedef NOLISTA *NOLISTAPTR;

void insere_no_inicio(NOLISTAPTR *inicio, char valor){

    NOLISTAPTR novo;

    novo = (NOLISTAPTR) malloc(sizeof(NOLISTA));
    
    if(novo == NULL)

    return;

    if (*inicio == NULL)
    {
        novo->valor = valor;

        novo->proximo = novo->anterior = NULL;

        *inicio = novo;
    }
    
    else{

        novo->valor = valor;

        novo->anterior = NULL;

        novo->proximo = *inicio;

        (*inicio)->anterior = novo;
    }
}

void insere_no_final(NOLISTAPTR *inicio, char valor){
    
    NOLISTAPTR novo, atual;

    novo = malloc(sizeof(NOLISTA));

    if(*inicio == NULL)

    return;

    if(*inicio == NULL){
        novo->valor = valor;

        novo->proximo = novo->anterior = NULL;

        *inicio = novo;
    }

    else{

        atual = *inicio;

        while (atual->proximo != NULL)
        {
            atual = atual->proximo;

            novo->valor = valor;

            novo->anterior = atual;

            novo->proximo = NULL;

            atual->proximo = novo; 
        }
        
    }

    int retira(NOLISTAPTR *inicio, char valor){

        NOLISTAPTR temporario, atual;

        if (*inicio == NULL)
        {
            return 0;

            atual = *inicio;
            
            if((*inicio)->valor == valor)

            *inicio = (*inicio)->proximo;

            while (atual != NULL && atual->valor != valor)
             
             atual = atual->proximo;

             return 0;

             else{

                 temporario = atual;

                 if(atual->anterior != NULL)

                 atual->proximo->anterior = atual->anterior;

                 free(temporario);
             }

             return 1;
            


        }

        char elimina_no(NOLISTAPTR *inicio){

            NOLISTAPTR temporario;

            char c;

            temporario = *inicio;
            c = (*inicio)->valor;
            *inicio = (*inicio)->valor;

            free(temporario);

            return c;
        }

        int esta_vazio(NOLISTAPTR lista){

            return lista == NULL;
        }

        void imprime_lista_ordem_direta(NOLISTAPTR lista){

            if(esta_vazia(lista))

            printf("\n\nA lista esta vazia.\n\n");

            else{
                printf("\nA lista eh:\n\n")

                while (lista != NULL)
                {
                    printf(" %c", lista->valor);

                    lista = lista->proximo;
                }
                
            }
        }        

        void imprime_lista_ordem_inversa(NOLISTAPTR lista){

            if(esta_vazia(lista))

            printf("\n\nA lista esta vazia.\n\n");

            else{
                while(lista->proximo != NULL)

                lista = lista->proximo;

                printf9("\nA lista eh:\n\n");

                while(lista = NULL){
                    printf(" %c", lista->valor);

                    lista = lista->anterior;
                }

            }

        }

        void menu(){

            printf(" <------> OPERACOES BASICAS EM UMA LISTA DUPLAMENTE ENCADEADA <------>\n\n");

            printf("\n\n\t\t\t\t OPCOES\n\n");

            printf("\t\t1 - Inserir um elemento no inicio da lista\n");

            printf("\t\t2 - Inserir um elemento no final da lista\n");

            printf("\t\t3 - Remover um elemento da lista\n");

            printf("\t\t4 - Imprimir lista na ordem direta\n");

            printf("\t\t5 - Imprimir lista na ordem inversa\n");

            printf("\t\t6 - sair\n\n");
        }

        int main(){

            NOLISTAPTR lista = NULL;

            int opcao;

            char valor;

            menu();

            printf("Escolha uma das opcoes: ");

            scanf("%d", &opcao);

            while(opcao != 6)

            switch (opcao)
            {
            case 1:
                printf("\nDigite um caractere; ");

                scanf("\n%c", &valor);

                insere_no_inicio(&lista, valor);

                system("cls");

                break;

            case 2:

                printf("\nDigite um caractere; ");

                scanf("\n%c", &valor);

                insere_no_final(&lista, valor);

                system("cls");
        
                break;
            
             case 3:

                printf("\nDigite o valor a ser retirado; ");

                scanf("\n%c", &valor);

                if(! retira(&lista, valor)){

                    printf("\nNo inexistente!\n\n")
                }
        
                break;
            
            }

        }
    }
}

