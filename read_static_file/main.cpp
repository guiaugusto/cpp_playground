#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void clean_breaklines(string file_name){
    // String para armazenar cada linha
    string s;

    // Cria vetor para armanzenar cada linha válida no arquivo .txt
    vector<string> content_file;

    // Cria arquivo para leitura
    ifstream file;

    // Abre arquivo
    file.open(file_name.c_str());

    // Variável para informar em qual linha existe um '\n'
    int numero_linha = 1;

    // Looping para percorrer todo o arquivo capturando apenas as quebras de linha
    while(getline(file, s)){
        // Se a linha tiver um '\n'
        if(s.size() == 0){
            cout << "Tem espaço aqui na linha " << numero_linha << "!" << endl;
        }else{
            // Coloca a linha válida no vetor
            content_file.push_back(s);
        }
        numero_linha++;
    }

    // Fecha arquivo
    file.close();

    // Remove arquivo para criar um novo com o mesmo nome
    remove(file_name.c_str());

    // Abre arquivo para escrita
    ofstream new_file;

    // Opcional: coloquei um outro nome para melhor visualização
    file_name = "new_" + file_name;

    // Abre novo arquivo para escrita
    new_file.open(file_name.c_str());

    // Insere no arquivo cada linha armazenada no vetor
    for(int i = 0; i < content_file.size(); i++){
        new_file << content_file[i] << endl;
    }

    // Fecha o novo arquivo
    new_file.close();
}

int main(){

    string file_name;

    cout << "Insira o nome do arquivo a ser executado: " << endl;
    cin >> file_name;

    clean_breaklines(file_name);

    return 0;
}
