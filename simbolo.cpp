#include "simbolo.h"
#include <iostream>

using namespace std;

Simbolo::Simbolo(string nome):
    nome(nome)
{
}

bool Simbolo::igual(const Simbolo outro)
{
    return (outro.nome == this->nome);
}

string Simbolo::texto()
{
    return this->nome;
}

void Simbolo::imprimir()
{
     cout << "simbolo=" << texto() << endl;
}
