#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Aluno
{
	public:
		void Inicializar ()
		{
			nome = "Sem Nome";
			nota = 0;

			cout << nome << endl;
			cout << nota << endl;
		}

		void SetNome(string nome)
		{
			this->nome = nome;
		}

		void GetNome()
		{
			cout << nome << endl;
		}

		void SetNota(double nota)
		{
			if (nota >= 0 && nota <= 10)
				this->nota = nota;
			else
				cout << "Nota Invalida - Intervalo de 0 a 10" << endl;
		}

		void Situacao ()
		{
			if (nota >= 6)
				cout << "Aprovado" << endl;
			else
				cout << "Reprovado" << endl;
		}

		void GetNota ()
		{
			cout << nota << endl;
		}

	private:
		string nome;
		double nota;
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Aluno aluno1;

	aluno1.Inicializar();
	cout << endl;

	aluno1.SetNome("João Pedro Vidal Alves");
	aluno1.SetNota(9);

	aluno1.GetNome();
	aluno1.GetNota();
	aluno1.Situacao();
	cout << endl;

	aluno1.SetNota(5);

	aluno1.GetNome();
	aluno1.GetNota();
	aluno1.Situacao();

	return 0;
}

