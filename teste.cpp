#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct DisciplinaAluno {
    string nome;
    int codigo;
    string professor;
    int creditos;
};

struct FichaAluno {
    string codigo;
    string nome;
    string cpf;
    DisciplinaAluno* disciplina;
};

int main() {
    char continuar = 'y';
    while (continuar == 'y' || continuar == 'Y') {
        FichaAluno* aluno;
        int ano, periodo, numero_de_alunos, numero_de_disciplinas;

        string sano, speriodo, titulo_txt;

        cout << "\n---------- Cadastro de aluno -----------\n\n\n";

        cout << "Digite o ano em que se encontra para cadastrar o aluno: ";
        cin >> ano;
        cout << "Digite o periodo em que voce se encontra atualmente: ";
        cin >> periodo;
        cout << "Digite quantos alunos voce deseja cadastrar: ";
        cin >> numero_de_alunos;
        aluno = new FichaAluno[numero_de_alunos];

        sano = to_string(ano);
        speriodo = to_string(periodo);
        titulo_txt = sano + "_" + speriodo + ".txt";

        ofstream teste(titulo_txt);

        for (int i = 0; i < numero_de_alunos; i++) {
            cout << "Cadastro do aluno " << i + 1 << ":\nQuantas disciplinas deseja cadastrar? ";
            cin >> numero_de_disciplinas;
            aluno[i].disciplina = new DisciplinaAluno[numero_de_disciplinas];

            cout << "Digite o nome do aluno: ";
            cin >> aluno[i].nome;
            cout << "Digite o codigo do aluno: ";
            cin >> aluno[i].codigo;
            cout << "Digite o cpf do aluno (apenas numeros): ";
            cin >> aluno[i].cpf;
            cout << "Cadastro de disciplinas:\n";

            for (int j = 0; j < numero_de_disciplinas; j++) {
                cout << "Digite o codigo da disciplina " << j + 1 << ": ";
                cin >> aluno[i].disciplina[j].codigo;
                cout << "Digite o nome da disciplina " << j + 1 << ": ";
                cin >> aluno[i].disciplina[j].nome;
                cout << "Digite o professor da disciplina " << j + 1 << ": ";
                cin >> aluno[i].disciplina[j].professor;
                cout << "Digite a quantidade de creditos da disciplina " << j + 1 << ": ";
                cin >> aluno[i].disciplina[j].creditos;
            }

            teste << "Aluno: " << aluno[i].nome << "\n    Codigo: " << aluno[i].codigo << "\n    cpf: " << aluno[i].cpf << "\n    Materias cursadas: \n";
            for (int j = 0; j < numero_de_disciplinas; j++) {
                teste << "         Codigo: " << aluno[i].disciplina[j].codigo << "\n            Nome: " << aluno[i].disciplina[j].nome << "\n            Professor: " << aluno[i].disciplina[j].professor << "\n            Creditos: " << aluno[i].disciplina[j].creditos << "\n";
            }
            teste << "\n";
        }

        teste.close();

        cout << "Gostaria de continuar? Y/y se sim e qualquer outra tecla se nao: ";
        cin >> continuar;
    }
    return 0;
}
