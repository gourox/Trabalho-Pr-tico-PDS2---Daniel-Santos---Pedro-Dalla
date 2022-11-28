#include "pesquisa.h"

#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

pesquisa::pesquisa(string caminho){

    set<string> lista;

    const fs::path documentos{caminho};

    for (auto const& arquivo : fs::directory_iterator{documentos}){
        lista.insert(arquivo.path());
    }

    for(string documento : lista){

        ifstream arquivo;
        arquivo.open(documento);

        string palavra;

        while(arquivo >> palavra){
                indice_[normaliza(palavra)].insert(documento);
            
        }



    }
}

string pesquisa::normaliza(std::string palavra){
    setlocale(LC_ALL, "portuguese");
    setlocale(LC_ALL, "pt_BR_utf8");
    
    for (int i = 0; i < palavra.size(); i++){

        string auxcedilha = "çÇ";
    
        for (int k = 0; k < auxcedilha.size(); k++){
            if (palavra[i] == auxcedilha[k]){
            palavra[i] = 'c';
            }
        }
        if (ispunct(palavra[i]) || isdigit(palavra[i])){
            palavra.erase(palavra.begin() + i);
            i--;}
    
        palavra[i] = tolower(palavra[i]);

    }

    return palavra;
}

void pesquisa::ordenar(vector<string>& v){

    sort(v.begin(), v.end());

}

void pesquisa::pesquisar(string palavra){

    if(auto it = indice_.find(normaliza(palavra)); it != indice_.end()){

        cout << "Os seguintes arquivos relevantes foram encontrados:" << endl << endl;
        
        set<string> x = it->second;

        vector<string> v;

        for(string s : x){
            v.push_back(s);
        }

        ordenar(v);

        for(string s : v){

            cout << s << endl << endl;
        }

    }



}

pesquisa::~pesquisa(){
    indice_.clear();
}