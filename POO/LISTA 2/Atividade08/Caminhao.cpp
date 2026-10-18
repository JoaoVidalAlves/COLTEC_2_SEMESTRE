#include "Caminhao.h"
#include <iostream>

Caminhao::Caminhao(const std::string& placa, int anoFabricacao, const std::string& combustivel, int cilindrada, double capacidadeCarga)
    : Veiculo(placa, anoFabricacao, combustivel, cilindrada), capacidadeCarga(capacidadeCarga) {}

void Caminhao::exibir() const 
{
    std::cout << "[Caminhao]" << std::endl;
    Veiculo::exibir();
    std::cout << "Capacidade de carga: " << capacidadeCarga << " t" << std::endl;
}

double Caminhao::valorLicenciamento() const 
{
    return Veiculo::valorLicenciamento() + 50.0 * capacidadeCarga;
}
