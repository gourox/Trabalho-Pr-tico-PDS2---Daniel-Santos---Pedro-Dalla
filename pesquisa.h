#pragma once

#include <filesystem>
#include <iostream>
#include<fstream>
#include <map>
#include <set>
#include <string>

using namespace std;
namespace fs = std::filesystem;


class pesquisa{
    public:

    //cria um indice invertido vazio
    pesquisa(string caminho);

    //retorna vetor com resultados de pesquisas (ordenados por valor léxicográfico dos arquivos)
    void pesquisar(string palavra);

    //destructor
    ~pesquisa();

    private:

    map<string, set<string>> indice_;
};

