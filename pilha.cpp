#include "pilha.h"

Pilha::Pilha()
{
}

void Pilha::empilha(Simbolo simbolo)
{
    push(simbolo);
}

Simbolo Pilha::desempilha()
{
    Simbolo simbolo = top();

    pop();

    return simbolo;
}
