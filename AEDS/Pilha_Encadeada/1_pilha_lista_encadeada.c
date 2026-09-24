/* ============================================================
   EXERCICIO 1 - FACIL
   Implemente uma Pilha utilizando Lista Encadeada contendo
   todas as operacoes fundamentais.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

/* ---------------- ESTRUTURAS ---------------- */

typedef struct No
{
    int valor;
    struct No* proximo;
} No;

typedef struct
{
    No* topo;
    int tamanho;
} Pilha;

/* ---------------- FUNCOES DE LEITURA (utilitarias) ---------------- */

int LerNumero(const char* mensagem, int minimo, int maximo)
{
    char entrada[100];
    char* topoStr;
    long valor;

    while (1)
    {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            continue;

        entrada[strcspn(entrada, "\n")] = '\0';

        valor = strtol(entrada, &topoStr, 10);

        if (*entrada == '\0' || *topoStr != '\0')
        {
            printf("Entrada invalida. Digite apenas numeros.\n\n");
            continue;
        }

        if (valor < minimo || valor > maximo)
        {
            printf("Valor invalido - Min %d, Max %d.\n\n",
                minimo, maximo);
            continue;
        }

        return (int)valor;
    }
}

/* ---------------- OPERACOES FUNDAMENTAIS DA PILHA ---------------- */

void InicializarPilha(Pilha* pilha)
{
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int PilhaVazia(Pilha* pilha)
{
    return pilha->topo == NULL;
}

void Push(int valor, Pilha* pilha)
{
    No* novoNo = (No*)malloc(sizeof(No));

    if (novoNo == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;

    printf("Valor %d inserido no topo da pilha.\n", valor);
}

void Pop(Pilha* pilha)
{
    if (PilhaVazia(pilha))
    {
        printf("Pilha vazia! Nao ha o que remover.\n");
        return;
    }

    No* removido = pilha->topo;
    printf("Valor removido do topo: %d\n", removido->valor);

    pilha->topo = removido->proximo;
    pilha->tamanho--;
    free(removido);
}

void Peek(Pilha* pilha)
{
    if (PilhaVazia(pilha))
    {
        printf("Pilha vazia! Nao ha topo para exibir.\n");
        return;
    }

    printf("Valor no topo da pilha: %d\n", pilha->topo->valor);
}

void Size(Pilha* pilha)
{
    printf("Tamanho atual da pilha: %d\n", pilha->tamanho);
}

void Exibir(Pilha* pilha)
{
    if (PilhaVazia(pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Pilha (topo -> base): ");
    No* atual = pilha->topo;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void DestruirPilha(Pilha* pilha)
{
    while (!PilhaVazia(pilha))
    {
        No* removido = pilha->topo;
        pilha->topo = removido->proximo;
        free(removido);
    }
    pilha->tamanho = 0;
}

/* ---------------- PROTOTIPOS ---------------- */

void atividade(void);

/* ---------------- MAIN ---------------- */

int main(void)
{
    system(CLEAR_COMMAND);

    int selecionarDificuldade = 0;

    selecionarDificuldade = LerNumero(
        "EXERCICIO PILHA\n\n"
        "1 = PILHA LISTA ENCADEADA\n"
        "Selecione: ", 1, 1);

    switch (selecionarDificuldade)
    {
        case 1:
        {
            atividade();
        }
        break;

        default:
        {
            printf("Selecione um exercicio valido");
        }
    }
    return 0;
}

void atividade(void)
{
    system(CLEAR_COMMAND);

    Pilha pilha;
    int opcao = 0, valorInserir = 0;

    InicializarPilha(&pilha);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Push\n\t"
            "2 - Pop\n\t"
            "3 - Peek\n\t"
            "4 - Size\n\t"
            "5 - Exibir Pilha\n\t"
            "Selecione: ", 0, 5);

        switch (opcao)
        {
            case 1:
                system(CLEAR_COMMAND);
                valorInserir = LerNumero("Digite um valor a ser inserido: ", 1, 100);
                Push(valorInserir, &pilha);
                break;
            case 2:
                system(CLEAR_COMMAND);
                Pop(&pilha);
                break;
            case 3:
                system(CLEAR_COMMAND);
                Peek(&pilha);
                break;
            case 4:
                system(CLEAR_COMMAND);
                Size(&pilha);
                break;
            case 5:
                system(CLEAR_COMMAND);
                Exibir(&pilha);
                break;
            default:
                if (opcao != 0)
                {
                    printf("Opcao Invalida!\n");
                }
        }
    } while (opcao != 0);

    DestruirPilha(&pilha);
    return;
}
