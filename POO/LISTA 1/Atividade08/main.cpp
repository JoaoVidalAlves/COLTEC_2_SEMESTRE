#include <iostream>
#include <windows.h>
#include "Reserva.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Reserva reservas[3] =
	{
		Reserva("Ana", 3, 4, 150.0f),
		Reserva("Bruno", 7, 2, 200.0f),
		Reserva("Carlos", 15, -2, 100.0f)
	};

	float totalGeral = 0;

	for (int i = 0; i < 3; i++)
	{
		cout << "--- Reserva " << (i + 1) << " ---" << '\n';
		reservas[i].extrato();
		totalGeral += reservas[i].valorTotal();
		cout << '\n';
	}

	cout << "Valor total de todas as reservas: " << totalGeral << '\n';
	cout << '\n';

	maisLonga(reservas[0], reservas[1]);

	return 0;
}
