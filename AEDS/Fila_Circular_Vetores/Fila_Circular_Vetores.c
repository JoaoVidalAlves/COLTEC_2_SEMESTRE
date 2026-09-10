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
        "1 = FILA CIRCULAR VETORES\n"
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

typedef struct Fila_V
{
    int valor[100];
    int inicio;
    int fim;
    int quantidade;
} Fila_V;

void InicializarFila(Fila_V* f)
{
    for (int i = 0; i < 100; i++)
    {
        f->valor[i] = 0;
    }
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

void Enfileirar(int num, Fila_V* f)
{
    if (f->quantidade == 100)
    {
        printf("Fila cheia!\n");
        return;
    }

    f->valor[f->fim] = num;
    f->fim = (f->fim + 1) % 100;
    f->quantidade++;
}

void Desenfileirar(Fila_V* f)
{
    if (f->quantidade == 0)
    {
        printf("Fila está vazia!\n");
        return;
    }

    f->inicio = (f->inicio + 1) % 100;   // anda em círculo
    f->quantidade--;
}

void Percorrer(Fila_V* f)
{
    printf("Imprimindo a fila:\n");

    for (int i = 0; i < f->quantidade; i++)
    {
        int indice = (f->inicio + i) % 100;
        printf("%d ", f->valor[indice]);
    }
    printf("\n");
}

void ConsultarFrente(Fila_V* f)
{
    if (f->quantidade == 0)
    {
        printf("Fila está vazia!\n");
        return;
    }

    printf("Imprimindo o 1º elemento:\n");
    printf("%d ", f->valor[f->inicio]);
    printf("\n");
}

void atividade()
{
    system(CLEAR_COMMAND);

    int opcao = 0, valorInserir = 0;

    Fila_V fila_v;

    InicializarFila(&fila_v);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Enfileirar\n\t"
            "2 - Desenfileirar\n\t"
            "3 - Percorrer\n\t"
            "4 - Consultar Frente\n\t"
            "Selecione: ", 0, 4);

        switch (opcao)
        {
        case 1:
            system(CLEAR_COMMAND);
            valorInserir = LerNumero("Digite um valor a ser inserido: ", 1, 100);
            Enfileirar(valorInserir, &fila_v);
            break;
        case 2:
            system(CLEAR_COMMAND);
            Desenfileirar(&fila_v);
            break;
        case 3:
            system(CLEAR_COMMAND);
            Percorrer(&fila_v);
            break;
        case 4:
            system(CLEAR_COMMAND);
            ConsultarFrente(&fila_v);
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