#include "Veiculo.h"
#include <iostream>

Veiculo::Veiculo(const std::string& placa, int anoFabricacao, const std::string& combustivel, int cilindrada)
    : placa(placa), anoFabricacao(anoFabricacao), motor(combustivel, cilindrada) {}

void Veiculo::exibir() const 
{
    std::cout << "Placa: " << placa << ", Ano: " << anoFabricacao << std::endl;
    motor.exibir();
}

double Veiculo::valorLicenciamento() const 
{
    return 100.0;
}
