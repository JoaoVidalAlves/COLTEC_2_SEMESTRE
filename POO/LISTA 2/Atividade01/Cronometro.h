#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include <string>

class Cronometro
{
private:
	int m_segundos;
	std::string m_rotulo;

public:
	Cronometro(std::string rotulo);

	int getSegundos() const;

	std::string getRotulo() const;

	void Avancar(int passo = 1);

	void Exibir();

	void Exibir(bool h_m_s);

	void Relatar(const Cronometro& c);
};

#endif // !CRONOMETRO_H
