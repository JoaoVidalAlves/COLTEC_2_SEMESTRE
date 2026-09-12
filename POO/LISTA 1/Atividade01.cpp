#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Disciplina
{
	private:
		string m_nomeDoProfessor;
		string m_nomeDaDisciplina;
		int m_quantidadeDeVagas;

	public:
		Disciplina()
		{
			m_nomeDoProfessor = "Vazio";
			m_nomeDaDisciplina = "Vazio";
			m_quantidadeDeVagas = 0;
		}

		Disciplina(string nomeDisci, string nomeProf, int vagas)
		{
			m_nomeDoProfessor = nomeProf;
			m_nomeDaDisciplina = nomeDisci;
			m_quantidadeDeVagas = vagas;
		}

	//----------------------------SET's--------------------------------

		void setNomeDoProfessor(const string& nome)
		{
			m_nomeDoProfessor = nome;
		}

		void setNomeDaDisciplina(const string& nome)
		{
			m_nomeDaDisciplina = nome;
		}

		void setQuantidadeDeVagas(int quantidade)
		{
			m_quantidadeDeVagas = quantidade;
		}

	//----------------------------GET's--------------------------------

		string getNomeDoProfessor() const
		{
			return m_nomeDoProfessor;
		}

		string getNomeDaDisciplina() const
		{
			return m_nomeDaDisciplina;
		}

		int getQuantidadeDeVagas() const
		{
			return m_quantidadeDeVagas;
		}

	//----------------------------IMPRIMIRj--------------------------------

		void mensagem()
		{
			cout << "Bem vindo a disciplina de: " << m_nomeDaDisciplina << '\n';
			cout << "Esta disciplina é ministrada pelo(a) professor(a): " << m_nomeDoProfessor << '\n';
			cout << "Quantidade de vagas: " << m_quantidadeDeVagas << '\n';
		}
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Disciplina disp1, disp2;

	disp1.mensagem();
	cout << '\n';
	disp2.mensagem();

	disp1.setNomeDaDisciplina("Matemática");
	disp1.setNomeDoProfessor("Rafael");
	disp1.setQuantidadeDeVagas(30);

	disp2.setNomeDaDisciplina("Português");
	disp2.setNomeDoProfessor("Fernanda");
	disp2.setQuantidadeDeVagas(30);

	cout << '\n';
	disp1.mensagem();
	cout << '\n';
	disp2.mensagem();

	return 0;
}