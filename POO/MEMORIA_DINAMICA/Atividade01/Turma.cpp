#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ErroDeValidacao : public std::runtime_error 
{
public:
	explicit ErroDeValidacao(const std::string& mensagem)
		: std::runtime_error(mensagem) {}
};

class Turma
{
private:
	string m_disciplina;
	double* m_nota;
	int m_qtdAlunos;

public:
	Turma(const string& disciplina, int qtdAlunos)
		:	m_disciplina(disciplina), m_nota(nullptr), m_qtdAlunos(qtdAlunos)
	{
		if (disciplina.empty())
			throw ErroDeValidacao("Nome não pode ser vazio.");

		if (qtdAlunos < 0)
			throw ErroDeValidacao("Alunos não pode ser menor que zero.");

		m_nota = new double[m_qtdAlunos];
		for (int i = 0; i < qtdAlunos; i++)
			m_nota[i] = 0.0f;
	}

	bool lancarNota(int indice, double nota) 
	{
		if (indice < 0 || indice >= m_qtdAlunos) 
			return false;
		if (nota < 0.0 || nota > 100.0) 
			return false;
		m_nota[indice] = nota;
		return true;
	}

	double media() const 
	{
		if (m_qtdAlunos == 0)
			return 0.0;
		double soma = 0.0;
		
		for (int i = 0; i < m_qtdAlunos; i++)
			soma += m_nota[i];

		return soma / m_qtdAlunos;
	}

	void exibir() const
	{
		cout << "Disciplina: " << m_disciplina << endl;
		for (int i = 0; i < m_qtdAlunos; i++)
			cout << "Nota " << i + 1 << ": " << m_nota[i] << endl;
		cout << "Media: " << media() << endl;
	}

	~Turma()
	{
		std::cout << "Foram liberadas " << m_qtdAlunos << " notas.\n";
		delete[] m_nota;
	}
};

int main()
{
	int alunos;

	cout << "Quantos alunos tem a turma: ";
	cin >> alunos;

	try
	{
		Turma turmaMat("Matematica", alunos);

		for (int i = 0; i < alunos; i++)
		{
			double nota;
			cout << "Nota do aluno " << i + 1 << ": ";
			cin >> nota;

			if (!turmaMat.lancarNota(i, nota))
			{
				cout << "Nota invalida, tente novamente.\n";
				i--;
			}
		}

		turmaMat.exibir();
	}
	catch (const ErroDeValidacao& erro)
	{
		cout << "ERRO: " << erro.what() << endl;
	}


	return 0;
}