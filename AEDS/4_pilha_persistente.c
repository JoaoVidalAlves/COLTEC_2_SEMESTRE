/* ============================================================
   EXERCICIO 4 - INTERMEDIARIO
   Implemente uma Pilha Persistente, preservando todas as
   versoes criadas apos cada operacao de Push e Pop.

   Ideia: os nos sao imutaveis. Cada Push cria um NOVO no que
   aponta para o topo da versao anterior (sem alterar a versao
   anterior). Cada Pop apenas cria uma nova versao cujo topo e
   o "proximo" do topo atual (sem apagar nenhum no da memoria,
   ja que ele pode ser compartilhado por outra versao). Assim,
   qualquer versao antiga continua acessivel e intacta.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#define MAX_VERSOES 1000

/* ---------------- ESTRUTURAS ---------------- */

typedef struct No
{
    int valor;
    struct No* anterior; /* aponta para o no anterior (compartilhado entre versoes) */
} No;

typedef struct
{
    No* topoPorVersao[MAX_VERSOES]; /* topoPorVersao[v] = topo da pilha na versao v */
    int tamanhoPorVersao[MAX_VERSOES];
    int versaoAtual;                /* versao 0 = pilha vazia inicial */
} PilhaPersistente;

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

/* ---------------- OPERACOES DA PILHA PERSISTENTE ---------------- */

void InicializarPilha(PilhaPersistente* pilha)
{
    pilha->versaoAtual = 0;
    pilha->topoPorVersao[0] = NULL;
    pilha->tamanhoPorVersao[0] = 0;
}

int PilhaVaziaNaVersao(PilhaPersistente* pilha, int versao)
{
    return pilha->topoPorVersao[versao] == NULL;
}

void Push(int valor, PilhaPersistente* pilha)
{
    if (pilha->versaoAtual + 1 >= MAX_VERSOES)
    {
        printf("Limite maximo de versoes atingido!\n");
        return;
    }

    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    novoNo->valor = valor;
    novoNo->anterior = pilha->topoPorVersao[pilha->versaoAtual];

    pilha->versaoAtual++;
    pilha->topoPorVersao[pilha->versaoAtual] = novoNo;
    pilha->tamanhoPorVersao[pilha->versaoAtual] =
        pilha->tamanhoPorVersao[pilha->versaoAtual - 1] + 1;

    printf("Valor %d inserido. Nova versao criada: v%d\n",
        valor, pilha->versaoAtual);
}

void Pop(PilhaPersistente* pilha)
{
    if (PilhaVaziaNaVersao(pilha, pilha->versaoAtual))
    {
        printf("Pilha vazia na versao atual! Nao ha o que remover.\n");
        return;
    }

    if (pilha->versaoAtual + 1 >= MAX_VERSOES)
    {
        printf("Limite maximo de versoes atingido!\n");
        return;
    }

    No* topoAtual = pilha->topoPorVersao[pilha->versaoAtual];
    printf("Valor removido do topo: %d\n", topoAtual->valor);

    pilha->versaoAtual++;
    /* A nova versao aponta para o no ANTERIOR ao topo atual.       */
    /* O no removido continua na memoria (nao e liberado), pois     */
    /* pode ainda ser referenciado pela versao anterior.            */
    pilha->topoPorVersao[pilha->versaoAtual] = topoAtual->anterior;
    pilha->tamanhoPorVersao[pilha->versaoAtual] =
        pilha->tamanhoPorVersao[pilha->versaoAtual - 1] - 1;

    printf("Nova versao criada: v%d\n", pilha->versaoAtual);
}

void Peek(PilhaPersistente* pilha, int versao)
{
    if (PilhaVaziaNaVersao(pilha, versao))
    {
        printf("Pilha vazia na versao v%d! Nao ha topo para exibir.\n", versao);
        return;
    }

    printf("Topo da pilha na versao v%d: %d\n",
        versao, pilha->topoPorVersao[versao]->valor);
}

void Size(PilhaPersistente* pilha, int versao)
{
    printf("Tamanho da pilha na versao v%d: %d\n",
        versao, pilha->tamanhoPorVersao[versao]);
}

void ExibirVersao(PilhaPersistente* pilha, int versao)
{
    if (PilhaVaziaNaVersao(pilha, versao))
    {
        printf("Versao v%d: pilha vazia.\n", versao);
        return;
    }

    printf("Versao v%d (topo -> base): ", versao);
    No* atual = pilha->topoPorVersao[versao];
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

void ExibirTodasVersoes(PilhaPersistente* pilha)
{
    for (int v = 0; v <= pilha->versaoAtual; v++)
    {
        ExibirVersao(pilha, v);
    }
}

/* Libera toda a memoria unica alocada. Como nos podem ser        */
/* compartilhados entre versoes, percorremos a versao mais nova   */
/* (que contem a cadeia mais longa) para garantir que cada no      */
/* criado via Push seja liberado uma unica vez.                    */
void DestruirPilha(PilhaPersistente* pilha)
{
    No* atual = pilha->topoPorVersao[pilha->versaoAtual];
    while (atual != NULL)
    {
        No* proximo = atual->anterior;
        free(atual);
        atual = proximo;
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
        "1 = PILHA PERSISTENTE\n"
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

    PilhaPersistente pilha;
    int opcao = 0, valorInserir = 0, versaoConsultada = 0;

    InicializarPilha(&pilha);

    do
    {
        printf("\n(Versao atual: v%d)\n", pilha.versaoAtual);

        opcao = LerNumero(
            "\t 0 - Sair\n\t"
            "1 - Push\n\t"
            "2 - Pop\n\t"
            "3 - Peek (versao atual)\n\t"
            "4 - Size (versao atual)\n\t"
            "5 - Exibir versao especifica\n\t"
            "6 - Exibir TODAS as versoes\n\t"
            "Selecione: ", 0, 6);

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
                Peek(&pilha, pilha.versaoAtual);
                break;
            case 4:
                system(CLEAR_COMMAND);
                Size(&pilha, pilha.versaoAtual);
                break;
            case 5:
                system(CLEAR_COMMAND);
                versaoConsultada = LerNumero("Digite o numero da versao desejada: ", 0, pilha.versaoAtual);
                ExibirVersao(&pilha, versaoConsultada);
                break;
            case 6:
                system(CLEAR_COMMAND);
                ExibirTodasVersoes(&pilha);
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
