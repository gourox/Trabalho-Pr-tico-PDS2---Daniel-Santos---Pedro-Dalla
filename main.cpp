#include <stdio.h>
#include "pesquisa.h"
#include <iostream>
#include <filesystem>
#include "normaliza_palavra.h"

using namespace std;
namespace fs = std::filesystem;

int main(){
    pesquisa p("documentos");

    string palavra;

    do{
    cout << "Insira a palavra a ser pesquisada" << endl << endl;

    cin >> palavra;

    cout << endl;

    p.pesquisar(palavra);

    }while(cin >> palavra);

    return 0;
}