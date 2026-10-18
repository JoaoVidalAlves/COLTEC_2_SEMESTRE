#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <string>
#include <iostream>

class Equipamento
{
protected:
	int m_patrimonio;
	std::string m_descricao;

public:
	Equipamento(int patrimonio, std::string descricao);

	~Equipamento()
	{
		std::cout << "Equipamento removido." << std::endl;
	}

	virtual void Exibir() const;
};

#endif // !EQUIPAMENTO_H
