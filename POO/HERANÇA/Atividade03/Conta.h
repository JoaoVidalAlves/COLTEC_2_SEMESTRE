#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta
{
protected:
    std::string m_titular;
    int m_numero;
    float m_saldo;

public:
    Conta(std::string titular, int numero, float saldo);

    void Depositar(float valor);

    void Sacar(float valor);

    void Exibir() const;
   
};

#endif