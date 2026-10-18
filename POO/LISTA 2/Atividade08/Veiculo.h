#ifndef VEICULO_H
#define VEICULO_H

#include <string>
#include "Motor.h"

class Veiculo 
{
protected:
    std::string placa;
    int anoFabricacao;

private:
    Motor motor;  // composição: o veículo "tem um" motor

public:
    Veiculo(const std::string& placa, int anoFabricacao,
            const std::string& combustivel, int cilindrada);

    void exibir() const;
    double valorLicenciamento() const;
};

#endif
