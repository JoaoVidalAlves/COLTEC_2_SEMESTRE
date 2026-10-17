#include <iostream>
#include <iomanip>
#include "Inteira.h"

Inteira::Inteira(double valor) 
	: Ingresso(valor) {}

double Inteira::precoFinal() const
{ 
	return valorBase; 
}

void Inteira::exibir() const
{
	std::cout << "Inteira  -> R$ " << std::fixed << std::setprecision(2) << precoFinal() << std::endl;
}