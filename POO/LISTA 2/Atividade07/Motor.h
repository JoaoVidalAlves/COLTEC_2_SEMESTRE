#ifndef MOTOR_H
#define MOTOR_H

#include <string>
#include <iostream>
#include "EquipamentoEletrico.h"

class Motor : public EquipamentoEletrico
{
private:
	double m_potencia;
	int m_rotacao;

public:
	Motor(int patrimonio, std::string descricao, double tensaoNominal, double potencia, int rotacao);

	~Motor()
	{
		std::cout << "Motor removido." << std::endl;
	}

	virtual void Exibir() const override;
};

#endif // !MOTOR_H
