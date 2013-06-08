#include "pilha.h"
#include <iostream>

using namespace std;

Pilha::Pilha()
{
}

void Pilha::empilha(Simbolo simbolo)
{
    if(!simbolo.igual(Simbolo(Simbolo::LAMBDA))) {
        push(simbolo);
        texto.append(simbolo.texto());
    }
    imprime();
}

void Pilha::empilha(list<Simbolo*> simbolos)
{
    for (std::list<Simbolo*>::reverse_iterator rit=simbolos.rbegin(); rit!=simbolos.rend(); ++rit) {
        empilha(**rit);
    }
}

void Pilha::desempilha()
{
    pop();
    texto.erase(texto.length()-1, 1);
    imprime();
}

Simbolo& Pilha::topo()
{
    return top();
}

void Pilha::imprime() {
    cout << "pilha: [" << texto << "]" << endl;
}
