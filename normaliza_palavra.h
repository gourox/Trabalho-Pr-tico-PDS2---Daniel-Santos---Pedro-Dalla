#ifndef NORMALIZA_PALAVRA_H
#define NORMALIZA_PALAVRA_H
#include <cctype>
#include <iostream>
#include <locale>
#include <string>

using std::string;

class NormalizaPalavra {
    public:

void RemoveCaracteresEspeciais(std::string _palavra);
void ConverteEmMinusculas(std::string _palavra);
string RetornaNormalizada(std::string palavra);

    private:
    string _palavra;
};

#endif
