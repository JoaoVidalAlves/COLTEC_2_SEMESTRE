#include <iostream>
#include <string>

class Midia {
protected:
    std::string m_titulo;
    int m_ano;

public:
    Midia(const std::string& titulo, int ano) : m_titulo(titulo), m_ano(ano) {}
    
    void exibirCabecalho() const 
    {
        std::cout << m_titulo << " (" << m_ano << ")";
    }
};

class Livro : public Midia 
{
private:
    int m_paginas;

public:
    Livro(const std::string& titulo, int ano, int paginas)
        : Midia(titulo, ano), m_paginas(paginas) {}

    void exibirPaginas() const 
    {
        exibirCabecalho();
        std::cout << " - " << m_paginas << " páginas\n";
        //std::cout << m_titulo << "TESTE";
    }
};

class Filme : public Midia 
{
private:
    int m_duracao; // em minutos

public:
    Filme(const std::string& titulo, int ano, int duracao)
        : Midia(titulo, ano), m_duracao(duracao) {}

    void exibirDuracao() const 
    {
        exibirCabecalho();
        std::cout << " - " << m_duracao << " minutos\n";
    }
};

int main() {
    Livro l("1984", 1949, 328);
    Filme f("Matrix", 1999, 136);

    l.exibirPaginas();
    f.exibirDuracao();

    return 0;
}

/*
main2.cpp:31:22: error: 'std::string Midia::m_titulo' is private within this context
   31 |         std::cout << m_titulo << "TESTE";
      |

EXPLICAÇÃO

O atributo privado m_titulo so pode ser acessado por métodos da própria classe.
*/