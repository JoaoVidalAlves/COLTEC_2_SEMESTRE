#include <iostream>
#include "Temperatura.h"

using namespace std;

/*
 * Por que operator<< precisa ser função livre e não método de Temperatura?
 * Um método sempre é chamado pelo objeto que fica à ESQUERDA do operador.
 * Em "cout << t", o objeto da esquerda é o cout (um ostream), não a Temperatura,
 * e não podemos alterar a classe ostream. Como método, só funcionaria "t << cout".
 */

int main() {
    Temperatura a(25.0);
    Temperatura b(30.5);
    Temperatura c(18.0);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    Temperatura soma = a + b;
    Temperatura diferenca = b - c;
    cout << "a + b = " << soma << endl;
    cout << "b - c = " << diferenca << endl;

    // descobrindo a maior usando apenas o operador <
    Temperatura maior = a;
    if (maior < b) maior = b;
    if (maior < c) maior = c;
    cout << "Maior temperatura: " << maior << endl;

    // forma explícita do operador
    Temperatura somaExplicita = a.operator+(b);
    cout << "a.operator+(b) = " << somaExplicita << endl;
    if (soma == somaExplicita) {
        cout << "Resultado confirmado: as duas formas dao o mesmo valor." << endl;
    }

    return 0;
}
