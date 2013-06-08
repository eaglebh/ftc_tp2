#include "palavra.h"

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
        simboloAtual = this->simbolos.begin();
        inicializado = true;
        return *simboloAtual;
    }
    advance(simboloAtual,1);

    if(simboloAtual != simbolos.end()) {
        return *simboloAtual;
    }
}
