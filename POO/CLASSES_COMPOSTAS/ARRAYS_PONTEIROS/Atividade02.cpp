#include <iostream>

using namespace std;

int main ()
{

    float vetor[3][2];

    for (int i = 0; i < 3; i++)
    {
        cout << "Aluno:" << i + 1 << endl; 

        for (int j = 0; j < 2; j++)
        {
            cout << "Informe a nota" << j + 1 << ":";
            cin >> vetor[i][j];
        }

        cout << endl;
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << "Aluno " << i + 1 << endl;

    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << "Nota: " << vetor[i][j] << endl;
    //     }

    //     cout << endl;
    // }

    float soma[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            soma[i] += vetor[i][j];
        }

        soma[i] /= 2;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Aluno " << i + 1 << endl;
        cout << "Notas: " << soma[i] << endl;
        cout << endl;
    }

    return 0;
}