#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#include "Veiculo.h"

class Automovel : public Veiculo 
{
private:
    int portas;

public:
    Automovel(const std::string& placa, int anoFabricacao, const std::string& combustivel, int cilindrada, int portas);

    void exibir() const;
    double valorLicenciamento() const;
};

#endif
