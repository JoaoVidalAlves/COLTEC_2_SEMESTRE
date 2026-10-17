#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

class ContaBancaria
{
protected:
	std::string m_titular;
	double m_saldo;

public:
	ContaBancaria(double saldo, std::string nome);

	virtual double RendimentoMensal() const;

	void CompararConta(const ContaBancaria& outra) const;

	void Extrato() const;

	virtual ~ContaBancaria() = default;
};

#endif