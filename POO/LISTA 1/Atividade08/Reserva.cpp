#include "Reserva.h"
#include <iostream>

using namespace std;

Reserva::Reserva(string nomeHospede, int numeroQuarto, int diarias, float precoPorDiaria)
{
	bool valido = true;

	if (numeroQuarto < 1 || numeroQuarto > 10)
	{
		cout << "Numero de quarto invalido para " << nomeHospede << '\n';
		valido = false;
	}

	if (diarias < 1)
	{
		cout << "Numero de diarias invalido para " << nomeHospede << '\n';
		valido = false;
	}

	if (precoPorDiaria <= 0)
	{
		cout << "Preco por diaria invalido para " << nomeHospede << '\n';
		valido = false;
	}

	m_nomeHospede = nomeHospede;

	if (valido)
	{
		m_numeroQuarto = numeroQuarto;
		m_diarias = diarias;
		m_precoPorDiaria = precoPorDiaria;
	}
	else
	{
		cout << "Reserva de " << nomeHospede << " criada com valores padrao" << '\n';
		m_numeroQuarto = 1;
		m_diarias = 1;
		m_precoPorDiaria = 0;
	}
}

float Reserva::valorTotal()
{
	return m_diarias * m_precoPorDiaria;
}

void Reserva::extrato()
{
	cout << "Hospede: " << m_nomeHospede << '\n';
	cout << "Quarto: " << m_numeroQuarto << '\n';
	cout << "Diarias: " << m_diarias << '\n';
	cout << "Preco por diaria: " << m_precoPorDiaria << '\n';
	cout << "Valor total: " << valorTotal() << '\n';
}

void Reserva::prorrogar(int dias)
{
	if (dias <= 0)
	{
		cout << "Quantidade de dias invalida para prorrogacao" << '\n';
	}
	else
	{
		m_diarias += dias;
	}
}

int Reserva::getDiarias()
{
	return m_diarias;
}

string Reserva::getNomeHospede()
{
	return m_nomeHospede;
}

void maisLonga(Reserva& a, Reserva& b)
{
	if (a.getDiarias() > b.getDiarias())
	{
		cout << "Reserva de " << a.getNomeHospede() << " e mais longa" << '\n';
	}
	else if (b.getDiarias() > a.getDiarias())
	{
		cout << "Reserva de " << b.getNomeHospede() << " e mais longa" << '\n';
	}
	else
	{
		cout << "As reservas de " << a.getNomeHospede() << " e " << b.getNomeHospede() << " tem a mesma duracao" << '\n';
	}
}
