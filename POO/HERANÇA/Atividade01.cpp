#include <iostream>
#include <string>

using namespace std;

class Veiculo
{
    private:
    string m_nome;
    int m_ano;

    public:
    void setDados(string nome, int ano)
    {
        m_nome = nome;
        m_ano = ano;
    }

    void exibir() const 
    {
        cout << "Nome: " << m_nome << " | Ano: " << m_ano << " | ";
    }
};

class Carro : public Veiculo
{
    private: 
    int m_portas;

    public:
    void setDados(string nome, int ano, int portas)
    {
        Veiculo::setDados(nome, ano);

        m_portas = portas;
    }

    void exibir() const 
    {
        Veiculo::exibir();
        cout << "Portas: " << m_portas << "\n";
    }
};

class Moto : public Veiculo
{
    private: 
    int m_cilindradas;

    public:
    void setDados(string nome, int ano, int cilindradas)
    {
        Veiculo::setDados(nome, ano);

        m_cilindradas = cilindradas;
    }

    void exibir() const 
    {
        Veiculo::exibir();
        cout << "Cilindradas: " << m_cilindradas << "\n";
    }
};

int main ()
{
    Carro carro;
    Moto moto;

    carro.setDados("HB20S", 2018, 4);
    moto.setDados("FAN160", 2020, 200);

    carro.exibir();
    moto.exibir();

    return 0;
}