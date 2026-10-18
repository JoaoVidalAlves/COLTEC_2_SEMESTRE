#include <iostream>
#include "Automovel.h"
#include "Caminhao.h"

int main() {
    const int QTD_AUTOMOVEIS = 2;
    const int QTD_CAMINHOES = 2;

    Automovel automoveis[QTD_AUTOMOVEIS] = 
    {
        Automovel("ABC-1234", 2020, "Flex", 1000, 4),
        Automovel("DEF-5678", 2018, "Gasolina", 1600, 2)
    };

    Caminhao caminhoes[QTD_CAMINHOES] = 
    {
        Caminhao("GHI-9012", 2015, "Diesel", 8000, 12.5),
        Caminhao("JKL-3456", 2022, "Diesel", 11000, 20.0)
    };

    double totalLicenciamento = 0.0;

    for (int i = 0; i < QTD_AUTOMOVEIS; i++) 
    {
        automoveis[i].exibir();
        double valor = automoveis[i].valorLicenciamento();
        std::cout << "Licenciamento: R$ " << valor << "\n" << std::endl;
        totalLicenciamento += valor;
    }

    for (int i = 0; i < QTD_CAMINHOES; i++) 
    {
        caminhoes[i].exibir();
        double valor = caminhoes[i].valorLicenciamento();
        std::cout << "Licenciamento: R$ " << valor << "\n" << std::endl;
        totalLicenciamento += valor;
    }

    std::cout << "Total de licenciamento da frota: R$ " << totalLicenciamento << std::endl;
    return 0;
}
