#include "pilha.h"

Pilha::Pilha()
{
}

void Pilha::empilha(Simbolo simbolo)
{
    push(simbolo);
}

void Pilha::desempilha()
{
    pop();
}

Simbolo& Pilha::topo()
{
    return top();
}
