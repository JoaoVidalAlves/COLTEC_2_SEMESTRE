#include <iostream>
#include <string>

#include "Cronometro.h"

int main()
{
	Cronometro cr1("Cronometro A");
	cr1.Avancar();
	std::cout << "==============" << std::endl;
	cr1.Exibir();
	std::cout << "==============" << std::endl;
	cr1.Exibir(true);
	std::cout << "==============" << std::endl;
	cr1.Relatar(cr1);
	std::cout << "==============" << std::endl;

	Cronometro cr2("Cronometro B");
	cr2.Avancar(10000);
	std::cout << "==============" << std::endl;
	cr2.Exibir();
	std::cout << "==============" << std::endl;
	cr2.Exibir(true);
	std::cout << "==============" << std::endl;
	cr2.Relatar(cr2);
	std::cout << "==============" << std::endl;

	return 0;
}