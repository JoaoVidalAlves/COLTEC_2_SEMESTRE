#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

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
void menuFacil();
void menuIntermediario();
void menuDificil();

void atvfacil1();
void atvfacil2();
void atvfacil3();
void atvfacil4();
void atvfacil5();

void atvintermediario1();
void atvintermediario2();
void atvintermediario3();
void atvintermediario4();
void atvintermediario5();

void atvdificil1();
void atvdificil2();
void atvdificil3();
void atvdificil4();
void atvdificil5();

//PROTOTIPO DO MENU
int selecionarDificuldade = 0;

int main()
{
    system(CLEAR_COMMAND);

    selecionarDificuldade = LerNumero(
        "EXERCICIOS DE LISTAS ENCADEADAS\n\n"
        "Selecione a dificuldade\n"
        "1 = FACIL\n"
        "2 = INTERMEDIARIO\n"
        "3 = DIFICIL\n"
        "Selecione: ", 1, 3);

    switch (selecionarDificuldade)
    {
    case 1:
    {
        system(CLEAR_COMMAND);
        menuFacil();
    }
    break;

    case 2:
    {
        system(CLEAR_COMMAND);
        menuIntermediario();
    }
    break;

    case 3:
    {
        system(CLEAR_COMMAND);
        menuDificil();
    }
    break;

    default:
    {
        printf("Selecione uma dificuldade valida.");
    }
    }
    return 0;
}

//PROTOTIPO DAS DIFICULDADES
void menuFacil()
{
    system(CLEAR_COMMAND);

    selecionarDificuldade = LerNumero(
        "EXERCICIOS FACEIS\n\n"
        "1 = Lista Encadeada Simples\n"
        "2 = Lista Encadeada Ordenada\n"
        "Selecione: ", 1, 2);

    switch (selecionarDificuldade)
    {
    case 1:
    {
        atvfacil1();
    }
    break;

    case 2:
    {
        atvfacil2();
    }
    break;

    default:
    {
        printf("Selecione um exercicio valido");
    }
    }
}

void menuIntermediario()
{
    system(CLEAR_COMMAND);

    selecionarDificuldade = LerNumero(
        "EXERCICIOS INTERMEDIARIOS\n\n"
        "1 = Lista Circular\n"
        "2 = Lista Duplamente Encadeada\n"
        "3 = Lista Circular Duplamente Encadeada\n"
        "4 = Lista com No Cabeca\n"
        "Selecione: ", 1, 4);

    switch (selecionarDificuldade) {
    case 1:
    {
        atvintermediario1();
    }
    break;

    case 2:
    {
        atvintermediario2();
    }
    break;

    case 3:
    {
        atvintermediario3();
    }
    break;

    case 4:
    {
        atvintermediario4();
    }
    break;

    default:
    {
        printf("Selecione um exercicio valido");
    }
    }
}

void menuDificil()
{
    system(CLEAR_COMMAND);

    selecionarDificuldade = LerNumero(
        "EXERCICIOS DIFICEIS\n\n"
        "1 = Agenda de Contatos\n"
        "2 = Gerenciamento de Biblioteca\n"
        "3 = Mapa de Rotas entre Cidades\n"
        "4 = Rede Social\n"
        "Selecione: ", 1, 4);

    switch (selecionarDificuldade)
    {
    case 1:
    {
        atvdificil1();
    }
    break;

    case 2:
    {
        atvdificil2();
    }
    break;

    case 3:
    {
        atvdificil2();
    }
    break;

    case 4:
    {
        atvdificil2();
    }
    break;

    default:
    {
        printf("Selecione um exercicio valido");
    }
    }
}

void atvfacil1()
{
    system(CLEAR_COMMAND);

    typedef struct no
    {
        int valor;
        struct no* prox;
    }No;

    void InserirNoInicio(No * *lista, int num)
    {
        No* novo = malloc(sizeof(No));

        if (novo)
        {
            novo->valor = num;
            novo->prox = *lista;
            *lista = novo;
        }
        else
        {
            printf("Erro ao alocar memoria!");
        }
    }

    void InserirNoFim(No * *lista, int num)
    {
        No* aux, * novo = malloc(sizeof(No));

        if (novo)
        {
            novo->valor = num;
            novo->prox = NULL;

            //É o primeiro?
            if (*lista == NULL)
            {
                //Se for o primeiro aponta para o novo.
                *lista = novo;
            }
            else
            {
                //Percorre a lista para adicionar no final.
                aux = *lista;
                while (aux->prox)
                {
                    aux = aux->prox;
                }
                aux->prox = novo;
            }
        }
    }

    void InserirNoMeio(No * *lista, int num, int ant)
    {
        No* aux, * novo = malloc(sizeof(No));

        if (novo)
        {
            novo->valor = num;

            //É o primeiro?
            if (*lista == NULL)
            {
                novo->prox = NULL;
                *lista = novo;
            }
            else
            {
                aux = *lista;

                while (aux->valor != ant && aux->prox)
                {
                    aux = aux->prox;
                }
                novo->prox = aux->prox;
                aux->prox = novo;
            }
        }
        else
        {
            printf("Erro ao alocar memoria!");
        }
    }

    void Imprimir(No * no)
    {
        printf("\n\tLista: ");

        while (no)
        {
            printf("%d ", no->valor);
            no = no->prox;
        }
    }

    int opcao = 0, valor = 0, anterior = 0;
    No* lista = NULL;

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Inserir Inicio\n\t"
            "2 - Inserir Meio\n\t"
            "3 - Inserir Fim\n\t"
            "4 - Imprimir\n\t"
            "Selecione: ", 0, 4);

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
            Imprimir(lista);
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
void atvfacil2()
{
    system(CLEAR_COMMAND);
    return;
}
void atvfacil3()
{
    system(CLEAR_COMMAND);
    return;
}
void atvfacil4()
{
    system(CLEAR_COMMAND);
    return;
}
void atvfacil5()
{
    system(CLEAR_COMMAND);
    return;
}

void atvintermediario1()
{
    system(CLEAR_COMMAND);
    return;
}
void atvintermediario2()
{
    system(CLEAR_COMMAND);
    return;
}
void atvintermediario3()
{
    system(CLEAR_COMMAND);
    return;
}
void atvintermediario4()
{
    system(CLEAR_COMMAND);
    return;
}
void atvintermediario5()
{
    system(CLEAR_COMMAND);
    return;
}

void atvdificil1()
{
    system(CLEAR_COMMAND);
    return;
}
void atvdificil2()
{
    system(CLEAR_COMMAND);
    return;
}
void atvdificil3()
{
    system(CLEAR_COMMAND);
    return;
}
void atvdificil4()
{
    system(CLEAR_COMMAND);
    return;
}
void atvdificil5()
{
    system(CLEAR_COMMAND);
    return;
}