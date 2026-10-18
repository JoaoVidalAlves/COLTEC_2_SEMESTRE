#include <string>
#include <iostream>

#include "Equipamento.h"

Equipamento::Equipamento(int patrimonio, std::string descricao)
	: m_patrimonio(patrimonio < 0 ? 0 : patrimonio), m_descricao(descricao)
{
	if (patrimonio < 0)
		std::cout << "Patrimonio não pode ser negativo." << std::endl;
}

void Equipamento::Exibir() const
{
	std::cout << "Patrimonio: " << m_patrimonio << std::endl;
	std::cout << "Descrição: " << m_descricao << std::endl;
}