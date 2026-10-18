#include <string>
#include <iostream>

#include "Motor.h"

Motor::Motor(int patrimonio, std::string descricao, double tensaoNominal, double potencia, int rotacao)
	: EquipamentoEletrico(patrimonio, descricao, tensaoNominal), m_potencia(potencia < 0 ? 0 : potencia), m_rotacao(rotacao < 0 ? 0 : rotacao)
{
	if (potencia < 0)
		std::cout << "Potencia não pode ser negativo." << std::endl;

	if (rotacao < 0)
		std::cout << "Rotacao não pode ser negativa." << std::endl;
}

void Motor::Exibir() const
{
	EquipamentoEletrico::Exibir();
	std::cout << "Potencia: " << m_potencia << std::endl;
	std::cout << "Rotacao: " << m_rotacao << std::endl;
}

