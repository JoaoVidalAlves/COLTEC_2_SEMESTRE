#include <iostream>

using namespace std;

class Cofre 
{
private:
    float total;

public:
    Cofre() 
    {
        total = 0.0f;
    }

    void guardar(float valor) 
    {
        if (valor > 0) 
        {
            total += valor;
            cout << "Guardado: R$ " << valor << endl;
        }
        else 
        {
            cout << "Valor invalido! So e permitido guardar valores positivos." << endl;
        }
    }

    void retirar(float valor) 
    {
        if (valor <= 0) 
        {
            cout << "Valor invalido! So e permitido retirar valores positivos." << endl;
        }
        else if (valor > total) 
        {
            cout << "Saldo insuficiente! Total disponivel: R$ " << total << endl;
        }
        else {
            total -= valor;
            cout << "Retirado: R$ " << valor << endl;
        }
    }

    float getTotal() 
    {
        return total;
    }
};

int main() 
{
    Cofre cofre;

    cofre.guardar(100.0f);
    cofre.guardar(50.0f);
    cofre.guardar(-20.0f);

    cofre.retirar(30.0f);
    cofre.retirar(1000.0f);

    cout << "\nValor final no cofre: R$ " << cofre.getTotal() << endl;

    return 0;
}