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
    vector<class aluno> alunos_na_disciplina;
};

class aluno {
public:
    string codigo_aluno;
    string nome_aluno;
    string cpf;
    vector<disciplina> disciplinas_cursadas;
};

void adicionarDisciplina(vector <disciplina> &disciplina) {
    class aluno novo_aluno;
    class disciplina disciplina_nova;
    string nome_do_aluno;
    int numero_de_alunos;
    disciplina.push_back(disciplina_nova);
    cout << "Digite o nome da disciplina (letras todas minusculas):";
            cin >> disciplina[-1].nome_disciplina;
            cout << "Digite o codigo da disciplina: ";
            cin >> disciplina[-1].codigo_disciplina;
            cout << "Digite o professor da disciplina: ";
            cin >> disciplina[-1].professor;
            cout << "Quantos creditos ha na disciplina?";
            cin >> disciplina[-1].creditos;
            cout << "Quantos alunos deseja cadastrar nessa disciplina?";
            cin >> numero_de_alunos;
            for (int j = 0; j < numero_de_alunos; j++) {
                cout << "Coloque o nome do " << j+1 << " aluno (letras todas minusculas):";
                cin >> nome_do_aluno;
                disciplina[-1].alunos_na_disciplina.push_back(novo_aluno);
                disciplina[-1].alunos_na_disciplina[-1].nome_aluno = nome_do_aluno;
            }
}

void adicionarAluno(vector <class aluno> &alunos){
    class aluno novo_aluno;
    class disciplina disciplina_nova;
    string nome_da_disciplina;
    int numero_de_disciplinas;
    alunos.push_back(novo_aluno);
    cout << "Digite o nome do aluno (letras todas minusculas):";
            cin >> alunos[-1].nome_aluno;
            cout << "Digite o codigo do aluno: ";
            cin >> alunos[-1].codigo_aluno;
            cout << "Digite o cpf do aluno (apenas numeros): ";
            cin >> alunos[-1].cpf;
            cout << "Quantas disciplinas deseja cadastrar o aluno?";
            cin >> numero_de_disciplinas;
            for (int j = 0; j < numero_de_disciplinas; j++) {
                cout << "Coloque o nome da " << j+1 << " disciplina (letras todas minusculas):";
                cin >> nome_da_disciplina;
                alunos[-1].disciplinas_cursadas.push_back(disciplina_nova);
                alunos[-1].disciplinas_cursadas[-1].nome_disciplina = nome_da_disciplina;
            }
}

int removerDisciplina(vector <aluno> &alunos, string nome_disciplina, string nome_do_aluno) {
    int tamanho = alunos.size();
    int tamanho_2;
    for (int i = 0; i < tamanho; i++)
    {
        if (alunos[i].nome_aluno == nome_do_aluno)
        {
            tamanho_2 = alunos[i].disciplinas_cursadas.size();
            for (int j = 0; j < tamanho_2; j++)
            {
                if (alunos[i].disciplinas_cursadas[j].nome_disciplina == nome_disciplina)
                {
                    alunos[i].disciplinas_cursadas.erase(alunos[i].disciplinas_cursadas.begin() + j);
                    return 1;
                }
            }
            cout << "nao encontrou a disciplina";
            return 0;    
        }    
    }
    cout << "nao encontrou o aluno";
    return 0;
}

int removerAluno(vector <aluno> &alunos, vector <disciplina> &disciplina, string codigo_aluno){
    int tamanho = alunos.size();
    int tamanho_disciplina = disciplina.size();
    int tamanho_3;
    for (int i = 0; i < tamanho_disciplina; i++)
    {
        tamanho_3 = disciplina[i].alunos_na_disciplina.size();
        for (int j = 0; j < tamanho_3; j++)
        {
            if (disciplina[i].alunos_na_disciplina[j].codigo_aluno == codigo_aluno)
            {
                disciplina[i].alunos_na_disciplina.erase(disciplina[i].alunos_na_disciplina.begin() + j);
            }
        }
    }
    for (int i = 0; i < tamanho; i++)
    {
        if (alunos[i].codigo_aluno == codigo_aluno)
        {
            alunos.erase(alunos.begin() + i);
            return 1;
        }
    }
    cout << "aluno nao cadastrado";
    return 0;
}

int main() {
    char continuar = 'y';
    while (continuar == 'y' || continuar == 'Y') {
        int opcao;
        int ano, periodo, numero_de_alunos, numero_de_disciplinas;

        string nome_de_arquivo, titulo_txt;

        cout << "\n---------- Cadastro de aluno -----------\n\n\n";
        cout << "Digite o ano em que se encontra para cadastrar o aluno: ";
        cin >> ano;
        cout << "Digite o periodo em que voce se encontra atualmente: ";
        cin >> periodo;
        cout << "Digite quantos alunos voce deseja cadastrar: ";
        cin >> numero_de_alunos;
        vector<aluno> alunos(numero_de_alunos);
        nome_de_arquivo = ano + '-' + periodo;

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
        }

        cout << "Menu de opções:\n";
        cout << "1. Adicionar aluno\n";
        cout << "2. Remover aluno\n";
        cout << "3. Adicionar disciplina a aluno\n";
        cout << "4. Remover disciplina de aluno\n";
        cout << "5. Ver os alunos de uma disciplina\n";
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
                int aluno_index, disciplina_index, aluno_na_disciplina_index;
                cout << "Digite o indice do aluno que deseja remover disciplina: ";
                cin >> aluno_index;
                cout << "Digite o indice da disciplina que deseja remover: ";
                cin >> disciplina_index;
                if (aluno_index >= 0 && aluno_index < alunos.size()) {
                    removerDisciplina(alunos[aluno_index], aluno_na_disciplina_index, disciplina_index);
                } else {
                    cout << "Indice de aluno invalido.\n";
                }
                break;
            default:
                cout << "Opcao invalida.\n";
                break;
            case 5:
                break;
        }

        cout << "Gostaria de continuar? Y/y se sim e qualquer outra tecla se nao: ";
        cin >> continuar;
    }
    return 0;
}

