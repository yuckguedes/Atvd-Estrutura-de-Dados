#include <stdio.h>
#include <string.h>

// Definição da estrutura de um contato
typedef struct {
    char nome[50];
    char telefone[15];
    char endereco[100];
} Contato;

// Definição da Agenda
typedef struct {
    Contato contatos[100]; 
    int numContatos;    
} Agenda;

// Inicializa uma nova agenda vazia
void inicializarAgenda(Agenda *agenda) {
    agenda->numContatos = 0;
}

// Adiciona um novo contato à agenda
void adicionarContato(Agenda *agenda, Contato novoContato) {
    if (agenda->numContatos < 100) {
        agenda->contatos[agenda->numContatos] = novoContato;
        agenda->numContatos++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A agenda esta cheia. Nao e possivel adicionar mais contatos.\n");
    }
}

// Remove um contato da agenda pelo nome
void removerContato(Agenda *agenda, char *nome) {
    int i, j;
    for (i = 0; i < agenda->numContatos; i++) {
        if (strcmp(agenda->contatos[i].nome, nome) == 0) {
            for (j = i; j < agenda->numContatos - 1; j++) {
                agenda->contatos[j] = agenda->contatos[j + 1];
            }
            agenda->numContatos--;
            printf("Contato removido com sucesso!\n");
            return;
        }
    }
    printf("Contato nao encontrado na agenda.\n");
}

// Procura um contato na agenda pelo nome e retorna suas informações
Contato buscarContato(Agenda agenda, char *nome) {
    int i;
    for (i = 0; i < agenda.numContatos; i++) {
        if (strcmp(agenda.contatos[i].nome, nome) == 0) {
            return agenda.contatos[i];
        }
    }
    // Retorna um contato vazio se não encontrado
    Contato contatoVazio;
    strcpy(contatoVazio.nome, "N/A");
    return contatoVazio;
}

// Lista todos os contatos na agenda
void listarContatos(Agenda agenda) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < agenda.numContatos; i++) {
        printf("Nome: %s\n", agenda.contatos[i].nome);
        printf("Telefone: %s\n", agenda.contatos[i].telefone);
        printf("Endereco: %s\n", agenda.contatos[i].endereco);
        printf("---------------------------\n");
    }
}

void testeAgenda() {
    Agenda minhaAgenda;
    inicializarAgenda(&minhaAgenda);

    int escolha;
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Adicionar contato\n");
        printf("2. Remover contato\n");
        printf("3. Buscar contato\n");
        printf("4. Listar contatos\n");
        printf("5. Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o nome, telefone e endereco do contato a ser adicionado:\n");
                Contato novoContato;
                scanf("%s %s %s", novoContato.nome, novoContato.telefone, novoContato.endereco);
                adicionarContato(&minhaAgenda, novoContato);
                break;
            case 2:
                printf("Digite o nome do contato a ser removido:\n");
                char nomeRemover[50];
                scanf("%s", nomeRemover);
                removerContato(&minhaAgenda, nomeRemover);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado:\n");
                char nomeBuscar[50];
                scanf("%s", nomeBuscar);
                Contato resultado = buscarContato(minhaAgenda, nomeBuscar);
                if (strcmp(resultado.nome, "N/A") != 0) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\n", resultado.nome);
                    printf("Telefone: %s\n", resultado.telefone);
                    printf("Endereco: %s\n", resultado.endereco);
                } else {
                    printf("Contato nao encontrado.\n");
                }
                break;
            case 4:
                listarContatos(minhaAgenda);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 5);

}
