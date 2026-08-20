#include <iostream>

using namespace std;

class Robo 
{
    public:

    void Andar ()
    {
        cout << "O Robô andou!" << endl;
    }

    void Falar (string texto)
    {
        cout << "O robô diz: " << texto << endl;
    }
};

int main ()
{
    string robo1Diz;
    string robo2Diz;

    Robo robo1, robo2;

    robo1.Andar();
    
    cout << "O robo 1 diz: " << endl;
    cin >> robo1Diz;

    robo1.Falar(robo1Diz);

    robo2.Andar();
    
    cout << "O robo 2 diz: " << endl;
    cin >> robo2Diz;

    robo1.Falar(robo2Diz);

    return 0;
}