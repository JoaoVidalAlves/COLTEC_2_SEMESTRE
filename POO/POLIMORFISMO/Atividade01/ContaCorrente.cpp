#include <iostream>
#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(double saldo, std::string nome, double tarifa)
	: ContaBancaria::ContaBancaria(saldo, nome), m_tarifa(tarifa < 0 ? 0 : tarifa)
{
	if (tarifa < 0)
		std::cout << "Tarifa não pode ser menor que 0." << std::endl;
}

double ContaCorrente::RendimentoMensal() const
{
	return -m_tarifa;
}
