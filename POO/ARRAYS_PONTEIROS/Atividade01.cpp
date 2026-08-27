#include <iostream>

using namespace std;

int main ()
{
    cout << "Digite os valores." << endl;

    int vetor[6];

    for (int i = 0; i < 6; i++)
    {
        cin >> vetor[i];
    }

    cout << "Imprimindo inverso" << endl;

    for (int i = 5; i >= 0; i--)
    {
        cout << vetor[i] << endl;
    }

    return 0;
}