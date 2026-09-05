#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>

using namespace std;

class Aluno
{
public:
	void Inicializar();
	
	void SetNome(string nome);

	string GetNome();
	
	void SetNota(double nota);

	void Situacao();

	double GetNota();

private:
	string nome;
	double nota;
};

#endif