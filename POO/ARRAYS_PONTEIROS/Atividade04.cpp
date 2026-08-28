#include <iostream>

using namespace std;

int* encontrarMaior(int v[], int tam)
{
    int *maior = &v[0];

    for (int i = 0; i < tam; i++)
    {
        if (v[i] > *maior)
        {
            *maior = v[i];
        }
    }
    return maior;
}

int main ()
{
    int tam = 7;
    int vetor[] = {1, 2, 3, 4, 5, 8, 2};
    
    cout << *encontrarMaior(vetor, tam) << endl;


    return 0;
}