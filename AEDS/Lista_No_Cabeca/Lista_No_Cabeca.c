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

typedef struct noCabeca
{
    int valor;
    struct noCabeca* prox;
}NoCabeca;

typedef struct listaCabeca
{
    NoCabeca* cabeca; //No sentinela, nunca guarda um valor de dado valido
    int tam;
}ListaCabeca;

void CriarListaCabeca(ListaCabeca* lista)
{
    lista->cabeca = malloc(sizeof(NoCabeca));

    if (lista->cabeca)
    {
        lista->cabeca->valor = 0;
        lista->cabeca->prox = NULL;
        lista->tam = 0;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirInicioCabeca(ListaCabeca* lista, int num)
{
    NoCabeca* novo = malloc(sizeof(NoCabeca));

    if (novo)
    {
        novo->valor = num;
        novo->prox = lista->cabeca->prox;
        lista->cabeca->prox = novo;
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirFimCabeca(ListaCabeca* lista, int num)
{
    NoCabeca* aux, * novo = malloc(sizeof(NoCabeca));

    if (novo)
    {
        novo->valor = num;
        novo->prox = NULL;

        aux = lista->cabeca;
        while (aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirMeioCabeca(ListaCabeca* lista, int num, int ant)
{
    NoCabeca* aux, * novo = malloc(sizeof(NoCabeca));

    if (novo)
    {
        novo->valor = num;

        //Sempre parte da cabeca -> nunca precisa tratar lista vazia
        aux = lista->cabeca;
        while (aux->prox && aux->valor != ant)
        {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void InserirOrdenadoCabeca(ListaCabeca* lista, int num)
{
    NoCabeca* aux, * novo = malloc(sizeof(NoCabeca));

    if (novo)
    {
        novo->valor = num;

        //A cabeca sempre existe, entao busca-se a posicao a partir dela
        aux = lista->cabeca;
        while (aux->prox && aux->prox->valor < num)
        {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria!");
    }
}

void ImprimirCabeca(ListaCabeca lista)
{
    NoCabeca* no = lista.cabeca->prox;

    printf("\n\tLista tamanho %d: ", lista.tam);
    while (no)
    {
        printf("%d ", no->valor);
        no = no->prox;
    }
    printf("\n");
}

NoCabeca* RemovidoCabeca(ListaCabeca* lista, int num)
{
    NoCabeca* aux, * remover = NULL;

    aux = lista->cabeca;
    while (aux->prox && aux->prox->valor != num)
    {
        aux = aux->prox;
    }

    if (aux->prox)
    {
        remover = aux->prox;
        aux->prox = remover->prox;
        lista->tam--;
    }
    return remover;
}

NoCabeca* BuscaElementoCabeca(ListaCabeca* lista, int num)
{
    NoCabeca* aux = lista->cabeca->prox;

    while (aux)
    {
        if (aux->valor == num)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void DestruirListaCabeca(ListaCabeca* lista)
{
    NoCabeca* atual = lista->cabeca->prox;
    NoCabeca* proximo;

    while (atual)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    lista->cabeca->prox = NULL;
    lista->tam = 0;
}

void atvintermediario1()
{
    system(CLEAR_COMMAND);

    int opcao = 0, valor = 0, anterior = 0;
    NoCabeca* remover = NULL;

    ListaCabeca lista;

    CriarListaCabeca(&lista);

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
            InserirInicioCabeca(&lista, valor);
            break;
        case 2:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            anterior = LerNumero("Digite o valor de referencia: ", 1, 100);
            InserirMeioCabeca(&lista, valor, anterior);
            break;
        case 3:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            InserirFimCabeca(&lista, valor);
            break;
        case 4:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            InserirOrdenadoCabeca(&lista, valor);
            break;
        case 5:
            system(CLEAR_COMMAND);
            valor = LerNumero("Digite um valor a ser removido: ", 1, 100);
            remover = RemovidoCabeca(&lista, valor);

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
            BuscaElementoCabeca(&lista, valor);
            break;
        case 7:
            system(CLEAR_COMMAND);
            DestruirListaCabeca(&lista);
            break;
        case 8:
            system(CLEAR_COMMAND);
            ImprimirCabeca(lista);
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
        "1 = Lista Com No Cabeça\n"
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