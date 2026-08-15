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
    while(1)
    {
        system("CLEAR_COMMAND");

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
                menuFacil();
            }
            break;

            case 2: 
            {
                menuIntermediario();
            }
            break;

            case 3: 
            {
                menuDificil();
            }
            break;

            default: 
            {
                printf("Selecione uma dificuldade valida.");
                continue;
            }
        }
    }
}

//PROTOTIPO DAS DIFICULDADES
void menuFacil() 
{
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
    return;
}
void atvfacil2()
{
    return;
}
void atvfacil3()
{
    return;
}
void atvfacil4()
{
    return;
}
void atvfacil5()
{
    return;
}

void atvintermediario1()
{
    return;
}
void atvintermediario2()
{
    return;
}
void atvintermediario3()
{
    return;
}
void atvintermediario4()
{
    return;
}
void atvintermediario5()
{
    return;
}

void atvdificil1()
{
    return;
}
void atvdificil2()
{
    return;
}
void atvdificil3()
{
    return;
}
void atvdificil4()
{
    return;
}
void atvdificil5()
{
    return;
}