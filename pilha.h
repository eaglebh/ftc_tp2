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
    Simbolo desempilha();
};

#endif // PILHA_H
