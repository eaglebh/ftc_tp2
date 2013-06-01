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

public:
    Palavra(list<Simbolo> simbolos);
    Palavra(string simbolos);
    Simbolo prox();

};

#endif // PALAVRA_H
