#include "palavra.h"

Palavra::Palavra(list<Simbolo> simbolos) :
    simbolos(simbolos)
{
    simboloAtual = this->simbolos.begin();
}

Palavra::Palavra(string simbolos)
{
    for(int i=0; i < simbolos.length(); ++i) {
        this->simbolos.push_front(Simbolo(simbolos.substr(i, 1)));
    }

    simboloAtual = this->simbolos.begin();
}

Simbolo Palavra::prox()
{
    ++simboloAtual;

    if(simboloAtual != simbolos.end()) {
        return *simboloAtual;
    }
}
