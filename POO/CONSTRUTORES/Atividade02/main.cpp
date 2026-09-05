#include <iostream>
#include <windows.h>
#include "Aluno.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Aluno aluno1;

	aluno1.Inicializar();

	aluno1.SetNome("João Pedro Vidal Alves");
	aluno1.SetNota(9);

	cout << "Nome: " << aluno1.GetNome() << endl;
	cout << "Nota: " << aluno1.GetNota() << endl;
	aluno1.Situacao();

	cout << endl;
	aluno1.SetNota(5);

	cout << "Nome: " << aluno1.GetNome() << endl;
	cout << "Nota: " << aluno1.GetNota() << endl;
	aluno1.Situacao();

	return 0;
}

