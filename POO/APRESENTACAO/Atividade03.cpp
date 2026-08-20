#include <iostream>

using namespace std;

class Termometro
{
public:
    void MedirTemperatura(float temperatura)
    {
        if (temperatura < 15)
        {
            cout << "Temperatura: " << temperatura << " C - FRIO";
        } else if (temperatura >= 15 && temperatura <= 25)
        {
            cout << "Temperatura: " << temperatura << " C - AGRADAVEL";
        } else if (temperatura > 25)
        {
            cout << "Temperatura: " << temperatura << " C - QUENTE";
        }
    }

    void VerificarFebre(float temperatura)
    {
        if (temperatura <= 37.5)
        {
            cout << "Temperatura: " << temperatura << " C - NORMAL";
        } else
        {
            cout << "Temperatura: " << temperatura << " C - FEBRE";
        }
    }
};

int main ()
{
    Termometro temperatura;

    float valor;

    cin >> valor;

    temperatura.MedirTemperatura(valor);

    cout << "\n";

    temperatura.VerificarFebre(valor);

    return 0;
}