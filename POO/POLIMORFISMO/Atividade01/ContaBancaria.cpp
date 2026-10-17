#include <iostream>
#include <string>
#include "ContaBancaria.h"

double ContaBancaria::RendimentoMensal() const
{
	return 0;
}

ContaBancaria::ContaBancaria(double saldo, std::string nome)
	: m_saldo(saldo < 0 ? 0 : saldo), m_titular(nome)
{
	if (saldo < 0)
		std::cout << "Saldo não pode ser menor que 0." << std::endl;
}

void ContaBancaria::CompararConta(const ContaBancaria& outra) const
{
	RendimentoMensal() > outra.RendimentoMensal() 
	? std::cout << "Conta de " << m_titular << " rende mais" << std::endl 
	: RendimentoMensal() == outra.RendimentoMensal() 
	? std::cout << "O rendimento de ambas as contas são iguais." << std::endl
	: std::cout << "Conta de " << outra.m_titular << " rende mais" << std::endl;
}

void ContaBancaria::Extrato() const
{
	std::cout << "Titular: " << m_titular << std::endl;
	std::cout << "Saldo: R$ " << m_saldo << std::endl;
	std::cout << "Rendimento: R$ " << RendimentoMensal() << std::endl;
	std::cout << "\n";
}