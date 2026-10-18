#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo 
{
private:
    double capacidadeCarga;

public:
    Caminhao(const std::string& placa, int anoFabricacao, const std::string& combustivel, int cilindrada, double capacidadeCarga);

    void exibir() const;
    double valorLicenciamento() const;
};

#endif
