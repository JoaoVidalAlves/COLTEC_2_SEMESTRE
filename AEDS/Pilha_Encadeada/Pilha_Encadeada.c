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
    char* topo;
    long valor;

    while (1)
    {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            continue;

        /* Remove o '\n' */
        entrada[strcspn(entrada, "\n")] = '\0';

        /* Converte para número */
        valor = strtol(entrada, &topo, 10);

        /* Verifica se toda a entrada era numérica */
        if (*entrada == '\0' || *topo != '\0')
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
        "EXERCICIO PILHA\n\n"
        "1 = PILHA LISTA ENCADEADA\n"
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

void atividade()
{
    system(CLEAR_COMMAND);

    int opcao = 0, valorInserir = 0;

    InicializarPilha(&pilha);

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Push\n\t"
            "2 - Pop\n\t"
            "3 - Peek\n\t"
            "4 - Size\n\t"
            "Selecione: ", 0, 4);

        switch (opcao)
        {
            case 1:
                system(CLEAR_COMMAND);
                valorInserir = LerNumero("Digite um valor a ser inserido: ", 1, 100);
                Push(valorInserir, &pilha);
                break;
            case 2:
                system(CLEAR_COMMAND);
                Pop(&pilha);
                break;
            case 3:
                system(CLEAR_COMMAND);
                Peek(&pilha);
                break;
            case 4:
                system(CLEAR_COMMAND);
                Size(&pilha);
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