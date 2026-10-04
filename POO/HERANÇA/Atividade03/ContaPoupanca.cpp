#include "ContaPoupanca.h"
#include <iostream>
#include <iomanip>

using namespace std;

    ContaPoupanca::ContaPoupanca(string titular, int numero, float saldo, double taxa)
        : Conta(titular, numero, saldo), m_taxaRendimento(taxa < 0 ? 0 : taxa), m_saldoAntesRendimento(m_saldo)
    {
        if (taxa < 0)
            cout << "Taxa não pode ser menor que 0" << "\n";
    }

    float ContaPoupanca::RenderJuros()
    {
        m_saldoAntesRendimento = m_saldo;
        m_saldo += m_saldo * (m_taxaRendimento / 100);
        return m_saldo;
    }

    void ContaPoupanca::Exibir() const
    {
        cout << "Titular: " << m_titular << "\n";
        cout << "Numero: " << m_numero << "\n";
        cout << "Taxa: " << m_taxaRendimento << "%\n";
        cout << fixed << setprecision(2);
        cout << "Saldo anterior: R$ " << m_saldoAntesRendimento << "\n";
        cout << "Saldo com juros: R$ " << m_saldo << "\n";
    }