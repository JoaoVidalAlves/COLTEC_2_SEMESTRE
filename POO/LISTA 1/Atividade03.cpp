#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class Sensor
{
private:
	string m_nome;
	float m_temperatura;
	char m_unidade;

public:

	Sensor()
	{
		m_nome = "Sensor";
		m_temperatura = 0;
		m_unidade = 'C';
	}

	Sensor(string nome, float temperatura, char unidade)
	{
		m_nome = nome;
		setUnidade(unidade);
		setTemperatura(temperatura);
	}

	void setTemperatura(float temperatura)
	{
		if (m_unidade == 'C' || m_unidade == 'c')
		{
			if (temperatura < -273.15f)
			{
				cout << "Menor temperatura possivel = -273.15 C" << '\n';
				m_temperatura = -273.15f;
			}
			else
			{
				m_temperatura = temperatura;
			}
		}

		if (m_unidade == 'F' || m_unidade == 'f')
		{
			if (temperatura < -459.67f)
			{
				cout << "Menor temperatura possivel = -459.67 F" << '\n';
				m_temperatura = -459.67f;
			}
			else
			{
				m_temperatura = temperatura;
			}
		}
	}

	void setUnidade(char unidade)
	{
		if (unidade != 'C' && unidade != 'c' && unidade != 'F' && unidade != 'f')
		{
			cout << "Unidade invalida - Ceusius = C ou c, Fahrenheit = F ou f" << '\n';
			m_unidade = 'C';
		}
		else
			m_unidade = unidade;
	}

	void Leitura()
	{
		cout << m_nome << ": " << m_temperatura << " " << m_unidade << '\n';
	}
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Sensor sensor1;
	Sensor sensor2("Sensor 2: ", -500.00f, 'f');
	Sensor sensor3("Sensor 3: ", -500.00f, 'c');

	sensor1.Leitura();
	sensor2.Leitura();
	sensor3.Leitura();

	return 0;
}