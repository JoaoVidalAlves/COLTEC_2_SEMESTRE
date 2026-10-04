#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta
{
private:
    double m_taxaRendimento;
    double m_saldoAntesRendimento;

public:
    ContaPoupanca(std::string titular, int numero, float saldo, double taxa);

    float RenderJuros();

    void Exibir() const;
   
};

#endif

