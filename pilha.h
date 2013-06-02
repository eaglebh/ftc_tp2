#ifndef PILHA_H
#define PILHA_H

#include <stack>
#include "simbolo.h"


using namespace std;

class Pilha : public stack<Simbolo>
{
public:
    Pilha();
    void empilha(Simbolo simbolo);
    void desempilha();
    Simbolo &topo();
};

#endif // PILHA_H
