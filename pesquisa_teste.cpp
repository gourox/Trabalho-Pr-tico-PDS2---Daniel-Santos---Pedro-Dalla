#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pesquisa.h"

using namespace std;

string normaliza(std::string palavra){
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

TEST_CASE("Testa função normaliza()"){

    CHECK(normaliza("stevew@helios.unl.edu") == "stevewheliosunledu");
    CHECK(normaliza( "_maca")== "maca");
    CHECK(normaliza("$dinheiros$") == "dinheiros");
}
