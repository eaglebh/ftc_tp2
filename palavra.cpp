#include "palavra.h"
#include <iostream>
#include <sstream>

using namespace std;

Palavra::Palavra(list<Simbolo> simbolos) :
    simbolos(simbolos)
{
    inicializado = false;
}

Palavra::Palavra(const string &l_simbolos)
{
    for(int i=0; i < l_simbolos.length(); ++i) {
        string simbolo = l_simbolos.substr(i, 1);
        this->simbolos.push_back(Simbolo(simbolo));
    }

    inicializado = false;
}

Simbolo& Palavra::prox()
{
    if(!inicializado) {
        if(this->simbolos.size() > 0) {
            inicializado = true;
            simboloAtual = this->simbolos.begin();
            return *simboloAtual;
        } else {
            inicializado = false;
            Simbolo *simbolo = new Simbolo(Simbolo::DELTA);
            return *simbolo;
        }
    }
    advance(simboloAtual,1);

    if(simboloAtual != simbolos.end()) {
        return *simboloAtual;
    } else {
        Simbolo *simbolo = new Simbolo(Simbolo::DELTA);
        return *simbolo;
    }

}

string Palavra::texto() {
    stringstream texto;
    if(simbolos.size() > 0) {
        for(list<Simbolo>::iterator it = simboloAtual; it != simbolos.end(); ++it) {
            texto << (*it).texto();
        }
    }
    return texto.str();
}

void Palavra::imprime() {
    cout << "palavra: ";
    cout << texto();
    cout << endl;
}
