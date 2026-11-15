#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int linhas, colunas;

	cout << "Numero de linhas: ";
	cin >> linhas;
	cout << "Numero de colunas: ";
	cin >> colunas;

	if (cin.fail() || linhas <= 0 || colunas <= 0)
	{
		cout << "ERRO: digite valores inteiros maiores que zero.\n";
		return 1;
	}

	int chamadasNew = 0;

	int** m = new int* [linhas];   // vetor de ponteiros (as "linhas")
	chamadasNew++;

	for (int i = 0; i < linhas; i++)
	{
		m[i] = new int[colunas];  // cada linha tem seu vetor de inteiros
		chamadasNew++;
	}

	// Preenche com a tabuada: (i + 1) * (j + 1)
	for (int i = 0; i < linhas; i++)
		for (int j = 0; j < colunas; j++)
			m[i][j] = (i + 1) * (j + 1);

	// Imprime em grade e mostra a soma de cada linha
	cout << "\nMatriz:\n";
	for (int i = 0; i < linhas; i++)
	{
		int soma = 0;
		for (int j = 0; j < colunas; j++)
		{
			cout << setw(5) << m[i][j];
			soma += m[i][j];
		}
		cout << "  | soma = " << soma << endl;
	}

	for (int i = 0; i < linhas; i++)
		delete[] m[i];

	delete[] m;

	cout << "\nChamadas de new: " << chamadasNew << endl;

	return 0;
}