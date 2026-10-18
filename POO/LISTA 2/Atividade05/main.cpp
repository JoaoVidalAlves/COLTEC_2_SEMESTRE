#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Eletrodomestico
{
protected:
    string m_nome;
    double m_potencia;

public:
    Eletrodomestico(string nome, double potencia)
        : m_nome(nome), m_potencia(potencia < 0 ? 0 : potencia)
    {
        if (m_potencia <= 0)
        {
            cout << "A potencia deve ser positiva." << endl;
        }

        cout << "Eletrodomestico cadastrado: " << m_nome << endl;
    }

    virtual ~Eletrodomestico()
    {
        cout << "Eletrodomestico removido: " << m_nome << endl;
    }

    virtual double consumoDiario() const
    {
        return m_potencia * 24 / 1000;
    }

    virtual void exibir() const
    {
        cout << fixed << setprecision(2);
        cout << "Nome: " << m_nome << endl;
        cout << "Potencia: " << m_potencia << " W" << endl;
        cout << "Consumo diario: " << consumoDiario()
            << " kWh" << endl;
    }
};

class Geladeira : public Eletrodomestico
{
private:
    double m_fatorUso;

public:
    Geladeira(string nome, double potencia, double fatorUso)
        : Eletrodomestico(nome, potencia), m_fatorUso(fatorUso < 0 ? 0 : fatorUso > 1 ? 1 : fatorUso)
    {
        if (fatorUso < 0 || fatorUso > 1)
            cout << "O fator de uso deve estar entre 0 e 1." << endl;
        
        cout << "Geladeira cadastrada: " << nome << endl;
    }

    ~Geladeira() override
    {
        cout << "Geladeira removida: " << m_nome << endl;
    }

    double consumoDiario() const override
    {
        return m_potencia * 24 * m_fatorUso / 1000;
    }

    void exibir() const override
    {
        Eletrodomestico::exibir();
        cout << "Fator de uso: " << m_fatorUso << endl;
    }
};

class Lampada : public Eletrodomestico
{
private:
    double m_horasAcesa;

public:
    Lampada(string nome, double potencia, double horasAcesa)
        : Eletrodomestico(nome, potencia), m_horasAcesa(horasAcesa < 0 ? 0 : horasAcesa > 24 ? 24 : horasAcesa)
    {
        if (horasAcesa < 0 || horasAcesa > 24)
            cout << "As horas acesa devem estar entre 0 e 24." << endl;

        cout << "Lampada cadastrada: " << nome << endl;
    }

    ~Lampada() override
    {
        cout << "Lampada removida: " << m_nome << endl;
    }

    double consumoDiario() const override
    {
        return m_potencia * m_horasAcesa / 1000;
    }

    void exibir() const override
    {
        Eletrodomestico::exibir();
        cout << "Horas acesa: " << m_horasAcesa << endl;
    }
};

int main()
{
    try
    {
        Geladeira geladeira("Geladeira", 200, 0.40);
        cout << endl;

        Lampada lampada("Lampada", 12, 6);
        cout << endl;

        cout << "=== GELADEIRA ===" << endl;
        geladeira.exibir();

        cout << endl;

        cout << "=== LAMPADA ===" << endl;
        lampada.exibir();
    }
    catch (const invalid_argument& erro)
    {
        cerr << "Erro: " << erro.what() << endl;
        return 1;
    }

    /*
    Os construtores são executados primeiro na classe base e depois
    na derivada. Ao sair do escopo, os destrutores são executados
    na ordem inversa: primeiro a lâmpada e depois a geladeira,
    sempre destruindo a classe derivada antes da classe base.
    */

    return 0;
}
