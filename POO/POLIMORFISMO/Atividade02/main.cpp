#include <iostream>
#include <iomanip>

#include "Cortesia.h"
#include "Meia.h"
#include "Inteira.h"

int main()
{
	Inteira i1(50), i2(50);
	Meia m1(50), m2(50);
	Cortesia c1(50), c2(50);

	Ingresso* ingressos[6] = { &i1, &m1, &c1, &i2, &m2, &c2 };

	double total = 0;
	for (int i = 0; i < 6; i++)
	{
		ingressos[i]->exibir();
		total += ingressos[i]->precoFinal();
	}

	std::cout << "\nArrecadacao total: R$ " << std::fixed << std::setprecision(2)
		<< total << std::endl;

	/*
	RESPOSTA: o que precisaria mudar no laco para aceitar um novo tipo de ingresso?
	
	Nada. O laco continua identico. Ele so conhece o tipo declarado (Ingresso*),
	e a ligacao dinamica escolhe, em tempo de execucao, o exibir() e o
	precoFinal() do tipo real de cada objeto.
	
	Para criar, por exemplo, a classe Estudante, basta:
	  1) criar a classe derivada de Ingresso com precoFinal() e exibir() com override;
	  2) colocar um objeto dela no array.
	
	Sem polimorfismo, o laco teria um if / else if para cada tipo
	(if tipo == INTEIRA ... else if tipo == MEIA ...), e cada novo tipo exigiria
	editar esse laco e todos os outros iguais a ele.
	*/

	return 0;
}