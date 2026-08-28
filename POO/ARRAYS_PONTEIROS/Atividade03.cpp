#include <iostream>

using namespace std;

inline void dobrarArray(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i] *= 2;
    }
}

int main ()
{
    int tam = 4;
    int vetor[4] = {1, 2, 3, 4};

    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << "\t";
    }
    
    cout << endl;
    
    dobrarArray(vetor, tam);
    
    cout << endl;
    
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << "\t";
    }

    return 0;
}