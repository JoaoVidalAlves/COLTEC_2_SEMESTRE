#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> catalogo = {"R-220-5", "C-100-10", "R-4700-1", "L-33-20", "R-10-5", "C-47-5"};

    // (a) quantidade
    cout << "Componentes no catalogo: " << catalogo.size() << endl;

    // (b) resistores
    int resistores = 0;
    for (size_t i = 0; i < catalogo.size(); i++)
        if (catalogo[i].substr(0, 1) == "R") resistores++;
    cout << "Resistores: " << resistores << endl;

    // (c) valor do meio
    cout << "Valores:" << endl;
    for (size_t i = 0; i < catalogo.size(); i++) {
        string cod = catalogo[i];
        size_t t1 = cod.find("-");
        size_t t2 = cod.find("-", t1 + 1);
        cout << cod << " -> " << cod.substr(t1 + 1, t2 - t1 - 1) << endl;
    }

    // (d) busca
    string procurado;
    cout << "Digite um codigo para procurar: ";
    cin >> procurado;
    int pos = -1;
    for (size_t i = 0; i < catalogo.size(); i++) {
        if (catalogo[i] == procurado) { pos = (int)i; break; }
    }
    if (pos >= 0) cout << "Encontrado na posicao " << pos << endl;
    else cout << "Codigo nao aparece no catalogo" << endl;
    return 0;
}
