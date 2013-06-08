#ifndef PILHA_H
#define PILHA_H

#include <stack>
#include "simbolo.h"
#include <list>

using namespace std;

class Pilha : public stack<Simbolo>
{
private:
    string texto;
public:
    Pilha();
    void empilha(Simbolo simbolo);
    void empilha(list<Simbolo *> simbolos);
    void desempilha();
    Simbolo &topo();
    void imprime();
};

#endif // PILHA_H
