#include "Prova.h"

Prova::Prova(string descricao, double peso, double pontuacao)
    : Avaliacao::Avaliacao(descricao, peso), m_pontuacao(pontuacao < 0 ? 0 : pontuacao) 
{
    if(pontuacao < 0)
        cout << "Pontuaçao não pode ser inferior a 0" << std::endl;
}

double Prova::Nota() const
{
    return m_pontuacao;
}

string Prova::Descricao() const
{
    return m_descricao;
}