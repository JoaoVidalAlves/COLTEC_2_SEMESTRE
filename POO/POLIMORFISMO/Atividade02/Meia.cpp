#include <iostream>
#include <iomanip>
#include "Meia.h"

Meia::Meia(double valor) 
	: Ingresso(valor) {}

double Meia::precoFinal() const
{
	return valorBase / 2; 
}

void Meia::exibir() const
{
	std::cout << "Meia     -> R$ " << std::fixed << std::setprecision(2) << precoFinal() << std::endl;
}