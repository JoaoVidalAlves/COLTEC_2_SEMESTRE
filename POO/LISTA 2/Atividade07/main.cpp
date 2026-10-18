#include <iostream>
#include <string>

#include "Motor.h"

int main()
{
	Motor motor1(1421, "Motor de teste", 1, 100, 50);

	motor1.Exibir();

	return 0;
}

//g++ Equipamento.cpp EquipamentoEletrico.cpp Motor.cpp main.cpp - o a.exe