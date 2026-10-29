#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <string>
#include <iomanip>
#include <iostream>

using std::string;
using std::cout;

class Avaliacao
{
protected:
    string m_descricao;
    double m_peso;

public:
    Avaliacao(string descricao, double peso);

    virtual double Nota() const = 0;
    virtual string Descricao() const = 0;

    double pontos() const;
    virtual void ExibirNota() const;
    double getPeso() const;
};

#endif //AVALIACAO_H