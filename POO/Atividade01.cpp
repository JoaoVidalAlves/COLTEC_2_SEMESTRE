#include <iostream>

using namespace std;

int main()
{
float x = 1;
float maiorNota = 0;
float menorNota = 0;
float mediaNotas = 0;
int contador = 0;

while (x > 0)
{
    cout << "Digite uma nota (menor que 0 encerra) encerra: ";
    cin >> x;

    if (x < 0)
    {
        mediaNotas /= contador;
        break;
    }

    mediaNotas += x;
    contador++;

    if (contador == 1)
    {
        menorNota = x;
        maiorNota = menorNota;
        continue;
    }

    if (x > maiorNota)
    {
        maiorNota = x;
    }

    if (x < menorNota)
    {
        menorNota = x;
    }
}    

cout << "Maior nota: " << maiorNota << endl;
cout << "Menor nota " << menorNota << endl;
cout << "Media: " << mediaNotas << endl;
cout << "Encerrando..." << endl;

    return 0;
}