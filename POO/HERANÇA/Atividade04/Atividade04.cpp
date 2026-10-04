#include <string>
#include <iostream>

class Pessoa
{
protected:
    std::string m_nome;
    int m_idade;

public:
    Pessoa(std::string nome, int idade)
        : m_nome(nome), m_idade(idade < 0 ? 0 : idade)
    {
        if (idade < 0)
        {
            std::cout << "Idade impossivel!" << "\n";
        }
    }

    void Exibir() const
    {
        std::cout << "Nome: " << m_nome << "\n";
        std::cout << "Idade: " << m_idade << "\n";
    }

};

class Funcionario : public Pessoa
{
private:
    int m_matricula;
    float m_salarioBase;

public:
    Funcionario(std::string nome, int idade, int matricula, float salariobase)
        : Pessoa(nome, idade), m_matricula(matricula), m_salarioBase(salariobase)
    {
        std::cout << "Funcionario " << m_nome << " cadastrado com sucesso!" << "\n";
    }

    ~Funcionario()
    {
        std::cout << "Funcionario " << m_nome << " removido com sucesso!" << "\n";
    }

    void Exibir() const
    {
        Pessoa::Exibir();
        std::cout << "Matricula: " << m_matricula << "\n";
        std::cout << "Salario Base: " << m_salarioBase << "\n";
    }
};

class Professor : public Funcionario
{
private:
    std::string m_disciplina;
    float m_cargahoraria;

public:
    Professor(std::string nome, int idade, int matricula, float salariobase, std::string disciplina, float cargahoraria)
        : Funcionario(nome, idade, matricula, salariobase), m_disciplina(disciplina), m_cargahoraria(cargahoraria)
    {
        std::cout << "Professor " << m_nome << " cadastrado com sucesso!" << "\n";
    }
    
    ~Professor()
    {
        std::cout << "Professor " << m_nome << " removido com sucesso!" << "\n";
    }

    void Exibir() const
    {
        Funcionario::Exibir();
        std::cout << "Disciplina: " << m_disciplina << "\n";
        std::cout << "Carga Horaria: " << m_cargahoraria << "\n";
    }
};

int main()
{
    Professor prof1("Joao", 30, 313214, 4500, "Fisica", 44);

    return 0;
}