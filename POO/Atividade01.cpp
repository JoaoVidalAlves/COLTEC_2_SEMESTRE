#include <iostream>

using namespace std;

int main()
{
int x = 0;

    do
    {
        cout << "Digite uma nota (menor que 0 encerra) encerra: ";
        cin >> x;

        if (x < 0)
        {
            cout << "Encerrando..." << endl;
        }
        else
        {
    
            cout << "Nota valida!" << endl;
        
        }

    } while (x >= 0);

    return 0;
}