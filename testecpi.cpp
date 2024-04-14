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
    vector<class aluno> alunos_na_disciplina;
};

void escrever_no_arquivo(string nome_do_arquivo,vector<class aluno> alunos, vector<class disciplina> disciplinas){
    ofstream arquivo;
    arquivo.open(nome_do_arquivo,ios::out|ios::trunc);
    if(arquivo.is_open()){
        arquivo << "ALUNOS:\n";
        for(int i=0;i=alunos.size();i++){
            arquivo << alunos[i].codigo_aluno << "\n";
            arquivo << alunos[i].nome_aluno << "\n";
            arquivo << alunos[i].cpf << "\n";
            for(int j=0;j=alunos[i].disciplinas_cursadas.size();j++){
                arquivo << alunos[i].disciplinas_cursadas[j].nome_disciplina << "\n";
            }
            arquivo << "\n\n";
        }
        arquivo << "DISCIPLINAS:\n";
        for(int i=0;i=disciplinas.size();i++){
            arquivo << disciplinas[i].codigo_disciplina << "\n";
            arquivo << disciplinas[i].nome_disciplina << "\n";
            arquivo << disciplinas[i].professor << "\n";
            arquivo << disciplinas[i].creditos << "\n";
            for(int j=0;j=disciplinas[i].alunos_na_disciplina.size();j++){
                arquivo << disciplinas[i].alunos_na_disciplina[j].nome_aluno << "\n";
            }
        }
    }
    else{
        cout << "falha na abertura do arquivo";
    }
    arquivo.close();
}

void ler_o_arquivo(string nome_do_arquivo, vector<class aluno> &alunos, vector<class disciplina> &disciplinas){
    ifstream arquivo;
    string temp;
    string temp2;
    alunos.clear();
    disciplinas.clear();
    class aluno aluno_temp;
    class disciplina disciplina_temp;
    int i=0;
    int j=0;
    arquivo.open(nome_do_arquivo,ios::in);
    while(!arquivo.eof()){
        getline(arquivo,temp);
        if(temp=="ALUNOS:\n"){
            temp2=temp;
            continue;
        }
        if(temp!="ALUNOS:\n" && temp2=="ALUNOS:\n"&&temp!="DISCIPLINAS:\n"){
            alunos.push_back(aluno_temp);
            alunos[i].codigo_aluno= temp;
            getline(arquivo,temp);
            alunos[i].nome_aluno= temp;
            getline(arquivo,temp);
            alunos[i].cpf= temp;
            while(!arquivo.eof()){
                getline(arquivo,temp);
                if(temp.empty()){
                    break;
                }
                else{
                    alunos[i].disciplinas_cursadas.push_back(disciplina_temp);
                    alunos[i].disciplinas_cursadas[j].nome_disciplina=temp;
                    j++;
                }

            }
            i++;
            j=0;
        }
        if(temp=="DISCIPLINAS:\n"){
            temp2=temp;
            i=0;
            continue;
        }
        if(temp!="DISCIPLINAS:\n"&& temp2=="DISCIPLINAS:\n"){
            disciplinas.push_back(disciplina_temp);
            disciplinas[i].codigo_disciplina=temp;
            getline(arquivo,temp);
            disciplinas[i].nome_disciplina=temp;
            getline(arquivo,temp);
            disciplinas[i].professor=temp;
            getline(arquivo,temp);
            disciplinas[i].creditos=temp;
            while(!arquivo.eof()){
                getline(arquivo,temp);
                if(temp.empty()){
                    break;
                }
                else{
                    disciplinas[i].alunos_na_disciplina.push_back(aluno_temp);
                    disciplinas[i].alunos_na_disciplina[j].nome_aluno=temp;
                    j++;
                }

            }
        }


    } 
    arquivo.close(); 
}


