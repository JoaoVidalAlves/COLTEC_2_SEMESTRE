#include <iostream>

using namespace std;

class Livro
{
    private:
    string titulo;
    string autor;
    int ano;

    public:

    Livro()
    {
        titulo = "A definir";
        autor = "A definir";
        ano = 0;
    }

    Livro(string titulo, string autor, int ano)
    {
        this->titulo = titulo;
        this->autor = autor;
        this->ano = ano;
    }

    //---------------------GET's--------------------------

    string getNomeAutor () const
    {
        return autor;
    }

    string getNomeTitulo () const
    {
        return titulo;
    }

    int getAno () const
    {
        return ano;
    }

    //------------------------SET's------------------------
    void setNomeAutor (string nomeAutor)
    {
        autor = nomeAutor;
    }

    void setNomeTitulo (string nomeTitulo)
    {
        titulo = nomeTitulo;
    }

    void setAno (int anoLivro)
    {
        ano = anoLivro;
    }

    //------------------------IMPRIMIR------------------------

    void Descricao()
    {
        cout << titulo << endl;
        cout << autor << endl;
    }

    void Descricao(bool a)
    {
        if (a)
        {
            cout << titulo << endl;
            cout << autor << endl;
            cout << ano << endl;
        }
        else
        {
            cout << titulo << endl;
            cout << autor << endl;
        }
    }
};

void Catalogar(const Livro& livro)
{
    cout << livro.getNomeTitulo() << endl;
    cout << livro.getNomeAutor() << endl;
    cout << livro.getAno() << endl;
}

int main ()
{
    Livro livro1, livro2;

    livro1.setNomeAutor("Homero");
    livro1.setNomeTitulo("Iliada");
    livro1.setAno(2026);

    livro2.setNomeAutor("Homero");
    livro2.setNomeTitulo("Odisseia");
    livro2.setAno(2026);

    livro1.Descricao();
    livro1.Descricao(false);

    // Catalogar(livro1);

    // Catalogar(livro2);

    return 0;
}