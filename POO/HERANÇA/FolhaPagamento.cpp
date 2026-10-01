#include <string>
#include <iostream>


class Funcionario 
{
    
protected:
    std::string m_nome;
    int m_matricula;
    float m_salarioBase;

public:
    Funcionario(std::string nome, int matricula, float salariobase) 
        : m_nome(nome), m_matricula(matricula), m_salarioBase(salariobase)
    {
        std::cout << "Funcionario " << m_nome << " cadastrado com sucesso!" << "\n";
    }

    ~Funcionario()
    {
        std::cout << "Funcionario " << m_nome << " removido com sucesso!" << "\n";
    }    

    float CalcularSalario()
    {
        return m_salarioBase;
    }

    void Exibir() const
    {
        std::cout << "Nome: " << m_nome << "\n";
        std::cout << "Matricula: " << m_matricula << "\n";
        std::cout << "Salario Base: " << m_salarioBase << "\n";
    }    
};

class Vendedor : public Funcionario
{
private:
    int m_totalVendas;
    float m_comissao;

public:
    Vendedor(std::string nome, int matricula, float salariobase, int totalvendas, float comissao) 
        : Funcionario(nome, matricula, salariobase), m_totalVendas(totalvendas), m_comissao(comissao)
    {
        std::cout << "Vendedor " << m_nome << " cadastrado com sucesso!" << "\n";
    }

    float CalcularSalario() const
    {
        return m_salarioBase + m_totalVendas*m_comissao/100;
    }

    void Exibir() const
    {
        std::cout << "Vendedor: " << m_nome << "\n";
        std::cout << "Total vendas: R$ " << m_totalVendas << "\n";
        std::cout << "Comissão: " << m_comissao << "%" << "\n";
        std::cout << "Total salario: R$ " << CalcularSalario() << "\n";
    }
};

class Gerente : public Funcionario
{
private:
    float m_bonus;
    std::string m_setor;

public:
    Gerente(std::string nome, int matricula, float salriobase, float bonus, std::string setor) 
        : Funcionario(nome, matricula, salriobase), m_bonus(bonus), m_setor(setor)
    {
        std::cout << "Gerente " << m_nome << " cadastrado com sucesso!" << "\n";
    }

    float CalcularSalario() const
    {
        return m_salarioBase + m_bonus;
    }

    void Exibir() const
    {
        Funcionario::Exibir();
        std::cout << "Bonus: R$ " << m_bonus << "\n";
        std::cout << "Setor: " << m_setor << "\n";
        std::cout << "Total salario: R$ " << CalcularSalario() << "\n";
        
    }
};

int main()
{
    Vendedor v1("Joao", 1234, 1621, 1000, 5);
    std::cout << "\n";
    
    Gerente g1("Pedro", 4321, 5000, 10, "Comercial");
    std::cout << "\n";

    v1.Exibir();
    std::cout << "\n";

    g1.Exibir();
    std::cout << "\n";

    return 0;
}