#include <iostream>
#include <string>
using namespace std;

// Definição da Classe
class Disciplina {
public:

    void inicializar(string nome, int totalVagas, int totalHoras) {
        nomeDisciplina = nome;
        setCargaHoraria(totalHoras);
        if (totalVagas > 0) {
            vagas = totalVagas;
        } else {
            vagas = 0;
        }
        matriculados = 0;
    }

    string getNomeDisciplina(){
        return nomeDisciplina;
    } 

    void setNomeDisciplina(string nome){
        nomeDisciplina = nome;
    } 

    void setCargaHoraria(int horas) {
        if (horas > 0) {
            cargaHoraria = horas;
        } else {
            cout << "Carga horaria invalida, valor ignorado." << endl;
        }
    }

    int getCargaHoraria() {
        return cargaHoraria;
    }

    void matricular() {
        if (matriculados < vagas) {
            matriculados++;
        } else {
            cout << "Turma lotada." << endl;
        }
    }

    void cancelarMatricula() {
        if (matriculados > 0) {
            matriculados--;
        }
    }

    int getMatriculados() {
        return matriculados;
    }

    void mensagem(){
        cout << "Bem vindos à disciplina de " << getNomeDisciplina() << "!" << endl;
    }

private:
    string nomeDisciplina;
    int vagas;
    int matriculados;
    int cargaHoraria;
}; // Fim da Classe

int main() {
    Disciplina poo;
    poo.inicializar("POO", 3, 40);

    poo.matricular();
    poo.matricular();
    poo.matricular();
    poo.matricular();   // turma lotada, recusado

    cout << "Matriculados: " << poo.getMatriculados() << endl;

    cout << "Carga: " << poo.getCargaHoraria() << endl;
    poo.setCargaHoraria(-10);   
    poo.setCargaHoraria(80);    
    cout << "Carga: " << poo.getCargaHoraria() << endl;

    return 0;
}