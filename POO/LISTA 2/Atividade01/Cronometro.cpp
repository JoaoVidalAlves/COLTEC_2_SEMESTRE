#include <iostream>
#include <string>

#include "Cronometro.h"

Cronometro::Cronometro(std::string rotulo)
	: m_segundos(0), m_rotulo(rotulo) {}

int Cronometro::getSegundos() const
{
	return m_segundos;
}

std::string Cronometro::getRotulo() const
{
	return m_rotulo;
}

void Cronometro::Avancar(int passo)
{
	if (passo < 0)
	{
		std::cout << "Valor invalido" << std::endl;
		return;
	}
	else
	{
		m_segundos += passo;
		std::cout << "Cronometro avançado em: " << passo << " segundos" << std::endl;
	}
}

void Cronometro::Exibir()
{
	std::cout << "Rotulo: " << m_rotulo << std::endl;
	std::cout << m_segundos << " Segundos" << std::endl;
}

void Cronometro::Exibir(bool h_m_s)
{
	if (h_m_s)
	{
		int horas = m_segundos / 3600;           // 1 hora = 3600 segundos
		int resto = m_segundos % 3600;           // Resto da divisão por hora
		int minutos = resto / 60;                   // 1 minuto = 60 segundos
		int segundos = resto % 60;                  // Segundos restantes

		std::cout << "Rotulo: " << m_rotulo << std::endl;
		std::cout << horas << "h " << minutos << "m " << segundos << "s" << std::endl;
	}
	else
		Exibir();
}

void Cronometro::Relatar(const Cronometro& c)
{
	std::cout << "Rotulo: " << getRotulo() << std::endl;
	std::cout << getSegundos() << " Segundos" << std::endl;
}

