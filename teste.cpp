#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Para usar a função std::remove

using namespace std;

class disciplina {
public:
    string codigo_disciplina;
    string nome_disciplina;
    string professor;
    string creditos;
};

class aluno {
public:
    string codigo_aluno;
    string nome_aluno;
    string cpf;
    vector<disciplina> disciplinas_cursadas;
};

void adicionarDisciplina(aluno &aluno, int index) {
    disciplina nova_disciplina;
    cout << "Digite o codigo da disciplina " << index + 1 << ": ";
    cin >> nova_disciplina.codigo_disciplina;
    cout << "Digite o nome da disciplina " << index + 1 << ": ";
    cin >> nova_disciplina.nome_disciplina;
    cout << "Digite o professor da disciplina " << index + 1 << ": ";
    cin >> nova_disciplina.professor;
    cout << "Digite a quantidade de creditos da disciplina " << index + 1 << ": ";
    cin >> nova_disciplina.creditos;
    aluno.disciplinas_cursadas.push_back(nova_disciplina);
}


void removerDisciplina(aluno& aluno, int index) {
    if (index >= 0 && index < aluno.disciplinas_cursadas.size()) {
        aluno.disciplinas_cursadas.erase(aluno.disciplinas_cursadas.begin() + index);
        cout << "Disciplina removida com sucesso!\n";
    } else {
        cout << "Indice de disciplina invalido.\n";
    }
}

int main() {
    char continuar = 'y';
    while (continuar == 'y' || continuar == 'Y') {
        int opcao;
        int ano, periodo, numero_de_alunos, numero_de_disciplinas;

        string sano, speriodo, titulo_txt;

        cout << "\n---------- Cadastro de aluno -----------\n\n\n";
        cout << "Digite o ano em que se encontra para cadastrar o aluno: ";
        cin >> ano;
        cout << "Digite o periodo em que voce se encontra atualmente: ";
        cin >> periodo;
        cout << "Digite quantos alunos voce deseja cadastrar: ";
        cin >> numero_de_alunos;
        vector<aluno> alunos(numero_de_alunos);

        sano = to_string(ano);
        speriodo = to_string(periodo);
        titulo_txt = sano + "_" + speriodo + ".txt";

        ofstream teste(titulo_txt);

        for (int i = 0; i < numero_de_alunos; i++) {
            cout << "Cadastro do aluno " << i + 1 << ":\nQuantas disciplinas deseja cadastrar? ";
            cin >> numero_de_disciplinas;
            alunos[i].disciplinas_cursadas.resize(numero_de_disciplinas);

            cout << "Digite o nome do aluno: ";
            cin >> alunos[i].nome_aluno;
            cout << "Digite o codigo do aluno: ";
            cin >> alunos[i].codigo_aluno;
            cout << "Digite o cpf do aluno (apenas numeros): ";
            cin >> alunos[i].cpf;
            cout << "Cadastro de disciplinas:\n";

            for (int j = 0; j < numero_de_disciplinas; j++) {
                adicionarDisciplina(alunos[i], j);
            }

            teste << "Aluno: " << alunos[i].nome_aluno << "\n    Codigo: " << alunos[i].codigo_aluno << "\n    cpf: " << alunos[i].cpf << "\n    Materias cursadas: \n";
            for (int j = 0; j < alunos[i].disciplinas_cursadas.size(); j++) {
                teste << "         Codigo: " << alunos[i].disciplinas_cursadas[j].codigo_disciplina << "\n            Nome: " << alunos[i].disciplinas_cursadas[j].nome_disciplina << "\n            Professor: " << alunos[i].disciplinas_cursadas[j].professor << "\n            Creditos: " << alunos[i].disciplinas_cursadas[j].creditos << "\n";
            }
            teste << "\n";
        }

        teste.close();

        cout << "Menu de opções:\n";
        cout << "1. Adicionar aluno\n";
        cout << "2. Remover aluno\n";
        cout << "3. Adicionar disciplina a aluno\n";
        cout << "4. Remover disciplina de aluno\n";
        cout << "Escolha a opção desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                // Adicionar aluno (pode implementar aqui)
                break;
            case 2:
                // Remover aluno (pode implementar aqui)
                break;
            case 3:
                // Adicionar disciplina a aluno
                // (mantive a funcionalidade existente de adicionar disciplina)
                break;
            case 4:
                int aluno_index, disciplina_index;
                cout << "Digite o indice do aluno que deseja remover disciplina: ";
                cin >> aluno_index;
                cout << "Digite o indice da disciplina que deseja remover: ";
                cin >> disciplina_index;
                if (aluno_index >= 0 && aluno_index < alunos.size()) {
                    removerDisciplina(alunos[aluno_index], disciplina_index);
                } else {
                    cout << "Indice de aluno invalido.\n";
                }
                break;
            default:
                cout << "Opcao invalida.\n";
                break;
        }

        cout << "Gostaria de continuar? Y/y se sim e qualquer outra tecla se nao: ";
        cin >> continuar;
    }
    return 0;
}

