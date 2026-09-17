#include <iostream>
#include <string>

using namespace std;

class Endereco
{
private:
    
    string m_rua;
    int m_numero;
    string m_cidade;

public:

    Endereco(string rua, int numero, string cidade)
        : m_rua(rua), m_numero(numero), m_cidade(cidade)
    {}

    void Exibir() const
    {
        cout << "Rua: " << m_rua << " nº " << m_numero << ", " << m_cidade << endl; 
    }
};

class Cliente
{
    private:
    
    string m_nomeCliente;

    public:

    Endereco ende1;

    Cliente (string nome, string rua, int numero, string cidade)
        : m_nomeCliente(nome), ende1(rua, numero, cidade)
    {}

    void Exibir() const
    {
        cout << m_nomeCliente << " - ";
        ende1.Exibir();
    }
};

int main()
{
    Cliente c1("Joao","Maraca",933,"Belo Horizonte");

    c1.Exibir();

    Cliente c2("Pedro","Patu",102,"Contagem");

    c2.Exibir();
    
    return 0;
}