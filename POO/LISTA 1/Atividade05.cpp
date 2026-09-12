#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Placar
{
private:
	string m_nomeTime1, m_nomeTime2;
	int m_golsTime1, m_golsTime2;

public:
	Placar(string nomeTime1, string nomeTime2)
	{
		m_nomeTime1 = nomeTime1;
		m_nomeTime2 = nomeTime2;
		m_golsTime1 = 0;
		m_golsTime2 = 0;
	}

	Placar()
	{
		cout << "Partida encerrada: ";
		resultado();
	}

	void marcarTime1()
	{
		m_golsTime1++;
	}

	void marcarTime2()
	{
		m_golsTime2++;
	}

	void resultado()
	{
		cout << m_nomeTime1 << " " << m_golsTime1 << " x " << m_golsTime2 << " " << m_nomeTime2 << '\n';

		if (m_golsTime1 > m_golsTime2)
		{
			cout << m_nomeTime1 << " esta vencendo" << '\n';
		}
		else if (m_golsTime2 > m_golsTime1)
		{
			cout << m_nomeTime2 << " esta vencendo" << '\n';
		}
		else
		{
			cout << "Empate" << '\n';
		}
	}

	void reiniciar()
	{
		m_golsTime1 = 0;
		m_golsTime2 = 0;
	}
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Placar placar("Atletico", "Cruzeiro");

	cout << "--- Primeira partida ---" << '\n';

	placar.marcarTime1();
	placar.resultado();
	cout << '\n';

	placar.marcarTime1();
	placar.resultado();
	cout << '\n';

	placar.marcarTime2();
	placar.resultado();
	cout << '\n';

	placar.marcarTime1();
	placar.resultado();
	cout << '\n';

	placar.marcarTime2();
	placar.resultado();
	cout << '\n';

	cout << "--- Reiniciando para a segunda partida ---" << '\n';
	placar.reiniciar();
	placar.resultado();
	cout << '\n';

	placar.marcarTime2();
	placar.resultado();

	return 0;
}
