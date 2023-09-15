#include <stdio.h>
#define MAX_SIZE 100

// Estrutura que representa a lista
typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

// Função para deixar a lista vazia
void initializeSet(Set *set) {
    set->size = 0;
}

// Função para verificar se um elemento está presente na lista
int isElementPresent(Set *set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1; // Elemento encontrado
        }
    }
    return 0; // Elemento não encontrado
}

// Função para inserir um elemento na lista
void insertElemento(Set *set, int element) {
    if (set->size < MAX_SIZE && !isElementPresent(set, element)) {
        set->elements[set->size] = element;
        set->size++;
        printf("\nElemento %d inserido com sucesso.\n", element);
    } else {
        printf("\nO elemento %d já está presente ou o conjunto está cheio.\n", element);
    }
}

// Função para remover um elemento da lista
void removeElemento(Set *set, int element) {
    int found = 0;
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            found = 1;
            // Substituir o elemento encontrado pelo último elemento da lista
            set->elements[i] = set->elements[set->size - 1];
            set->size--;
            printf("\nElemento %d removido com sucesso.\n", element);
            break;
        }
    }
    if (!found) {
        printf("\nO elemento %d não foi encontrado no conjunto.\n", element);
    }
}

// Função para imprimir todos os elementos da lista
void printElementos(Set *set) {
    printf("\n");
    printf("Elementos no conjunto: ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->elements[i]);
    }
    printf("\n");
}

//Parte Principal do sistema
void testeLista_inteiros() {
    Set lista;
    initializeSet(&lista);

    int escolha, numero, n = 1;

    do{
        printf("\n1. Inserir elemento\n2. Remover elemento\n3. Verificar presenca\n4. Imprimir todos os elementos\n5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &numero);
                insertElemento(&lista, numero);
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &numero);
                removeElemento(&lista, numero);
                break;
            case 3:
                printf("Digite o elemento a ser verificado: ");
                scanf("%d", &numero);
                if (isElementPresent(&lista, numero)) {
                    printf("\nO elemento %d esta presente no conjunto.\n", numero);
                } else {
                    printf("\nO elemento %d nao esta presente no conjunto.\n", numero);
                }
                break;
            case 4:
                printElementos(&lista);
                break;
            case 5:
                n = 0;
                printf("\nsaindo...\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
                n = 0;
        }
    }while( (n == 1) );

}