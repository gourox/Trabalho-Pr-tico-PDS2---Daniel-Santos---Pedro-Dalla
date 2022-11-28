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
                indice_[palavra].insert(documento);
            
        }



    }
}

void pesquisa::pesquisar(string palavra){



    

    if(auto it = indice_.find(palavra); it != indice_.end()){
        
        set<string> x = it->second;

        while(x.empty() == false){
            string max;

            max = *(x.rbegin());
            x.erase(max);
            max.erase(0, 11);

            cout << max << endl;

            
        }

    }



}

pesquisa::~pesquisa(){
    indice_.clear();
}