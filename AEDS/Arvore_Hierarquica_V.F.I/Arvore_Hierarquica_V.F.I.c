#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif


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

typedef struct No
{
    int valor;
    struct No* primeiroFilho;
    struct No* proximoIrmao;
} No;

typedef struct Raiz
{
    No* inicio;
} Raiz;

void CriarHI(Raiz* raiz)
{
    raiz->inicio = NULL;
}

No* CriarNo(int valor)
{
    No* novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("ERRO AO ALOCAR NO\n");
        return NULL;
    }

    novo->valor = valor;
    novo->primeiroFilho = NULL;
    novo->proximoIrmao = NULL;

    return novo;
}

No* BuscaHI(No* raiz, int valor)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->valor == valor)
        return raiz;

    No* filho = raiz->primeiroFilho;

    while (filho != NULL)
    {
        No* encontrado = BuscaHI(filho, valor);

        if (encontrado != NULL)
            return encontrado;

        filho = filho->proximoIrmao;
    }

    return NULL;
}

int InserirRaizHI(Raiz* raiz, int valor)
{
    if (raiz->inicio != NULL)
    {
        printf("A arvore ja possui uma raiz.\n");
        return 0;
    }

    raiz->inicio = CriarNo(valor);
    return raiz->inicio != NULL;
}

int InserirNoHI(Raiz* raiz, int valorPai, int valor)
{
    if (BuscaHI(raiz->inicio, valor) != NULL)
    {
        printf("Ja existe um no com esse valor.\n");
        return 0;
    }

    No* pai = BuscaHI(raiz->inicio, valorPai);

    if (pai == NULL)
    {
        printf("No pai nao encontrado.\n");
        return 0;
    }

    No* novo = CriarNo(valor);

    if (novo == NULL)
        return 0;

    if (pai->primeiroFilho == NULL)
    {
        pai->primeiroFilho = novo;
    }
    else
    {
        No* filho = pai->primeiroFilho;

        while (filho->proximoIrmao != NULL)
            filho = filho->proximoIrmao;

        filho->proximoIrmao = novo;
    }

    return 1;
}

void PercorrerHI(No* raiz)
{
    if (raiz == NULL)
        return;

    printf("%d ", raiz->valor);

    No* filho = raiz->primeiroFilho;

    while (filho != NULL)
    {
        PercorrerHI(filho);
        filho = filho->proximoIrmao;
    }
}

void DestruirHI(No* raiz)
{
    if (raiz == NULL)
        return;

    No* filho = raiz->primeiroFilho;

    while (filho != NULL)
    {
        No* proximo = filho->proximoIrmao;
        filho->proximoIrmao = NULL;
        DestruirHI(filho);
        filho = proximo;
    }

    free(raiz);
}

int AlturaHI(No* raiz)
{
    if (raiz == NULL)
        return -1;

    int maiorAltura = -1;
    No* filho = raiz->primeiroFilho;

    while (filho != NULL)
    {
        int alturaFilho = AlturaHI(filho);

        if (alturaFilho > maiorAltura)
            maiorAltura = alturaFilho;

        filho = filho->proximoIrmao;
    }

    return maiorAltura + 1;
}

int QuantidadeNosHI(No* raiz)
{
    if (raiz == NULL)
        return 0;

    int total = 1;
    No* filho = raiz->primeiroFilho;

    while (filho != NULL)
    {
        total += QuantidadeNosHI(filho);
        filho = filho->proximoIrmao;
    }

    return total;
}

int QuantidadeFolhasHI(No* raiz)
{
    if (raiz == NULL)
        return 0;

    if (raiz->primeiroFilho == NULL)
        return 1;

    int total = 0;
    No* filho = raiz->primeiroFilho;

    while (filho != NULL)
    {
        total += QuantidadeFolhasHI(filho);
        filho = filho->proximoIrmao;
    }

    return total;
}

int RemoverSubHI(No** raiz, int valor)
{
    if (*raiz == NULL)
        return 0;

    if ((*raiz)->valor == valor)
    {
        No* removido = *raiz;
        *raiz = removido->proximoIrmao;
        removido->proximoIrmao = NULL;
        DestruirHI(removido);
        return 1;
    }

    if (RemoverSubHI(&(*raiz)->primeiroFilho, valor))
        return 1;

    return RemoverSubHI(&(*raiz)->proximoIrmao, valor);
}

void atividade()
{
    system(CLEAR_COMMAND);

    Raiz raiz;
    CriarHI(&raiz);

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

            if (raiz.inicio == NULL)
            {
                InserirRaizHI(&raiz, valor);
            }
            else
            {
                int valorPai = LerNumero("Digite o valor do no pai: ", 0);
                InserirNoHI(&raiz, valorPai, valor);
            }
        }
        break;

        case 2:
        {
            system(CLEAR_COMMAND);
            int valor = LerNumero("Digite o valor do no a remover: ", 0);

            if (RemoverSubHI(&raiz.inicio, valor))
                printf("Subarvore removida.\n");
            else
                printf("Valor nao encontrado!\n");
        }
        break;

        case 3:
        {
            system(CLEAR_COMMAND);
            int valor = LerNumero("Digite o valor: ", 0);
            No* encontrado = BuscaHI(raiz.inicio, valor);

            if (encontrado != NULL)
                printf("Valor %d encontrado na arvore!\n", encontrado->valor);
            else
                printf("Valor nao encontrado!\n");
        }
        break;

        case 4:
        {
            system(CLEAR_COMMAND);
            PercorrerHI(raiz.inicio);
            printf("\n");
        }
        break;

        case 5:
        {
            system(CLEAR_COMMAND);
            printf("Quantidade nos: %d\n", QuantidadeNosHI(raiz.inicio));
        }
        break;

        case 6:
        {
            system(CLEAR_COMMAND);
            printf("Quantidade folhas: %d\n", QuantidadeFolhasHI(raiz.inicio));
        }
        break;

        case 7:
        {
            system(CLEAR_COMMAND);
            printf("Altura: %d\n", AlturaHI(raiz.inicio));
        }
        break;

        case 8:
        {
            system(CLEAR_COMMAND);
            DestruirHI(raiz.inicio);
            raiz.inicio = NULL;
            printf("Arvore destruida.\n");
        }
        break;

        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    DestruirHI(raiz.inicio);
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
        "1 = ARVORE HIERARQUICA\n"
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
