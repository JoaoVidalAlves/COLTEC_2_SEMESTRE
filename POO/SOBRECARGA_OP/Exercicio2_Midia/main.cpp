#include <iostream>
#include "Midia.h"
#include "Musica.h"
#include "Filme.h"
#include "Serie.h"

using namespace std;

int main() {
    const int N = 5;

    // um único array de ponteiros da classe base apontando para tipos variados
    Midia* catalogo[N] = {
        new Musica("Bohemian Rhapsody", 6),
        new Filme("Interestelar", 169, "Christopher Nolan"),
        new Serie("Breaking Bad", 47, 62),
        new Musica("Imagine", 3),
        new Filme("Cidade de Deus", 130, "Fernando Meirelles")
    };

    int total = 0;
    const Midia* maisLonga = catalogo[0];

    // percorre o array uma única vez: imprime, soma e procura a mais longa
    for (int i = 0; i < N; i++) {
        Midia* midia = catalogo[i];
        cout << *midia << endl;

        total += midia->duracaoMinutos();
        if (midia->duracaoMinutos() > maisLonga->duracaoMinutos()) {
            maisLonga = midia;
        }
    }

    cout << "\nDuracao total do catalogo: " << total << " min" << endl;
    cout << "Midia mais longa: " << *maisLonga << endl;

    // libera a memória (o destrutor virtual garante a destruição correta)
    for (int i = 0; i < N; i++) {
        delete catalogo[i];
    }

    return 0;
}
