#include "Avaliacao.h"

Avaliacao::Avaliacao(string descricao, double peso)
    : m_descricao(descricao), m_peso(peso < 0 ? 0 : peso) 
{
    if(peso < 0)
        cout << "Peso não pode ser inferior a 0" << std::endl;   
}

double Avaliacao::pontos() const 
{
    return Nota() * m_peso;
}

void Avaliacao::ExibirNota() const
{
    cout << std::left << std::setw(18) << m_descricao
         << " | " << std::setw(10) <<  Avaliacao::Descricao()
         << " | nota " << std::fixed << std::setprecision(1) << Avaliacao::Nota()
         << " | peso " << m_peso
         << " | pontos " << Avaliacao::pontos() << std::endl; 
}

double Avaliacao::getPeso() const
{
    return m_peso;
}