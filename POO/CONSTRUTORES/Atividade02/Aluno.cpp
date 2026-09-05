#include <iostream>
#include "Aluno.h"

using namespace std;

void Aluno::Inicializar()
{
	nome = "Sem Nome";
	nota = 0;

	cout << nome << endl;
	cout << nota << endl;
}

void Aluno::SetNome(string nome)
{
	this->nome = nome;
}

string Aluno::GetNome()
{
	return nome;
}

void Aluno::SetNota(double nota)
{
	if (nota >= 0 && nota <= 10)
		this->nota = nota;
	else
		cout << "Nota Invalida - Intervalo de 0 a 10" << endl;
}

double Aluno::GetNota()
{
	return nota;
}

void Aluno::Situacao()
{
	if (nota >= 6)
		cout << "Aprovado" << endl;
	else
		cout << "Reprovado" << endl;
}