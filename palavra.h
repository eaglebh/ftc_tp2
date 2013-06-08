#ifndef PALAVRA_H
#define PALAVRA_H

#include <list>
#include "simbolo.h"

using namespace std;

class Palavra
{
private:
    list<Simbolo> simbolos;
    list<Simbolo>::iterator simboloAtual;
    bool inicializado;

public:
    Palavra(list<Simbolo> simbolos);
    Palavra(const string &l_simbolos);
    Simbolo &prox();

    void imprime();
    string texto();
};

#endif // PALAVRA_H
