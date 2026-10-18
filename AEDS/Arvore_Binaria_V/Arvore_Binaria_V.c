#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#define MAX_NOS 20

int LerNumero(const char* mensagem, int minimo)
{
    char entrada[100];
    char* fim;
    long valor;

    while (1)
    {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            continue;

        entrada[strcspn(entrada, "\n")] = '\0';
        valor = strtol(entrada, &fim, 10);

        if (*entrada == '\0' || *fim != '\0')
        {
            printf("Entrada invalida. Digite apenas numeros.\n\n");
            continue;
        }

        if (valor < minimo || valor > 2147483647L)
        {
            printf("Valor invalido - Min %d.\n\n", minimo);
            continue;
        }

        return (int)valor;
    }
}

/* DECLARAR PROTOTIPOS DO MENU E ATIVIDADES */
void atividade();

typedef struct Arvore
{
    int valores[MAX_NOS];
    int ocupado[MAX_NOS];
} Arvore;

void CriarABV(Arvore* arvore)
{
    for (int i = 0; i < MAX_NOS; i++)
        arvore->ocupado[i] = 0;
}

int BuscaABV(Arvore* arvore, int indice, int valor)
{
    if (indice >= MAX_NOS || !arvore->ocupado[indice])
        return -1;

    if (arvore->valores[indice] == valor)
        return indice;

    int encontrado = BuscaABV(arvore, indice * 2 + 1, valor);

    if (encontrado != -1)
        return encontrado;

    return BuscaABV(arvore, indice * 2 + 2, valor);
}

int InserirRaizABV(Arvore* arvore, int valor)
{
    if (arvore->ocupado[0])
    {
        printf("A arvore ja possui uma raiz.\n");
        return 0;
    }

    arvore->valores[0] = valor;
    arvore->ocupado[0] = 1;
    return 1;
}

int InserirNoABV(Arvore* arvore, int valorPai, int valor, int lado)
{
    if (BuscaABV(arvore, 0, valor) != -1)
    {
        printf("Ja existe um no com esse valor.\n");
        return 0;
    }

    int indicePai = BuscaABV(arvore, 0, valorPai);

    if (indicePai == -1)
    {
        printf("No pai nao encontrado.\n");
        return 0;
    }

    int indiceFilho;

    if (lado == 1)
        indiceFilho = indicePai * 2 + 1;
    else
        indiceFilho = indicePai * 2 + 2;

    if (indiceFilho >= MAX_NOS)
    {
        printf("Limite do vetor atingido. Nao e possivel inserir nesse local.\n");
        return 0;
    }

    if (arvore->ocupado[indiceFilho])
    {
        printf("Esse lado ja possui um filho.\n");
        return 0;
    }

    arvore->valores[indiceFilho] = valor;
    arvore->ocupado[indiceFilho] = 1;
    return 1;
}

void PercorrerABV(Arvore* arvore, int indice)
{
    if (indice >= MAX_NOS || !arvore->ocupado[indice])
        return;

    printf("%d ", arvore->valores[indice]);
    PercorrerABV(arvore, indice * 2 + 1);
    PercorrerABV(arvore, indice * 2 + 2);
}

void DestruirSubABV(Arvore* arvore, int indice)
{
    if (indice >= MAX_NOS || !arvore->ocupado[indice])
        return;

    DestruirSubABV(arvore, indice * 2 + 1);
    DestruirSubABV(arvore, indice * 2 + 2);
    arvore->ocupado[indice] = 0;
}

void DestruirABV(Arvore* arvore)
{
    for (int i = 0; i < MAX_NOS; i++)
        arvore->ocupado[i] = 0;
}

int AlturaABV(Arvore* arvore, int indice)
{
    if (indice >= MAX_NOS || !arvore->ocupado[indice])
        return -1;

    int alturaEsquerda = AlturaABV(arvore, indice * 2 + 1);
    int alturaDireita = AlturaABV(arvore, indice * 2 + 2);

    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

int QuantidadeNosABV(Arvore* arvore, int indice)
{
    if (indice >= MAX_NOS || !arvore->ocupado[indice])
        return 0;

    return 1 + QuantidadeNosABV(arvore, indice * 2 + 1)
        + QuantidadeNosABV(arvore, indice * 2 + 2);
}

int QuantidadeFolhasABV(Arvore* arvore, int indice)
{
    if (indice >= MAX_NOS || !arvore->ocupado[indice])
        return 0;

    int esquerda = indice * 2 + 1;
    int direita = indice * 2 + 2;

    if ((esquerda >= MAX_NOS || !arvore->ocupado[esquerda]) &&
        (direita >= MAX_NOS || !arvore->ocupado[direita]))
        return 1;

    return QuantidadeFolhasABV(arvore, esquerda)
        + QuantidadeFolhasABV(arvore, direita);
}

int RemoverSubABV(Arvore* arvore, int valor)
{
    int indice = BuscaABV(arvore, 0, valor);

    if (indice == -1)
        return 0;

    DestruirSubABV(arvore, indice);
    return 1;
}

void atividade()
{
    system(CLEAR_COMMAND);

    Arvore arvore;
    CriarABV(&arvore);

    int opcao = 0;

    do
    {
        opcao = LerNumero(
            "\n\t0 - Sair\n\t"
            "1 - Inserir no\n\t"
            "2 - Remover subarvore\n\t"
            "3 - Buscar elemento\n\t"
            "4 - Percorrer arvore\n\t"
            "5 - Contar nos\n\t"
            "6 - Contar folhas\n\t"
            "7 - Calcular altura\n\t"
            "8 - Destruir arvore\n\t"
            "Selecione: ", 0
        );

        switch (opcao)
        {
        case 1:
        {
            system(CLEAR_COMMAND);
            int valor = LerNumero("Digite o valor do novo no: ", 0);

            if (!arvore.ocupado[0])
            {
                InserirRaizABV(&arvore, valor);
            }
            else
            {
                int valorPai = LerNumero("Digite o valor do no pai: ", 0);
                int lado = LerNumero("Digite o lado (1 - Esquerdo, 2 - Direito): ", 1);

                while (lado != 1 && lado != 2)
                    lado = LerNumero("Opcao invalida. Digite 1 (Esquerdo) ou 2 (Direito): ", 1);

                InserirNoABV(&arvore, valorPai, valor, lado);
            }
        }
        break;

        case 2:
        {
            system(CLEAR_COMMAND);
            int valor = LerNumero("Digite o valor do no a remover: ", 0);

            if (RemoverSubABV(&arvore, valor))
                printf("Subarvore removida.\n");
            else
                printf("Valor nao encontrado!\n");
        }
        break;

        case 3:
        {
            system(CLEAR_COMMAND);
            int valor = LerNumero("Digite o valor: ", 0);
            int encontrado = BuscaABV(&arvore, 0, valor);

            if (encontrado != -1)
                printf("Valor %d encontrado na arvore!\n", arvore.valores[encontrado]);
            else
                printf("Valor nao encontrado!\n");
        }
        break;

        case 4:
        {
            system(CLEAR_COMMAND);
            PercorrerABV(&arvore, 0);
            printf("\n");
        }
        break;

        case 5:
        {
            system(CLEAR_COMMAND);
            printf("Quantidade nos: %d\n", QuantidadeNosABV(&arvore, 0));
        }
        break;

        case 6:
        {
            system(CLEAR_COMMAND);
            printf("Quantidade folhas: %d\n", QuantidadeFolhasABV(&arvore, 0));
        }
        break;

        case 7:
        {
            system(CLEAR_COMMAND);
            printf("Altura: %d\n", AlturaABV(&arvore, 0));
        }
        break;

        case 8:
        {
            system(CLEAR_COMMAND);
            DestruirABV(&arvore);
            printf("Arvore destruida.\n");
        }
        break;

        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    system(CLEAR_COMMAND);

    int selecionarExercicio = 0;

    selecionarExercicio = LerNumero(
        "EXERCICIO ARVORES\n\n"
        "1 = ARVORE BINARIA UTILIZANDO VETOR\n"
        "Selecione: ", 1);

    switch (selecionarExercicio)
    {
    case 1:
        atividade();
        break;

    default:
        printf("Selecione um exercicio valido\n");
    }

    return 0;
}
