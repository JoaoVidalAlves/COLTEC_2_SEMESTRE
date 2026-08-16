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

typedef struct no
{
    int valor;
    struct no* proximo;
    struct no* anterior;
}No;

typedef struct lista
{
    No* inicio;
    No* fim;
    int tam;
}Lista;

void CriarLista(Lista* lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void InserirNoInicio(Lista* lista, int num)
{
    No* novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        novo->anterior = NULL;
        if (lista->inicio)
        {
            lista->inicio->anterior = novo;
        }
        lista->inicio = novo;
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirNoFim(Lista* lista, int num)
{
    No* aux, * novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        //É o primeiro?
        if (lista->inicio == NULL)
        {
            //Se for o primeiro aponta para o novo.
            lista->inicio = novo;
            novo->anterior = NULL;
        }
        else
        {
            //Percorre a lista para adicionar no final.
            aux = lista->inicio;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
        lista->tam++;
    }
}

void InserirNoMeio(Lista* lista, int num, int ant)
{
    No* aux, * novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;

        //É o primeiro?
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;

            while (aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            
            if (aux->proximo)
            { 
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirOrdenado(Lista* lista, int num)
{
    No* aux, * novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            lista->inicio = novo;
        }
        else if (novo->valor < lista->inicio->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio->anterior = novo;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo->anterior = novo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void Imprimir(Lista lista)
{
    No* no = lista.inicio;

    printf("\n\tLista tamanho %d: ", lista.tam);

    while (no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
}

No* Removido(Lista* lista, int num)
{
    No* aux, * remover = NULL, * anterior = NULL;

    if (lista->inicio)
    {
        if (lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            if (lista->inicio)
            {
                lista->inicio->anterior = NULL;
            }
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo && aux->proximo->valor != num)
            {
                aux = aux->proximo;
            }
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if (aux->proximo)
                {
                    aux->proximo->anterior = aux;
                }
            }
        }
    }
    return remover;
}

void BuscaElemento(Lista* lista, int num)
{
    No* no = lista->inicio;

    int posicao = 1;
    int achou = 0;

    while (no)
    {
        if (no->valor == num)
        {
            printf("Valor: %d - Posicao: %d ", no->valor, posicao);
            achou = 1;
        }

        no = no->proximo;
        posicao++;
    }

    if (!achou)
    {
        printf("Valor nao encontrado na lista.\n");
    }
}

void DestruirLista(Lista* lista)
{
    No* atual = lista->inicio;
    No* proximo;

    while (atual)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->tam = 0;
}

No* Ultimo(No* lista)
{
    No* aux = lista;
    
    while (aux->proximo)
    {
        aux = aux->proximo;
    }
    return aux;
}

void ImprimirDoUltimo(No *no)
{
    printf("\n\tLista: ");

    while (no)
    {
        printf("%d ", no->valor);
        no = no->anterior;
    }
    printf("\n\n");
}

void atv()
{
    system(CLEAR_COMMAND);

    int opcao = 0, valor = 0, anterior = 0;
    No* remover = NULL;

    Lista lista;

    CriarLista(&lista);

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
            "9 - Imprimir do ultimo\n\t"
            "Selecione: ", 0, 9);

        switch (opcao)
        {
        case 1:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor: ", 1, 100);
            InserirNoInicio(&lista, valor);
            break;
        case 2:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            anterior = LerNumero("Digite o valor de referencia: ", 1, 100);
            InserirNoMeio(&lista, valor, anterior);
            break;
        case 3:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            InserirNoFim(&lista, valor);
            break;
        case 4:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            InserirOrdenado(&lista, valor);
            break;
        case 5:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser removido: ", 1, 100);
            remover = Removido(&lista, valor);
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
            BuscaElemento(&lista, valor);
            break;
        case 7:
            system(CLEAR_COMMAND);
            DestruirLista(&lista);
            break;
        case 8:
            system(CLEAR_COMMAND);
            Imprimir(lista);
            break;
        case 9:
            system(CLEAR_COMMAND);
            ImprimirDoUltimo(Ultimo(lista.inicio));
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
        "1 = Lista Duplamente Encadeada\n"
        "Selecione: ", 1, 1);

    switch (selecionarDificuldade)
    {
    case 1:
    {
        atv();
    }
    break;

    default:
    {
        printf("Selecione um exercicio valido");
    }
    }
    return 0;
}
