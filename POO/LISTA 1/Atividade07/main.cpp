#include <iostream>
#include <windows.h>
#include "Aluno.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Aluno aluno1("Joao", 1001);
	Aluno aluno2("Maria", 1002);

	aluno1.lancarNota(0, 8.0f);
	aluno1.lancarNota(1, 7.5f);
	aluno1.lancarNota(2, 6.0f);
	aluno1.lancarNota(3, 9.0f);

	aluno2.lancarNota(0, 4.0f);
	aluno2.lancarNota(1, 5.0f);
	aluno2.lancarNota(2, 5.5f);
	aluno2.lancarNota(3, 12.0f);

	aluno1.situacao();
	aluno2.situacao();

	return 0;
}
