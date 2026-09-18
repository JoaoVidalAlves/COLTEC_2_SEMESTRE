#include <iostream>
#include <string>

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
    
    Ponto inferiorEsq, superiorDir;

    public:

    Retangulo(Ponto infEsq, Ponto SupDir)
        : inferiorEsq(infEsq), superiorDir(SupDir)
    {}

    float Area() const
    {
        float largura = inferiorEsq.getX() - superiorDir.getX();
        float altura = inferiorEsq.getY() - superiorDir.getY();

        return largura * altura;
    }

    void Exibir() const
    {
        cout << "Canto inferior esquerdo: ";
        inferiorEsq.Exibir();

        cout << endl;

        cout << "Canto superior direito: ";
        superiorDir.Exibir();

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