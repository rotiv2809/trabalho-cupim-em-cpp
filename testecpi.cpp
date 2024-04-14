#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class aluno{
    public:
    string codigo_aluno;
    string nome_aluno;
    string cpf;
    vector<class disciplina> disciplinas_cursadas;
};


class disciplina{
    public:
    string codigo_disciplina;
    string nome_disciplina;
    string professor;
    string creditos;
};

int main(){
    cout << "cum";
}


