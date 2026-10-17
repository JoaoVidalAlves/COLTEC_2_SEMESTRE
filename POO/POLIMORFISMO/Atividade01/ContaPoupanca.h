#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "ContaBancaria.h"

class ContaPoupanca : public ContaBancaria
{
private:
	double m_taxa;

public:
	ContaPoupanca(double saldo, std::string nome, double taxa);

	double RendimentoMensal() const override;
};

#endif