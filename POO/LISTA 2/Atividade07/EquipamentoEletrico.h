#ifndef EQUIPAMENTOELETRICO_H
#define EQUIPAMENTOELETRICO_H

#include <string>
#include <iostream>
#include "Equipamento.h"

class EquipamentoEletrico : public Equipamento
{
private:
	double m_tensaoNominal;

public:
	EquipamentoEletrico(int patrimonio, std::string descricao, double tensaoNominal);

	~EquipamentoEletrico()
	{
		std::cout << "Equipamento Eletrico removido." << std::endl;
	}

	virtual void Exibir() const override;
};

#endif // !EQUIPAMENTO_H
