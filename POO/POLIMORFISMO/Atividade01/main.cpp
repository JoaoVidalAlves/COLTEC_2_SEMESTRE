#include <iostream>
#include "ContaPoupanca.h"
#include "ContaCorrente.h"

int main() 
{
	ContaPoupanca contaP1(1000, "Ana", 0.005f), contaP2(5000, "Carla", 0.010f);
	ContaCorrente contaC1(1000, "Bruno", 30);

	ContaBancaria* contas[3] = { &contaP1, &contaP2, &contaC1 };
	for (int i = 0; i < 3; i++)
		contas[i]->Extrato();

	contaP1.CompararConta(contaP2);
	contaP1.CompararConta(contaC1);

	return 0;
}