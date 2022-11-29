#include "pesquisa.h"

#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

pesquisa::pesquisa(string caminho){

    const fs::path documentos{caminho};

    if(fs::exists(caminho) == false){

        CaminhoInexistente x;

        throw x;
    }

    else if(fs::is_empty(caminho) == true){

        PastaVazia x;

        throw x;
    }

    set<string> lista;

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

vector<string> pesquisa::ordenar(set<string> x){

    vector<string> v;

    for(string s : x){

            s.erase(0, 11);

            v.push_back(s);

        }

        sort(v.begin(), v.end());

       return v;
}

vector<string> pesquisa::pesquisar(string palavra){

    if(auto it = indice_.find(normaliza(palavra)); it != indice_.end()){
        
        vector<string> v = ordenar(it -> second);

        return v;

    }else{

            PalavraInexistente x;
            
            throw x;
            
        }



}

pesquisa::~pesquisa(){
    indice_.clear();
}