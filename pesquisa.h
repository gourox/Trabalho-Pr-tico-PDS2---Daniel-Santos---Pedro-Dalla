#pragma once
#include <filesystem>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;


class pesquisa{
    public:

    //cria um indice invertido vazio
    pesquisa(string caminho);

    //retorna vetor com resultados de pesquisas (ordenados por valor léxicográfico dos arquivos)
    void pesquisar(string palavra);

    //normaliza palavra
    string normaliza(std::string palavra);

    //destructor
    ~pesquisa();

    private:

    map<string, set<string>> indice_;
};

struct CaminhoInexistente{
    
};

struct PastaVazia{
    
};

struct PalavraInexistente{
    
};

