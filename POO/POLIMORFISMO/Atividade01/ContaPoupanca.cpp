#include <iostream>
#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(double saldo, std::string nome, double taxa)
	: ContaBancaria::ContaBancaria(saldo, nome), m_taxa(taxa < 0 ? 0 : taxa)
{
	if (taxa < 0)
		std::cout << "Taxa não pode ser menor que 0!" << std::endl;
}

double ContaPoupanca::RendimentoMensal() const
{
	return m_saldo * m_taxa;
}