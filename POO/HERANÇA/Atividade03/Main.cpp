#include "ContaPoupanca.h"

int main()
{
    ContaPoupanca conta1("Joao Vidal", 233, 0, 10);
    
    conta1.Depositar(100);
    conta1.Sacar(50);
    conta1.RenderJuros();
    conta1.Exibir();
    return 0;

    //g++ -c main.cpp Conta.cpp ContaPoupanca.cpp
    //g++ main.o Conta.o ContaPoupanca.o -o Atividade03.exe
    //./Atividade03.exe
}