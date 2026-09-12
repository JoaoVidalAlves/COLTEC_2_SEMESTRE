#include "Aluno.h"
#include <iostream>

using namespace std;

Aluno::Aluno(string nome, int matricula)
{
	m_nome = nome;
	m_matricula = matricula;

	for (int i = 0; i < 4; i++)
	{
		m_notas[i] = 0;
	}
}

void Aluno::lancarNota(int indice, float valor)
{
	if (indice < 0 || indice > 3)
	{
		cout << "Indice invalido, deve estar entre 0 e 3" << '\n';
		return;
	}

	if (valor < 0 || valor > 10)
	{
		cout << "Valor invalido, deve estar entre 0 e 10" << '\n';
		return;
	}

	m_notas[indice] = valor;
}

float Aluno::mediaFinal()
{
	float soma = 0;

	for (int i = 0; i < 4; i++)
	{
		soma += m_notas[i];
	}

	return soma / 4;
}

void Aluno::situacao()
{
	cout << m_nome << " (matricula " << m_matricula << ") - media: " << mediaFinal() << " - ";

	if (mediaFinal() >= 6)
	{
		cout << "Aprovado" << '\n';
	}
	else
	{
		cout << "Reprovado" << '\n';
	}
}
