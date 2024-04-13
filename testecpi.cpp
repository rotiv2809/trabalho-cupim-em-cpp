#include <iostream>
#include <vector>
#include <string>

using namespace std;

class aluno{
    public:
    string codigo_aluno;
    string nome;
    string cpf;
    vector<disciplina> disciplinas_cursadas;
};


class disciplina{
    public:
    string codigo_disciplina;
    string nome_disciplina;
    string professor;
    string creditos;
};


