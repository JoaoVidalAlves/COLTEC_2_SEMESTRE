#include <string>
#include <iostream>

#include "EquipamentoEletrico.h"

EquipamentoEletrico::EquipamentoEletrico(int patrimonio, std::string descricao, double tensaoNominal)
	: Equipamento(patrimonio, descricao), m_tensaoNominal(tensaoNominal < 0 ? 0 : tensaoNominal)
{
	if (tensaoNominal < 0)
		std::cout << "Tensao Nominal não pode ser negativo." << std::endl;
}

void EquipamentoEletrico::Exibir() const
{
	Equipamento::Exibir();
	std::cout << "Tensao Nominal: " << m_tensaoNominal << std::endl;
}