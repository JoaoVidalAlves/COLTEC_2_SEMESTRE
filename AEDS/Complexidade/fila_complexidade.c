/* AEDS 07 - Exercicio 1: Fila com Vetor vs Fila com Lista Encadeada
   Compilar: gcc -O0 -o fila fila_complexidade.c
   (-O0 para o compilador nao "apagar" o codigo que estamos medindo) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ---------- Tempo em nanossegundos ---------- */
static double agora_ns(void) {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1e9 + t.tv_nsec;
}

/* ================= FILA COM VETOR (circular) ================= */
typedef struct {
    int *dados;
    int inicio, fim, tamanho, capacidade;
} FilaVetor;

FilaVetor *fv_criar(int cap) {
    FilaVetor *f = malloc(sizeof(FilaVetor));
    f->dados = malloc(cap * sizeof(int));
    f->inicio = f->fim = f->tamanho = 0;
    f->capacidade = cap;
    return f;
}
int fv_inserir(FilaVetor *f, int v) {
    if (f->tamanho == f->capacidade) return 0;
    f->dados[f->fim] = v;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
    return 1;
}
int fv_remover(FilaVetor *f, int *v) {
    if (f->tamanho == 0) return 0;
    *v = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return 1;
}
void fv_liberar(FilaVetor *f) { free(f->dados); free(f); }

/* ====== FILA COM VETOR "INGENUA" (remove deslocando tudo) ====== */
typedef struct { int *dados; int tamanho, capacidade; } FilaVetorSimples;

FilaVetorSimples *fs_criar(int cap) {
    FilaVetorSimples *f = malloc(sizeof(FilaVetorSimples));
    f->dados = malloc(cap * sizeof(int));
    f->tamanho = 0; f->capacidade = cap;
    return f;
}
int fs_inserir(FilaVetorSimples *f, int v) {
    if (f->tamanho == f->capacidade) return 0;
    f->dados[f->tamanho++] = v;
    return 1;
}
int fs_remover(FilaVetorSimples *f, int *v) {
    if (f->tamanho == 0) return 0;
    *v = f->dados[0];
    memmove(f->dados, f->dados + 1, (f->tamanho - 1) * sizeof(int)); /* O(n) */
    f->tamanho--;
    return 1;
}
void fs_liberar(FilaVetorSimples *f) { free(f->dados); free(f); }

/* ================= FILA COM LISTA ENCADEADA ================= */
typedef struct No { int valor; struct No *prox; } No;
typedef struct { No *inicio, *fim; int tamanho; } FilaLista;

FilaLista *fl_criar(void) {
    FilaLista *f = malloc(sizeof(FilaLista));
    f->inicio = f->fim = NULL; f->tamanho = 0;
    return f;
}
int fl_inserir(FilaLista *f, int v) {
    No *n = malloc(sizeof(No));
    if (!n) return 0;
    n->valor = v; n->prox = NULL;
    if (f->fim) f->fim->prox = n; else f->inicio = n;
    f->fim = n;
    f->tamanho++;
    return 1;
}
int fl_remover(FilaLista *f, int *v) {
    if (!f->inicio) return 0;
    No *n = f->inicio;
    *v = n->valor;
    f->inicio = n->prox;
    if (!f->inicio) f->fim = NULL;
    free(n);
    f->tamanho--;
    return 1;
}
void fl_liberar(FilaLista *f) { int x; while (fl_remover(f, &x)); free(f); }

/* ================= MEDICOES ================= */
/* Repete o teste varias vezes nos tamanhos pequenos, pois o relogio
   nao tem precisao para medir algo que dura poucos nanossegundos. */
int repeticoes(int n) {
    if (n <= 10) return 100000;
    if (n <= 1000) return 1000;
    if (n <= 10000) return 100;
    return 1;
}

int main(void) {
    int tamanhos[] = {10, 1000, 10000, 1000000};
    int x;

    printf("%-10s | %-26s | %-14s | %-14s\n", "N", "Estrutura", "Insercao (ms)", "Remocao (ms)");
    printf("-----------+----------------------------+----------------+---------------\n");

    for (int t = 0; t < 4; t++) {
        int n = tamanhos[t];
        int rep = repeticoes(n);
        double ins, rem, ini;

        /* --- Vetor circular --- */
        ins = rem = 0;
        for (int r = 0; r < rep; r++) {
            FilaVetor *f = fv_criar(n);
            ini = agora_ns(); for (int i = 0; i < n; i++) fv_inserir(f, i); ins += agora_ns() - ini;
            ini = agora_ns(); for (int i = 0; i < n; i++) fv_remover(f, &x); rem += agora_ns() - ini;
            fv_liberar(f);
        }
        printf("%-10d | %-26s | %14.6f | %14.6f\n", n, "Vetor circular", ins/rep/1e6, rem/rep/1e6);

        /* --- Vetor ingenuo (desloca ao remover) --- */
        if (n <= 100000) {
            ins = rem = 0;
            for (int r = 0; r < rep; r++) {
                FilaVetorSimples *f = fs_criar(n);
                ini = agora_ns(); for (int i = 0; i < n; i++) fs_inserir(f, i); ins += agora_ns() - ini;
                ini = agora_ns(); for (int i = 0; i < n; i++) fs_remover(f, &x); rem += agora_ns() - ini;
                fs_liberar(f);
            }
            printf("%-10d | %-26s | %14.6f | %14.6f\n", n, "Vetor c/ deslocamento", ins/rep/1e6, rem/rep/1e6);
        } else {
            printf("%-10d | %-26s | %14s | %14s\n", n, "Vetor c/ deslocamento", "-", "(pulado: ~minutos)");
        }

        /* --- Lista encadeada --- */
        ins = rem = 0;
        for (int r = 0; r < rep; r++) {
            FilaLista *f = fl_criar();
            ini = agora_ns(); for (int i = 0; i < n; i++) fl_inserir(f, i); ins += agora_ns() - ini;
            ini = agora_ns(); for (int i = 0; i < n; i++) fl_remover(f, &x); rem += agora_ns() - ini;
            fl_liberar(f);
        }
        printf("%-10d | %-26s | %14.6f | %14.6f\n", n, "Lista encadeada", ins/rep/1e6, rem/rep/1e6);
        printf("-----------+----------------------------+----------------+---------------\n");
    }
    return 0;
}
