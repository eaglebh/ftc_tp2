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
        pilhaTexto.insert(0, simbolo.texto());
    }
}

void Pilha::empilha(list<Simbolo*> simbolos)
{
    for (std::list<Simbolo*>::reverse_iterator rit=simbolos.rbegin(); rit!=simbolos.rend(); ++rit) {
        empilha(**rit);
    }
}

void Pilha::desempilha()
{
    if(topo().igual(Simbolo(Simbolo::DELTA))) {
        return;
    }
    pop();
    pilhaTexto.erase(0, 1);
}

Simbolo Pilha::topo()
{
    Simbolo topoPilha = top();
    return topoPilha;
}

string Pilha::texto(){
    return pilhaTexto;
}

void Pilha::imprime() {
    cout << "pilha: [" << texto() << "]" << endl;
}
