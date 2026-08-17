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

typedef struct noDupla
{
    int valor;
    struct noDupla* prox;
    struct noDupla* ant;
}NoDupla;

typedef struct listaDupla
{
    NoDupla* inicio;
    NoDupla* fim;
    int tam;
}ListaDupla;

void CriarListaDupla(ListaDupla* lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void InserirInicioDupla(ListaDupla* lista, int num)
{
    NoDupla* novo = malloc(sizeof(NoDupla));

    if (novo)
    {
        novo->valor = num;

        //É o primeiro?
        if (lista->inicio == NULL)
        {
            novo->prox = novo;
            novo->ant = novo;
            lista->inicio = novo;
            lista->fim = novo;
        }
        else
        {
            novo->prox = lista->inicio;
            novo->ant = lista->fim;
            lista->inicio->ant = novo;
            lista->fim->prox = novo;
            lista->inicio = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirFimDupla(ListaDupla* lista, int num)
{
    NoDupla* novo = malloc(sizeof(NoDupla));

    if (novo)
    {
        novo->valor = num;

        //É o primeiro?
        if (lista->inicio == NULL)
        {
            novo->prox = novo;
            novo->ant = novo;
            lista->inicio = novo;
            lista->fim = novo;
        }
        else
        {
            novo->prox = lista->inicio;
            novo->ant = lista->fim;
            lista->fim->prox = novo;
            lista->inicio->ant = novo;
            lista->fim = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirMeioDupla(ListaDupla* lista, int num, int ant)
{
    NoDupla* aux, * novo = malloc(sizeof(NoDupla));

    if (novo)
    {
        novo->valor = num;

        //Lista vazia -> insere no inicio
        if (lista->inicio == NULL)
        {
            InserirInicioDupla(lista, num);
            free(novo);
            return;
        }

        aux = lista->inicio;

        while (aux->valor != ant && aux->prox != lista->inicio)
        {
            aux = aux->prox;
        }

        //Se o valor de referencia for o ultimo, insere no fim
        if (aux == lista->fim && aux->valor == ant)
        {
            InserirFimDupla(lista, num);
            free(novo);
            return;
        }

        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirOrdenadoDupla(ListaDupla* lista, int num)
{
    NoDupla* aux;

    if (lista->inicio == NULL)
    {
        InserirInicioDupla(lista, num);
    }
    else if (num < lista->inicio->valor)
    {
        InserirInicioDupla(lista, num);
    }
    else
    {
        aux = lista->inicio;
        while (aux->prox != lista->inicio && num > aux->prox->valor)
        {
            aux = aux->prox;
        }

        if (aux == lista->fim)
        {
            InserirFimDupla(lista, num);
        }
        else
        {
            InserirMeioDupla(lista, num, aux->valor);
        }
    }
}

void ImprimirDupla(ListaDupla lista)
{
    NoDupla* no = lista.inicio;

    printf("\n\tLista tamanho %d: ", lista.tam);
    if (no)
    {
        do
        {
            printf("%d ", no->valor);
            no = no->prox;
        } while (no != lista.inicio);
        printf("\n");
    }
}

void ImprimirInvertidoDupla(ListaDupla lista)
{
    NoDupla* no = lista.fim;

    printf("\n\tLista invertida tamanho %d: ", lista.tam);
    if (no)
    {
        do
        {
            printf("%d ", no->valor);
            no = no->ant;
        } while (no != lista.fim);
        printf("\n");
    }
}

NoDupla* RemovidoDupla(ListaDupla* lista, int num)
{
    NoDupla* aux, * remover = NULL;

    if (lista->inicio)
    {
        //Unico elemento da lista
        if (lista->inicio == lista->fim && lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
        }
        //É o primeiro?
        else if (lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->prox;
            lista->inicio->ant = lista->fim;
            lista->fim->prox = lista->inicio;
        }
        else
        {
            aux = lista->inicio;
            while (aux != lista->fim && aux->valor != num)
            {
                aux = aux->prox;
            }

            if (aux->valor == num)
            {
                remover = aux;
                remover->ant->prox = remover->prox;
                remover->prox->ant = remover->ant;

                if (remover == lista->fim)
                {
                    lista->fim = remover->ant;
                }
            }
        }

        if (remover)
        {
            lista->tam--;
        }
    }
    return remover;
}

NoDupla* BuscaElementoDupla(ListaDupla* lista, int num)
{
    NoDupla* aux = lista->inicio;

    if (aux)
    {
        do
        {
            if (aux->valor == num)
            {
                return aux;
            }
            aux = aux->prox;
        } while (aux != lista->inicio);

    }
    return NULL;
}

void DestruirListaDupla(ListaDupla* lista)
{
    NoDupla* atual = lista->inicio;
    NoDupla* proximo;
    int i;

    if (atual)
    {
        for (i = 0; i < lista->tam; i++)
        {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void atvintermediario1()
{
    system(CLEAR_COMMAND);

    int opcao = 0, valor = 0, anterior = 0;
    NoDupla* remover = NULL;

    ListaDupla lista;

    CriarListaDupla(&lista);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Inserir Inicio\n\t"
            "2 - Inserir Meio\n\t"
            "3 - Inserir Fim\n\t"
            "4 - Inserir Ordenado\n\t"
            "5 - Remover\n\t"
            "6 - Buscar\n\t"
            "7 - Destruir Lista\n\t"
            "8 - Imprimir\n\t"
            "Selecione: ", 0, 8);

        switch (opcao)
        {
        case 1:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor: ", 1, 100);
            InserirInicioDupla(&lista, valor);
            break;
        case 2:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            anterior = LerNumero("Digite o valor de referencia: ", 1, 100);
            InserirMeioDupla(&lista, valor, anterior);
            break;
        case 3:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            InserirFimDupla(&lista, valor);
            break;
        case 4:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            InserirOrdenadoDupla(&lista, valor);
            break;
        case 5:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser removido: ", 1, 100);
            remover = RemovidoDupla(&lista, valor);

            if (remover)
            {
                printf("Elemento a ser removido: %d\n", remover->valor);
                lista.tam--;
                free(remover);
            }
            break;
        case 6:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser encontrado: ", 1, 100);
            BuscaElementoDupla(&lista, valor);
            break;
        case 7:
            system(CLEAR_COMMAND);
            DestruirListaDupla(&lista);
            break;
        case 8:
            system(CLEAR_COMMAND);
            ImprimirDupla(lista);
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

int main()
{
    system(CLEAR_COMMAND);

    int selecionarDificuldade = 0;

    selecionarDificuldade = LerNumero(
        "EXERCICIOS\n\n"
        "1 = Lista Circular Duplamente Encadeada\n"
        "Selecione: ", 1, 1);

    switch (selecionarDificuldade)
    {
    case 1:
    {
        atvintermediario1();
    }
    break;

    default:
    {
        printf("Selecione um exercicio valido");
    }
    }
    return 0;
}