#include <iostream>
#include <iomanip>
#include "Ingresso.h"

Ingresso::Ingresso(double valor) 
	: valorBase(valor < 0 ? 0 : valor) {}

double Ingresso::precoFinal() const
{ 
	return valorBase; 
}

void Ingresso::exibir() const
{
	std::cout << "Ingresso -> R$ " << std::fixed << std::setprecision(2) << precoFinal() << std::endl;
}
