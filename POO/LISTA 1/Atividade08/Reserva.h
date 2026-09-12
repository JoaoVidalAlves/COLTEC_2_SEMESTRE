#ifndef RESERVA_H
#define RESERVA_H

#include <string>

class Reserva
{
private:
	std::string m_nomeHospede;
	int m_numeroQuarto;
	int m_diarias;
	float m_precoPorDiaria;

public:
	Reserva(std::string nomeHospede, int numeroQuarto, int diarias, float precoPorDiaria);

	float valorTotal();
	void extrato();
	void prorrogar(int dias);
	int getDiarias();
	std::string getNomeHospede();
};

void maisLonga(Reserva& a, Reserva& b);

#endif
