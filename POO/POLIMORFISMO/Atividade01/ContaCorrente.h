#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "ContaBancaria.h"

class ContaCorrente : public ContaBancaria
{
private:
	double m_tarifa;

public:
	ContaCorrente(double saldo, std::string nome, double tarifa);

	double RendimentoMensal() const override;
};

#endif