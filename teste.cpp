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

void escrever_no_arquivo(string nome_do_arquivo,vector<class aluno> &alunos, vector<class disciplina> &disciplinas){
    ofstream arquivo;
    arquivo.open(nome_do_arquivo,ios::out|ios::trunc);
    if(arquivo.is_open()){
        arquivo << "ALUNOS:" <<endl;
        for(int i=0;i<alunos.size();i++){
            arquivo << alunos[i].codigo_aluno << endl;
            arquivo << alunos[i].nome_aluno << endl;
            arquivo << alunos[i].cpf << endl;
            for(int j=0;j<alunos[i].disciplinas_cursadas.size();j++){
                arquivo << alunos[i].disciplinas_cursadas[j].nome_disciplina << endl;
            }
            arquivo << "\n\n" << endl;
        }
        arquivo << "DISCIPLINAS:\n";
        for(int i=0;i<disciplinas.size();i++){
            arquivo << disciplinas[i].codigo_disciplina << endl;
            arquivo << disciplinas[i].nome_disciplina << endl;
            arquivo << disciplinas[i].professor << endl;
            arquivo << disciplinas[i].creditos << endl;
            for(int j=0;j<disciplinas[i].alunos_na_disciplina.size();j++){
                arquivo << disciplinas[i].alunos_na_disciplina[j].nome_aluno << endl;
            }
            arquivo << endl;
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
    if(arquivo.is_open()){
        while(!arquivo.eof()){
            getline(arquivo,temp);
            if(temp=="ALUNOS:"){
                temp2=temp;
                continue;
            }
            if(temp.empty()){
                continue;
            }
            if(temp!="ALUNOS:" && temp2=="ALUNOS:"&&temp!="DISCIPLINAS:"){
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
            if(temp=="DISCIPLINAS:"){
                temp2=temp;
                i=0;
                continue;
            }
            if(temp!="DISCIPLINAS:"&& temp2=="DISCIPLINAS:"){
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
                        j=0;
                        break;
                    }
                    else{
                        disciplinas[i].alunos_na_disciplina.push_back(aluno_temp);
                        disciplinas[i].alunos_na_disciplina[j].nome_aluno=temp;
                        j++;
                    }

                }
                i++;
            }


        } 
    }
    arquivo.close(); 
}

void adicionarDisciplina(vector <disciplina> &disciplina,vector <aluno> &alunos) {
    class aluno novo_aluno;
    class disciplina disciplina_nova;
    int k = 0, m;
    int size;
    int size2;
    int size3 = alunos.size();
    string nome_do_aluno;
    int numero_de_alunos;
    disciplina.push_back(disciplina_nova);
    size=disciplina.size();
    cout << "Digite o nome da disciplina (letras todas minusculas):";
    cin >> disciplina[size-1].nome_disciplina;
    cout << "Digite o codigo da disciplina: ";
    cin >> disciplina[size-1].codigo_disciplina;
    cout << "Digite o professor da disciplina: ";
    cin >> disciplina[size-1].professor;
    cout << "Quantos creditos ha na disciplina?";
    cin >> disciplina[size-1].creditos;
    cout << "Quantos alunos deseja cadastrar nessa disciplina?";
    cin >> numero_de_alunos;
    for (int j = 0; j < numero_de_alunos; j++) {
        cout << "Coloque o nome do " << j+1 << " aluno (letras todas minusculas):";
        cin >> nome_do_aluno;
        for (int i = 0; i < alunos.size(); i++)
        {
            if (alunos[i].nome_aluno == nome_do_aluno)
            {
                k++;
                m = i;
            }
        }
        if (k==1)
        {
            for (int l = 0; l < alunos[m].disciplinas_cursadas.size(); l++)
            {
                if (alunos[m].disciplinas_cursadas[l].nome_disciplina == disciplina[size-1].nome_disciplina)
                {
                    cout << "o aluno " <<  alunos[m].nome_aluno << "ja se encontra na disciplina" << alunos[m].disciplinas_cursadas[l].nome_disciplina << '\n';
                    k = 0;
                }
                break;
            }
            if (k != 0)
            {
                alunos[m].disciplinas_cursadas.push_back(disciplina[size - 1]);
            }
        }
        else{
            alunos[j].disciplinas_cursadas.push_back(disciplina[size - 1]);
        }
        disciplina[size-1].alunos_na_disciplina.push_back(novo_aluno);
        size2=disciplina[size-1].alunos_na_disciplina.size();
        disciplina[size-1].alunos_na_disciplina[size2-1].nome_aluno = nome_do_aluno;
    }
}

void adicionarAluno(vector <class aluno> &alunos, vector <class disciplina> &disciplina){
    class aluno novo_aluno;
    class disciplina disciplina_nova;
    string nome_da_disciplina;
    int numero_de_disciplinas;
    alunos.push_back(novo_aluno);
    int k = 0, m;
    int size;
    int size2;
    size=alunos.size();
    cout << "Digite o nome do aluno (letras todas minusculas):";
            cin >> alunos[size-1].nome_aluno;
            cout << "Digite o codigo do aluno: ";
            cin >> alunos[size-1].codigo_aluno;
            cout << "Digite o cpf do aluno (apenas numeros): ";
            cin >> alunos[size-1].cpf;
            cout << "Quantas disciplinas deseja cadastrar o aluno?";
            cin >> numero_de_disciplinas;
            for (int j = 0; j < numero_de_disciplinas; j++) {
                cout << "Coloque o nome da " << j+1 << " disciplina (letras todas minusculas):";
                cin >> nome_da_disciplina;
                alunos[size-1].disciplinas_cursadas.push_back(disciplina_nova);
                size2=alunos[size-1].disciplinas_cursadas.size();
                alunos[size-1].disciplinas_cursadas[size2-1].nome_disciplina = nome_da_disciplina;
                for (int i = 0; i < disciplina.size(); i++)
                {
                    if (disciplina[i].nome_disciplina == nome_da_disciplina)
                    {
                        m = i;
                        k++;
                    }
                }
                if (k == 0)
                {
                    disciplina.push_back(disciplina_nova);
                    disciplina[disciplina.size() - 1].alunos_na_disciplina.push_back(novo_aluno);
                }
                else{
                    disciplina[m].alunos_na_disciplina.push_back(novo_aluno);
                } 
            }
}

int adicionardisciplinaaoaluno(vector <class aluno> &alunos,vector <class disciplina> &disciplinas,string nome_da_disciplina,string codigo_aluno){
    class disciplina disciplina_temp;
    class aluno aluno_temp;
    string nome_do_aluno;
    int size=alunos.size();
    int size_2=disciplinas.size();
    int size_3 = alunos[0].disciplinas_cursadas.size();
    int size_4 = disciplinas[0].alunos_na_disciplina.size();
    for(int i=0;i<size;i++){
        if(alunos[i].codigo_aluno==codigo_aluno){
            alunos[i].disciplinas_cursadas.push_back(disciplina_temp);
            alunos[i].disciplinas_cursadas[size_3 - 1].nome_disciplina=nome_da_disciplina;
            nome_do_aluno=alunos[i].nome_aluno;
            for(int j=0;j<size_2;j++){
                if(disciplinas[j].nome_disciplina==nome_da_disciplina){
                    disciplinas[j].alunos_na_disciplina.push_back(aluno_temp);
                    disciplinas[j].alunos_na_disciplina[size_4 - 1].nome_aluno=nome_do_aluno;
                }
            }
            return(1);
        }
    }
    cout << "Esse aluno nao existe";
    return(0);
}

int removerDisciplina(vector <aluno> &alunos, string nome_disciplina, string codigo_aluno) {
    int tamanho = alunos.size();
    int tamanho_2;
    for (int i = 0; i < tamanho; i++)
    {
        if (alunos[i].codigo_aluno == codigo_aluno)
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

int ver_os_alunos(vector<disciplina> disciplinas,string codigo_disciplina){
    int size=disciplinas.size();
    int size2;
    for(int i=0;i<size;i++){
        if(disciplinas[i].codigo_disciplina==codigo_disciplina){
            size2=disciplinas[i].alunos_na_disciplina.size();
            for(int j=0;j<size2;j++){
                cout << disciplinas[i].alunos_na_disciplina[j].nome_aluno;
            }
            return(1);

        }
    }
    cout << "nao achei esse codigo de disciplina";
    return(0);

}

int main() {
    char continuar = 'y';
    string nome_de_arquivo;
    vector<aluno> alunos;
    vector<disciplina> disciplinas;
    string codigo_aluno;
    string nome_da_disciplina;
    string codigo_disciplina;
    int opcao;
    string ano, periodo;

    cout << "\n---------- Cadastro de aluno -----------\n\n\n";
    cout << "Digite o ano em que se encontra para cadastrar o aluno: ";
    cin >> ano;
    cout << "Digite o periodo em que voce se encontra atualmente: ";
    cin >> periodo;
        
    nome_de_arquivo = ano + '-' + periodo;

    ler_o_arquivo(nome_de_arquivo,alunos,disciplinas);
    
    while (continuar == 'y' || continuar == 'Y') {

        cout << "Menu de opções:\n";
        cout << "1. Adicionar aluno\n";
        cout << "2. Remover aluno\n";
        cout << "3. Adicionar disciplina\n";
        cout << "4. Adicionar disciplina a um aluno\n";
        cout << "5. Remover disciplina de aluno\n";
        cout << "6. Ver os alunos de uma disciplina\n";
        cout << "Escolha a opção desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarAluno(alunos, disciplinas);
                break;
            case 2:
                cout << "coloque o codigo do aluno";
                cin >> codigo_aluno;
                removerAluno(alunos,disciplinas,codigo_aluno);
                break;
            case 3:
                adicionarDisciplina(disciplinas, alunos);
                break;
            case 4:
                cout << "Coloque o codigo do aluno";
                cin >> codigo_aluno;
                cout << "Coloque o nome da disciplina(letras minusculas)";
                cin >> nome_da_disciplina;
                adicionardisciplinaaoaluno(alunos,disciplinas,nome_da_disciplina,codigo_aluno);
                break;
                
            case 5:
                cout << "Coloque o codigo do aluno";
                cin >> codigo_aluno;
                cout << "Coloque o nome da disciplina(letras minusculas)";
                cin >> nome_da_disciplina;
                removerDisciplina(alunos,nome_da_disciplina,codigo_aluno);
                break;
            case 6:
                cout << "Coloque o codigo da disciplina";
                cin >> codigo_disciplina;
                ver_os_alunos(disciplinas,codigo_disciplina);
                break;
                
            default:
                cout << "Opcao invalida.\n";
                break;
        }

        cout << "Gostaria de continuar? Y/y se sim e qualquer outra tecla se nao: ";
        cin >> continuar;
    }
    escrever_no_arquivo(nome_de_arquivo,alunos,disciplinas);
    return 0;
}

