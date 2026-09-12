#include <iostream>
#include <string>
#include <Windows.h>

class Retangulo
{
private:
	float m_largura, m_altura;

public:
	Retangulo()
	{
		m_largura = 1;
		m_altura = 2;
	}

	Retangulo(float largura, float altura)
		: m_largura(0), m_altura(0)
	{
		setLargura(largura);
		setAltura(altura);
	}

	void setLargura(float largura)
	{
		if (largura <= 0)
		{
			std::cout << "Largura invalida" << '\n';
			m_largura = (m_altura * 1.5);
		}
		else if (largura == m_altura)
		{
			std::cout << "Largura não pode ser igual à altura" << '\n';
			m_largura = (m_altura * 1.5);
		}
		else
		{ 
			m_largura = largura;
		}
	}

	void setAltura(float altura)
	{
		if (altura <= 0)
		{
			std::cout << "Altura invalida" << '\n';
			m_altura = (m_largura * 1.5);
		}
		else if (altura == m_largura)
		{
			std::cout << "Altura não pode ser igual à largura" << '\n';
			m_altura = (m_largura * 1.5);
		}
		else
		{ 
			m_altura = altura;
		}
	}

	void exibir()
	{
		std::cout << "Altura = " << m_altura << '\n';
		std::cout << "Largura = " << m_largura << '\n';
	}

	float area()
	{
		return (m_largura * m_altura);
	}

	float perimetro()
	{
		return ((m_largura * 2) + (m_altura * 2));
	}
};



int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Retangulo retangulos[3] =
	{
		Retangulo(),
		Retangulo(2.2f, 2.2f),
		Retangulo(1, 2.2f)
	};

	float maiorArea = 0;
	int indiceMaiorArea = 0;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Retangulo " << (i + 1) << '\n';
		retangulos[i].exibir();
		std::cout << '\n';

		if (retangulos[i].area() > maiorArea)
		{
			maiorArea = retangulos[i].area();
			indiceMaiorArea = i;
		}
	}

	std::cout << "Retangulo com a maior area: "<< indiceMaiorArea + 1 << '\n' << "Area total: " << maiorArea << '\n';

	return 0;
}