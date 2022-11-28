#include <stdio.h>
#include "Normaliza_Palavra.h"
#include "pesquisa.h"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main(){
    pesquisa p("documentos");

    p.pesquisar("(James");

    return 0;
}