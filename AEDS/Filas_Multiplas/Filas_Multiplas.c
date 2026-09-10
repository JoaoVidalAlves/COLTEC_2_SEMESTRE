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
        "EXERCICIO FILAS MULTIPLAS\n\n"
        "1 = ATENDIMENTO TELEFONICO\n"
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
    int senha;              // numero/identificador do cliente
    struct no* prox;
}No;

typedef struct fila
{
    No* inicio;
    No* fim;
    int tam;
    const char* nome;       // nome da fila, so para exibicao
}Fila;

void CriarFila(Fila* fila, const char* nome)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
    fila->nome = nome;
}

void Enfileirar(Fila* fila, int senha)
{
    No* novo = malloc(sizeof(No));

    if (novo)
    {
        novo->senha = senha;
        novo->prox = NULL;

        if (fila->inicio == NULL)
        {
            fila->inicio = novo;
            fila->fim = novo;
        }
        else
        {
            fila->fim->prox = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }
}

No* Desenfileirar(Fila* fila)
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

int FilaVazia(Fila* fila)
{
    return fila->inicio == NULL;
}

void Imprimir(Fila* fila)
{
    No* no = fila->inicio;

    printf("\n\t%s (tamanho %d): ", fila->nome, fila->tam);

    if (no == NULL)
    {
        printf("(vazia)");
        return;
    }

    while (no)
    {
        printf("%d ", no->senha);
        no = no->prox;
    }
}

void ImprimirFrente(Fila* fila)
{
    if (fila->inicio == NULL)
    {
        printf("\n\t%s: fila vazia!\n", fila->nome);
        return;
    }
    printf("\n\t%s -> proximo da vez: %d\n", fila->nome, fila->inicio->senha);
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

/* ---------- Politica de atendimento entre as 3 filas ----------
   Prioridade fixa: Preferencial > Convencional > Tecnico.
   So passa para a proxima fila se a anterior estiver vazia. */
No* Atender(Fila* preferencial, Fila* convencional, Fila* tecnico)
{
    if (!FilaVazia(preferencial))
        return Desenfileirar(preferencial);

    if (!FilaVazia(convencional))
        return Desenfileirar(convencional);

    if (!FilaVazia(tecnico))
        return Desenfileirar(tecnico);

    return NULL; // nenhuma fila tem cliente
}

void atividade()
{
    system(CLEAR_COMMAND);

    int opcao = 0, senha = 0, tipoFila = 0, proximaSenha = 1;
    No* atendido = NULL;

    Fila preferencial, convencional, tecnico;

    CriarFila(&preferencial, "Atendimento Preferencial");
    CriarFila(&convencional, "Atendimento Convencional");
    CriarFila(&tecnico, "Atendimento Tecnico");

    do
    {
        opcao = LerNumero(
            "\n\t 0 - Sair\n\t"
            "1 - Entrar na fila (gerar senha)\n\t"
            "2 - Atender proximo cliente (segue a politica)\n\t"
            "3 - Percorrer todas as filas\n\t"
            "4 - Consultar frente de todas as filas\n\t"
            "5 - Destruir todas as filas\n\t"
            "Selecione: ", 0, 5);

        switch (opcao)
        {
        case 1:
            system(CLEAR_COMMAND);
            tipoFila = LerNumero(
                "Tipo de atendimento:\n"
                "1 - Preferencial\n"
                "2 - Convencional\n"
                "3 - Tecnico\n"
                "Selecione: ", 1, 3);

            senha = proximaSenha++;

            switch (tipoFila)
            {
            case 1:
                Enfileirar(&preferencial, senha);
                printf("Senha %d gerada para Atendimento Preferencial.\n", senha);
                break;
            case 2:
                Enfileirar(&convencional, senha);
                printf("Senha %d gerada para Atendimento Convencional.\n", senha);
                break;
            case 3:
                Enfileirar(&tecnico, senha);
                printf("Senha %d gerada para Atendimento Tecnico.\n", senha);
                break;
            }
            break;

        case 2:
            system(CLEAR_COMMAND);
            atendido = Atender(&preferencial, &convencional, &tecnico);
            if (atendido)
            {
                printf("Chamando senha %d para atendimento!\n", atendido->senha);
                free(atendido);
            }
            else
            {
                printf("Nao ha clientes em nenhuma fila.\n");
            }
            break;

        case 3:
            system(CLEAR_COMMAND);
            Imprimir(&preferencial);
            Imprimir(&convencional);
            Imprimir(&tecnico);
            printf("\n");
            break;

        case 4:
            system(CLEAR_COMMAND);
            ImprimirFrente(&preferencial);
            ImprimirFrente(&convencional);
            ImprimirFrente(&tecnico);
            break;

        case 5:
            system(CLEAR_COMMAND);
            DestruirFila(&preferencial);
            DestruirFila(&convencional);
            DestruirFila(&tecnico);
            printf("Todas as filas foram destruidas.\n");
            break;

        default:
            if (opcao != 0)
            {
                printf("Opcao Invalida!\n");
            }
        }
    } while (opcao != 0);

    DestruirFila(&preferencial);
    DestruirFila(&convencional);
    DestruirFila(&tecnico);

    return;
}