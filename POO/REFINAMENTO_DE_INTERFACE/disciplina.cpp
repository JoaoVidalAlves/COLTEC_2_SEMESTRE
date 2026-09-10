#include <iostream>

using namespace std;

class Disciplina 
{
        private:
        string nomeDaDisciplina;
        string nomeDoProfessor;
        int numeroDeVagas;

        public:

        Disciplina()
        {
            nomeDaDisciplina = "A definir";
            nomeDoProfessor = "A definir";
            numeroDeVagas = 0;
        }

        Disciplina(string nomeDaDisciplina, string nomeDoProfessor)
        {
            this->nomeDaDisciplina = nomeDaDisciplina;
            this->nomeDoProfessor = nomeDoProfessor;
            numeroDeVagas = 0;
        }

    //---------------------GET's--------------------------

        string getNomeDaDisciplina() const
        {
            return nomeDaDisciplina;
        }

        string getNomeDoProfessor() const
        {
            return nomeDoProfessor;
        }

        int getNumeroDeVagas() const
        {
            return numeroDeVagas;
        }    
        
    //---------------------SET's--------------------------

        void setNomeDaDisciplina(string nomeDisciplina)
        {
            nomeDaDisciplina = nomeDisciplina;
        }

        void setNomeDoProfessor(string nomeProfessor)
        {
            nomeDoProfessor = nomeProfessor;
        }

        void setNumeroDeVagas(int vagas)
        {
            numeroDeVagas = vagas;
        }
        
    //---------------------IMPRIMIR--------------------------
        
    void Imprimir()
    {
        cout << nomeDaDisciplina << endl;
        cout << nomeDoProfessor << endl;
        cout << numeroDeVagas << endl;
    }

};

int main ()
{
    Disciplina disp1;

    disp1.Imprimir();

    disp1.setNomeDaDisciplina("Matematica");
    disp1.setNomeDoProfessor("Rafael");
    disp1.setNumeroDeVagas(30);

    cout << disp1.getNomeDaDisciplina() << endl;
    cout << disp1.getNomeDoProfessor() << endl;
    cout << disp1.getNumeroDeVagas() << endl;

    return 0;
}