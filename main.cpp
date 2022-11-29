#include <stdio.h>
#include "pesquisa.h"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main(){

    try{
        pesquisa p("documentos");

        string palavra;

        while(cout << "Insira a palavra a ser pesquisada" << endl << endl && cin >> palavra){

        cout << endl;

        vector<string> v = p.pesquisar(palavra);

            cout << "Foram encontrados os seguintes documentos relevantes:" << endl << endl;

            for(string s : v){

                cout << s << endl << endl;
            }

        }

    }catch(CaminhoInexistente e){

        cout << "Erro: o caminho especificado não existe" << endl << endl;

    }catch(PastaVazia e){

        cout << "Erro:  pasta especificada não possui documentos" << endl << endl;
    
    }catch(PalavraInexistente e){

        cout << "Erro: nenhum arquivo presente na pasta possuí a(s) palavra(s) pesquisada(s)" << endl << endl;
    }



    return 0;
}