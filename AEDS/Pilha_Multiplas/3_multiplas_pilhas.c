/* ============================================================
   EXERCICIO 3 - INTERMEDIARIO
   Implemente uma estrutura contendo Multiplas Pilhas
   independentes, permitindo ao usuario selecionar em qual
   Pilha deseja realizar cada operacao.

   Cada pilha e implementada com Lista Encadeada, e todas as
   pilhas ficam guardadas em um vetor de pilhas.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#define MAX_PILHAS 5

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

typedef struct
{
    Pilha pilhas[MAX_PILHAS];
    int quantidadePilhas;
} MultiplasPilhas;

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

/* ---------------- OPERACOES DE UMA PILHA (lista encadeada) ---------------- */

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

    printf("Valor %d inserido no topo.\n", valor);
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

    printf("Valor no topo: %d\n", pilha->topo->valor);
}

void Size(Pilha* pilha)
{
    printf("Tamanho atual: %d\n", pilha->tamanho);
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

/* ---------------- OPERACOES DA ESTRUTURA DE MULTIPLAS PILHAS ---------------- */

void InicializarMultiplasPilhas(MultiplasPilhas* estrutura, int quantidade)
{
    estrutura->quantidadePilhas = quantidade;
    for (int i = 0; i < quantidade; i++)
    {
        InicializarPilha(&estrutura->pilhas[i]);
    }
}

void DestruirMultiplasPilhas(MultiplasPilhas* estrutura)
{
    for (int i = 0; i < estrutura->quantidadePilhas; i++)
    {
        DestruirPilha(&estrutura->pilhas[i]);
    }
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
        "1 = MULTIPLAS PILHAS INDEPENDENTES\n"
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

    MultiplasPilhas estrutura;
    int opcao = 0, indicePilha = 0, valorInserir = 0, quantidadePilhas = 0;

    quantidadePilhas = LerNumero("Quantas pilhas deseja criar (1 a 5)? ", 1, MAX_PILHAS);
    InicializarMultiplasPilhas(&estrutura, quantidadePilhas);

    system(CLEAR_COMMAND);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Push\n\t"
            "2 - Pop\n\t"
            "3 - Peek\n\t"
            "4 - Size\n\t"
            "5 - Exibir uma Pilha\n\t"
            "6 - Exibir todas as Pilhas\n\t"
            "Selecione: ", 0, 6);

        if (opcao >= 1 && opcao <= 5)
        {
            system(CLEAR_COMMAND);

            char mensagem[80];
            snprintf(mensagem, sizeof(mensagem),
                "Selecione a pilha (1 a %d): ", quantidadePilhas);
            indicePilha = LerNumero(mensagem, 1, quantidadePilhas) - 1;
        }

        switch (opcao)
        {
            case 1:
                valorInserir = LerNumero("Digite um valor a ser inserido: ", 1, 100);
                Push(valorInserir, &estrutura.pilhas[indicePilha]);
                break;
            case 2:
                Pop(&estrutura.pilhas[indicePilha]);
                break;
            case 3:
                Peek(&estrutura.pilhas[indicePilha]);
                break;
            case 4:
                Size(&estrutura.pilhas[indicePilha]);
                break;
            case 5:
                Exibir(&estrutura.pilhas[indicePilha]);
                break;
            case 6:
                system(CLEAR_COMMAND);
                for (int i = 0; i < quantidadePilhas; i++)
                {
                    printf("Pilha %d -> ", i + 1);
                    Exibir(&estrutura.pilhas[i]);
                }
                break;
            default:
                if (opcao != 0)
                {
                    printf("Opcao Invalida!\n");
                }
        }
    } while (opcao != 0);

    DestruirMultiplasPilhas(&estrutura);
    return;
}
