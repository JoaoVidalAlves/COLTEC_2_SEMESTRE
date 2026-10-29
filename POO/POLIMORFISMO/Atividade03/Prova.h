#ifndef PROVA_H
#define PROVA_H

#include "Avaliacao.h"

class Prova : public Avaliacao
{
protected:
    double m_pontuacao;

public:
    Prova(string descricao, double peso, double pontuacao);

    double Nota() const override;

    string Descricao() const override;
};

#endif //PROVA_H