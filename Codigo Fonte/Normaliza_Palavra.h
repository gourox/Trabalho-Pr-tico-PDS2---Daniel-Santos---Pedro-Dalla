#ifndef NORMALIZA_PALAVRA_H
#define NORMALIZA_PALAVRA_H

#include <string>

using std::string;

class NormalizaPalavra {
    public:

void RemoveCaracteresEspeciais(std::string _palavra);
void ConverteEmMinusculas();
void RetornaNormalizada();

    private:
    string* _palavra;
};

#endif