/* ============================================================
   EXERCICIO 2 - INTERMEDIARIO
   Implemente uma estrutura contendo Duas Pilhas
   compartilhando um unico Vetor.

   Tecnica classica: a Pilha 1 cresce a partir do inicio do
   vetor (indice 0 para frente) e a Pilha 2 cresce a partir do
   final do vetor (indice TAM-1 para tras). O vetor esta cheio
   quando os dois topos se encontram.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#define TAM_VETOR 10

/* ---------------- ESTRUTURAS ---------------- */

typedef struct
{
    int vetor[TAM_VETOR];
    int topo1;   /* comeca em -1 (vazia), cresce para +infinito       */
    int topo2;   /* comeca em TAM_VETOR (vazia), cresce para -infinito */
} DuasPilhas;

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

/* ---------------- OPERACOES DAS DUAS PILHAS ---------------- */

void InicializarPilha(DuasPilhas* pilha)
{
    pilha->topo1 = -1;
    pilha->topo2 = TAM_VETOR;
}

int PilhaVazia(DuasPilhas* pilha, int numeroPilha)
{
    if (numeroPilha == 1)
        return pilha->topo1 == -1;
    else
        return pilha->topo2 == TAM_VETOR;
}

int PilhasCheias(DuasPilhas* pilha)
{
    return pilha->topo1 + 1 == pilha->topo2;
}

void Push(int valor, int numeroPilha, DuasPilhas* pilha)
{
    if (PilhasCheias(pilha))
    {
        printf("Vetor cheio! As duas pilhas se encontraram, nao e possivel inserir.\n");
        return;
    }

    if (numeroPilha == 1)
    {
        pilha->topo1++;
        pilha->vetor[pilha->topo1] = valor;
    }
    else
    {
        pilha->topo2--;
        pilha->vetor[pilha->topo2] = valor;
    }

    printf("Valor %d inserido na Pilha %d.\n", valor, numeroPilha);
}

void Pop(int numeroPilha, DuasPilhas* pilha)
{
    if (PilhaVazia(pilha, numeroPilha))
    {
        printf("Pilha %d vazia! Nao ha o que remover.\n", numeroPilha);
        return;
    }

    if (numeroPilha == 1)
    {
        printf("Valor removido da Pilha 1: %d\n", pilha->vetor[pilha->topo1]);
        pilha->topo1--;
    }
    else
    {
        printf("Valor removido da Pilha 2: %d\n", pilha->vetor[pilha->topo2]);
        pilha->topo2++;
    }
}

void Peek(int numeroPilha, DuasPilhas* pilha)
{
    if (PilhaVazia(pilha, numeroPilha))
    {
        printf("Pilha %d vazia! Nao ha topo para exibir.\n", numeroPilha);
        return;
    }

    if (numeroPilha == 1)
        printf("Topo da Pilha 1: %d\n", pilha->vetor[pilha->topo1]);
    else
        printf("Topo da Pilha 2: %d\n", pilha->vetor[pilha->topo2]);
}

void Size(int numeroPilha, DuasPilhas* pilha)
{
    if (numeroPilha == 1)
        printf("Tamanho da Pilha 1: %d\n", pilha->topo1 + 1);
    else
        printf("Tamanho da Pilha 2: %d\n", TAM_VETOR - pilha->topo2);
}

void Exibir(DuasPilhas* pilha)
{
    printf("Vetor completo (%d posicoes):\n[ ", TAM_VETOR);
    for (int i = 0; i < TAM_VETOR; i++)
    {
        int usadoPor1 = i <= pilha->topo1;
        int usadoPor2 = i >= pilha->topo2;

        if (usadoPor1)
            printf("%d(P1) ", pilha->vetor[i]);
        else if (usadoPor2)
            printf("%d(P2) ", pilha->vetor[i]);
        else
            printf("_ ");
    }
    printf("]\n");
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
        "1 = DUAS PILHAS EM UM UNICO VETOR\n"
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

    DuasPilhas pilha;
    int opcao = 0, numeroPilha = 0, valorInserir = 0;

    InicializarPilha(&pilha);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Push\n\t"
            "2 - Pop\n\t"
            "3 - Peek\n\t"
            "4 - Size\n\t"
            "5 - Exibir Vetor\n\t"
            "Selecione: ", 0, 5);

        switch (opcao)
        {
            case 1:
                system(CLEAR_COMMAND);
                numeroPilha = LerNumero("Em qual pilha deseja inserir (1 ou 2)? ", 1, 2);
                valorInserir = LerNumero("Digite um valor a ser inserido: ", 1, 100);
                Push(valorInserir, numeroPilha, &pilha);
                break;
            case 2:
                system(CLEAR_COMMAND);
                numeroPilha = LerNumero("De qual pilha deseja remover (1 ou 2)? ", 1, 2);
                Pop(numeroPilha, &pilha);
                break;
            case 3:
                system(CLEAR_COMMAND);
                numeroPilha = LerNumero("De qual pilha deseja ver o topo (1 ou 2)? ", 1, 2);
                Peek(numeroPilha, &pilha);
                break;
            case 4:
                system(CLEAR_COMMAND);
                numeroPilha = LerNumero("De qual pilha deseja ver o tamanho (1 ou 2)? ", 1, 2);
                Size(numeroPilha, &pilha);
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

    return;
}
