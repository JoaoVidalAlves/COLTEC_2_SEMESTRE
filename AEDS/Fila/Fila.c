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

        /* Remove o '\n' */
        entrada[strcspn(entrada, "\n")] = '\0';

        /* Converte para número */
        valor = strtol(entrada, &fim, 10);

        /* Verifica se toda a entrada era numérica */
        if (*entrada == '\0' || *fim != '\0')
        {
            printf("Entrada invalida. Digite apenas numeros.\n\n");
            continue;
        }

        /* Verifica intervalo */
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

        /* Se encontrou '\n', remove */
        if (strchr(texto, '\n') != NULL)
        {
            texto[strcspn(texto, "\n")] = '\0';
            return;
        }

        /* Buffer não terminou -> usuário digitou mais caracteres */
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
        "EXERCICIO FILA\n\n"
        "1 = FILA\n"
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

void InserirNoFim(Fila* fila, int num)
{
    No* aux, * novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->prox = NULL;

        //É o primeiro?
        if (fila->inicio == NULL)
        {
            //Se for o primeiro aponta para o novo.
            fila->inicio = novo;
        }
        else
        {
            //Percorre a fila para adicionar no final.
            aux = fila->inicio;
            while (aux->prox)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        fila->tam++;
    }
}

void Imprimir(Fila fila)
{
    No* no = fila.inicio;

    printf("\n\tFila tamanho %d: ", fila.tam);

    while (no)
    {
        printf("%d ", no->valor);
        no = no->prox;
    }
}

void ImprimirFrente(Fila fila)
{
    No* no = fila.inicio;

    printf("\n\tFila tamanho %d: ", fila.tam);

    printf("%d ", no->valor);
}

No* Removido(Fila* fila)
{
    No* aux, * remover = NULL, * anterior = NULL;

    if (fila->inicio)
    {
        aux = fila->inicio;
        remover = aux;
        fila->inicio = remover->prox;
    }
    return remover;
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
    fila->tam = 0;
}

void atividade()
{
    system(CLEAR_COMMAND);

    int opcao = 0, valor = 0, anterior = 0;
    No* remover = NULL;

    Fila fila;

    CriarFila(&fila);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Enfileirar\n\t"
            "2 - Desenfileirar\n\t"
            "3 - Percorrer\n\t"
            "4 - Consultar Frente\n\t"
            "5 - Destruir Fila\n\t"
            "Selecione: ", 0, 5);

        switch (opcao)
        {
        case 1:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            InserirNoFim(&fila, valor);
            break;
        case 2:
            system(CLEAR_COMMAND);
            Removido(&fila);
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