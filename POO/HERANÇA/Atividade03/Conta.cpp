#include "Conta.h"
#include <iostream>
#include <iomanip>

using namespace std;

    Conta::Conta(string titular, int numero, float saldo)
        : m_titular(titular), m_numero(numero), m_saldo(saldo < 0 ? 0 : saldo)
    {
        if (saldo < 0)
        {
            cout << "Saldo não pode ser negativo!\n";
        }
    }

    void Conta::Depositar(float valor)
    {
        if (valor <= 0)
        {
            cout << "Deposito não pode ser inferior ou igual a 0 (zero)" << "\n";
            return;
        }
        m_saldo += valor;
    }

    void Conta::Sacar(float valor)
    {
        if (valor <= 0)
        {
            cout << "Impossivel sacar menor ou igual a 0 (zero)" << "\n";
            return;
        }
        if (m_saldo < valor)
        {
            cout << "Saldo Insuficiente! R$: " << m_saldo << "\n";
            return;
        }
        m_saldo -= valor;
    }

    void Conta::Exibir() const
    {
        cout << "Titular: " << m_titular << "\n";
        cout << "Numero: " << m_numero << "\n";
        cout << "Saldo: R$ " << fixed << setprecision(2) << m_saldo << "\n";
    }