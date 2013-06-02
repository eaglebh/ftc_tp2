#ifndef PILHA_H
#define PILHA_H

#include <stack>
#include "simbolo.h"
#include <list>

using namespace std;

class Pilha : public stack<Simbolo>
{
public:
    Pilha();
    void empilha(Simbolo simbolo);
    void empilha(list<Simbolo *> simbolos);
    void desempilha();
    Simbolo &topo();
};

#endif // PILHA_H
