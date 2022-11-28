#include "normaliza_palavra.h"

#include <vector>
#include <cctype>
#include <iostream>
#include <locale>
#include <string>

void NormalizaPalavra::RemoveCaracteresEspeciais(std::string palavra){
    
    string auxcedilha = "çÇ";
    this->_palavra = palavra;
    

    for (int i = 0; i < _palavra.size(); i++){
    
        for (int k = 0; k < auxcedilha.size(); k++){
            if (_palavra[i] == auxcedilha[k]){
            _palavra[i] = 'c';
            }
        }
    if (ispunct(_palavra[i]) || isdigit(_palavra[i])){
        _palavra.erase(_palavra.begin() + i);
        i--;}
    }
}

void NormalizaPalavra::ConverteEmMinusculas(std::string palavra){
    this->_palavra = palavra;
    for (int i = 0; i < _palavra.size(); i++){
        _palavra[i] = tolower(_palavra[i]);
    }
}

string NormalizaPalavra::RetornaNormalizada(std::string palavra){
    ConverteEmMinusculas(_palavra);
    RemoveCaracteresEspeciais(_palavra);
    return _palavra;

}
