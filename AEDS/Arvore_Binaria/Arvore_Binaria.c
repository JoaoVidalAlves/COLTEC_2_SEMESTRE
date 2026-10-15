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

        if (valor < minimo)
        {
            printf("Valor invalido - Min %d.\n\n",
                minimo);
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
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); 
        SetConsoleCP(CP_UTF8);   
    #endif

    system(CLEAR_COMMAND);

    int selecionarExercicio = 0;

    selecionarExercicio = LerNumero(
        "EXERCICIO ARVORES\n\n"
        "1 = ARVORE BINARIA\n"
        "Selecione: ", 1);

    switch (selecionarExercicio)
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

typedef struct No 
{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

typedef struct Raiz
{
    struct No* inicio;
    int tam;
} Raiz;

void CriarArvoreB(Raiz* raiz)
{
    raiz->inicio = NULL;
    raiz->tam = 0;
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
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* Inserir(No* no, int valor)
{
    if (no == NULL)
        return CriarNo(valor);

    if (valor < no->valor)
        no->esq = Inserir(no->esq, valor);
    else
        no->dir = Inserir(no->dir, valor);

    return no;
}

void InserirNoAB(Raiz* raiz, int valor)
{
    raiz->inicio = Inserir(raiz->inicio, valor);
    raiz->tam++;
}

void PercorrerAB(No* raiz)
{
    if (raiz != NULL)
    {
        PercorrerAB(raiz->esq);
        printf("%d ", raiz->valor);
        PercorrerAB(raiz->dir);
    }
}

void DestruirArvoreB(No* raiz) 
{
    if (raiz == NULL)
        return;
    DestruirArvoreB(raiz->esq);
    DestruirArvoreB(raiz->dir);
    free(raiz);
}

int AlturaAB(No* raiz)
{
    if (raiz == NULL)
        return -1;
    else
    {
        int esq = AlturaAB(raiz->esq);
        int dir = AlturaAB(raiz->dir);
        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int QuantidadeNosAB(No* raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + QuantidadeNosAB(raiz->esq) + QuantidadeNosAB(raiz->dir);
}

int QuantidadeFolhasAB(No* raiz)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    else
        return QuantidadeFolhasAB(raiz->esq) + QuantidadeFolhasAB(raiz->dir);
}

No* RemoverSubAB(No* raiz, int valor)
{
    if (raiz == NULL)
    {
        printf("Valor não encontrado!\n");
        return NULL;
    }
    else
    {
        if (raiz->valor == valor)
        {
            if (raiz->esq == NULL && raiz->dir == NULL)
            {
                free(raiz);
                return NULL;
            }
            else
            {
                if (raiz->esq != NULL && raiz->dir != NULL)
                {
                    No* aux = raiz->esq;
                    while (aux->dir != NULL)
                        aux = aux->dir;
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esq = RemoverSubAB(raiz->esq, valor);
                    return raiz;
                }
                else
                {
                    No* aux;
                    if (raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    return aux;
                }
            }
        }
        else
        {
            if (valor < raiz->valor)
                raiz->esq = RemoverSubAB(raiz->esq, valor);
            else
                raiz->dir = RemoverSubAB(raiz->dir, valor);
            return raiz;
        }
    }
}

int BuscaAB(No* raiz, int valor)
{
    if (raiz == NULL)
    {
        printf("Valor não encontrado!\n");
        return -1;
    }
    else
    {
        if (raiz->valor == valor)
            return raiz->valor;
        else
        {
            if (valor < raiz->valor)
                return BuscaAB(raiz->esq, valor);
            else
                return BuscaAB(raiz->dir, valor);
        }
    }
}
void atividade()
{
    system(CLEAR_COMMAND);

    Raiz raiz;

    CriarArvoreB(&raiz);

    int opcao = 0;

    do
    {
        opcao = LerNumero
        (
            "\n\t0 - Sair\n\t"
            "1 - Inserir nó\n\t"
            "2 - Remover subarvore\n\t"
            "3 - Buscar elemento\n\t"
            "4 - Percorrer arvore\n\t"
            "5 - Contar nós\n\t"
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
                int valor = LerNumero("Digite o valor : ", 0);
                InserirNoAB(&raiz, valor);
            }
            break;

            case 2:
            {
                system(CLEAR_COMMAND);
                int valor = LerNumero("Digite o valor : ", 0);
                RemoverSubAB(raiz.inicio, valor);
            }
            break;

            case 3:
            {
                system(CLEAR_COMMAND);
                int valor = LerNumero("Digite o valor : ", 0);
                if(BuscaAB(raiz.inicio, valor) != -1)
                    printf("Valor %d encontrado na arvore!", BuscaAB(raiz.inicio, valor));
            }
            break;

            case 4:
            {
                system(CLEAR_COMMAND);
                PercorrerAB(raiz.inicio);
            }
            break;

            case 5:
            {
                system(CLEAR_COMMAND);
                printf("Quantidade nos: %d", QuantidadeNosAB(raiz.inicio));
            }
            break;

            case 6:
            {
                system(CLEAR_COMMAND);
                printf("Quantidade nos: %d", QuantidadeFolhasAB(raiz.inicio));
            }
            break;

            case 7:
            {
                system(CLEAR_COMMAND);
                printf("Altura: %d", AlturaAB(raiz.inicio));
            }
            break;

            case 8:
            {
                system(CLEAR_COMMAND);
                DestruirArvoreB(raiz.inicio);
                raiz.inicio = NULL;
                raiz.tam = 0;
            }
            break;

            default:
                if (opcao != 0)
                {
                    printf("Opcao Invalida!\n");
                }
        }
    } while (opcao != 0);
    
    DestruirArvoreB(raiz.inicio);
    return;
}