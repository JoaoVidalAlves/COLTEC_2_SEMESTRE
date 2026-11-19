#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pluviometro {
    string estacao;
    vector<double> leituras;   // no lugar de double* + quantidade
public:
    Pluviometro(string e, int q) : estacao(e), leituras(q, 0.0) {}
    // sem destrutor: o vector libera a memória sozinho

    void registrar(int i, double mm) {
        if (i >= 0 && i < (int)leituras.size()) leituras[i] = mm;
    }
    double acumulado() const {
        double s = 0;
        for (double l : leituras) s += l;
        return s;
    }
    double maior() const {
        if (leituras.empty()) return 0.0;
        double m = leituras[0];
        for (double l : leituras)
            if (l > m) m = l;
        return m;
    }
    void exibir() const {
        cout << "Estacao: " << estacao << endl;
        for (size_t i = 0; i < leituras.size(); i++)
            cout << "Dia " << i + 1 << ": " << leituras[i] << " mm" << endl;
        cout << "Acumulado: " << acumulado() << " mm" << endl;
        cout << "Maior leitura: " << maior() << " mm" << endl;
    }
};

int main() {
    Pluviometro p("Pampulha", 4);
    p.registrar(0, 12.5);
    p.registrar(1, 0.0);
    p.registrar(2, 30.2);
    p.registrar(3, 8.3);
    p.exibir();
    return 0;
}
