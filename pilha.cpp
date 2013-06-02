#include "pilha.h"

Pilha::Pilha()
{
}

void Pilha::empilha(Simbolo simbolo)
{
    push(simbolo);
}

void Pilha::empilha(list<Simbolo*> simbolos)
{
    for (std::list<Simbolo*>::iterator it=simbolos.begin(); it != simbolos.end(); ++it){
        empilha(**it);
    }
}

void Pilha::desempilha()
{
    pop();
}

Simbolo& Pilha::topo()
{
    return top();
}
