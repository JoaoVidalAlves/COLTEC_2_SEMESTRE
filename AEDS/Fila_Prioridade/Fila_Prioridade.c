#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

int LerNumero(const char* mensagem, int minimo, int maximo)
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

        if (valor < minimo || valor > maximo)
        {
            printf("Valor invalido - Min %d, Max %d.\n\n",
                minimo, maximo);
            continue;
        }

        return (int)valor;
    }
}

void LerTexto(const char* mensagem, char texto[], int tamanho)
{
    while (1)
    {
        printf("%s", mensagem);

        if (fgets(texto, tamanho, stdin) == NULL)
            continue;

        if (strchr(texto, '\n') != NULL)
        {
            texto[strcspn(texto, "\n")] = '\0';
            return;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Valor invalido - Max %d caracteres.\n\n",
            tamanho - 1);
    }
}

//DECLARAR PROTOTIPOS DO MENU E ATIVIDADES
void atividade();

int main()
{
    system(CLEAR_COMMAND);

    int selecionarDificuldade = 0;

    selecionarDificuldade = LerNumero(
        "EXERCICIO FILA DE PRIORIDADE\n\n"
        "1 = FILA DE PRIORIDADE\n"
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

typedef struct no
{
    int valor;
    int prioridade;
    struct no* prox;
}No;

typedef struct fila
{
    No* inicio;
    No* fim;
    int tam;
}Fila;

void CriarFila(Fila* fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void Inserir(Fila* fila, int num, int prioridade)
{
    No* novo = malloc(sizeof(No));
    No* atual = NULL;
    No* anterior = NULL;

    if (!novo)
        return;

    novo->valor = num;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    // Fila vazia -> novo é inicio e fim
    if (fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
        fila->tam++;
        return;
    }

    // Prioridade maior que a do primeiro -> entra na frente de tudo
    if (prioridade > fila->inicio->prioridade)
    {
        novo->prox = fila->inicio;
        fila->inicio = novo;
        fila->tam++;
        return;
    }

    // Procura o ponto onde a prioridade do novo já não é mais menor
    atual = fila->inicio;
    while (atual->prox != NULL && atual->prox->prioridade >= prioridade)
    {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    // Se inseriu depois do último nó, atualiza o fim
    if (novo->prox == NULL)
        fila->fim = novo;

    fila->tam++;
}

/* Remove sempre o inicio, que é o de maior prioridade */
No* Remover(Fila* fila)
{
    No* remover = NULL;

    if (fila->inicio)
    {
        remover = fila->inicio;
        fila->inicio = remover->prox;

        if (fila->inicio == NULL)
            fila->fim = NULL;

        fila->tam--;
    }
    return remover;
}

void Imprimir(Fila fila)
{
    No* no = fila.inicio;

    printf("\n\tFila tamanho %d:\n", fila.tam);

    while (no)
    {
        printf("\t  Valor: %d | Prioridade: %d\n", no->valor, no->prioridade);
        no = no->prox;
    }
}

void ImprimirFrente(Fila fila)
{
    if (fila.inicio == NULL)
    {
        printf("\n\tFila vazia!\n");
        return;
    }
    printf("\n\tProximo a ser atendido -> Valor: %d | Prioridade: %d\n",
        fila.inicio->valor, fila.inicio->prioridade);
}

void DestruirFila(Fila* fila)
{
    No* atual = fila->inicio;
    No* proximo;

    while (atual)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void atividade()
{
    system(CLEAR_COMMAND);

    int opcao = 0, valor = 0, prioridade = 0;
    No* remover = NULL;

    Fila fila;

    CriarFila(&fila);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Inserir\n\t"
            "2 - Remover (atender o mais prioritario)\n\t"
            "3 - Percorrer\n\t"
            "4 - Consultar Frente\n\t"
            "5 - Destruir Fila\n\t"
            "Selecione: ", 0, 5);

        switch (opcao)
        {
        case 1:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            prioridade = LerNumero("Digite a prioridade (1 a 10, sendo 10 mais urgente): ", 1, 10);
            Inserir(&fila, valor, prioridade);
            break;
        case 2:
            system(CLEAR_COMMAND);
            remover = Remover(&fila);
            if (remover)
            {
                printf("Atendido -> Valor: %d | Prioridade: %d\n",
                    remover->valor, remover->prioridade);
                free(remover);
            }
            else
            {
                printf("Fila vazia!\n");
            }
            break;
        case 3:
            system(CLEAR_COMMAND);
            Imprimir(fila);
            break;
        case 4:
            system(CLEAR_COMMAND);
            ImprimirFrente(fila);
            break;
        case 5:
            system(CLEAR_COMMAND);
            DestruirFila(&fila);
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