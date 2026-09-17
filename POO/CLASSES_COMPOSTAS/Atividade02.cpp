#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Ponto
{
    private:

    float m_x;
    float m_y;

    public:

    Ponto(float x, float y)
        : m_x(x), m_y(y)
    {}

    void Exibir() const
    {
        cout << "(" << m_x << ", " << m_y << ")"<< endl;
    }

    double getX() const {
        return m_x;
    }

    double getY() const {
        return m_y;
    }
};

class Retangulo
{
    private:
    
    Ponto p1, p2;

    public:

    Retangulo(Ponto infEsq, Ponto SupDir)
        : p1(infEsq), p2(SupDir)
    {}

    float Area() const
    {
        float largura = p1.getX() - p2.getX();
        float altura = p1.getY() - p2.getY();

        return largura * altura;
    }

    void Exibir() const
    {
        cout << "Canto inferior esquerdo: ";
        p1.Exibir();

        cout << endl;

        cout << "Canto superior direito: ";
        p2.Exibir();

        cout << endl;
    }
};

int main() {
    Ponto inferiorEsquerdo(2, 3);
    Ponto superiorDireito(8, 7);

    Retangulo retangulo(inferiorEsquerdo, superiorDireito);

    retangulo.Exibir();

    cout << "Area: " << retangulo.Area() << endl;

    return 0;
}