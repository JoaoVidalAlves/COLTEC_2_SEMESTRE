#include <iostream>
#include <iomanip>
#include "Cortesia.h"

Cortesia::Cortesia(double valor) 
	: Ingresso(valor) {}

double Cortesia::precoFinal() const 
{ 
	return 0;
}

void Cortesia::exibir() const
{
	std::cout << "Cortesia -> R$ " << std::fixed << std::setprecision(2)
		<< precoFinal() << std::endl;
}