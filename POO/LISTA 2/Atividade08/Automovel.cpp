#include "Automovel.h"
#include <iostream>

Automovel::Automovel(const std::string& placa, int anoFabricacao, const std::string& combustivel, int cilindrada, int portas)
    : Veiculo(placa, anoFabricacao, combustivel, cilindrada), portas(portas) {}

void Automovel::exibir() const 
{
    std::cout << "[Automovel]" << std::endl;
    Veiculo::exibir();
    std::cout << "Portas: " << portas << std::endl;
}

double Automovel::valorLicenciamento() const
{
    return Veiculo::valorLicenciamento() + 20.0 * portas;
}
