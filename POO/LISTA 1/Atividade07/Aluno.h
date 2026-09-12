#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno
{
private:
	std::string m_nome;
	int m_matricula;
	float m_notas[4];

public:
	Aluno(std::string nome, int matricula);

	void lancarNota(int indice, float valor);
	float mediaFinal();
	void situacao();
};

#endif
