#include "simbolo.h"
#include <iostream>
#include <sstream>

using namespace std;

Simbolo::Simbolo(string nome):
    nome(nome)
{
}

Simbolo::Simbolo(char nome)
{
    stringstream strstream;
    strstream << nome;

    this->nome = strstream.str();
}

bool Simbolo::igual(const Simbolo outro)
{
    return (outro.nome == this->nome);
}

string Simbolo::texto()
{
#ifdef __unix__
    if(this->nome.at(0) == LAMBDA) {
        return "\u03BB";
    } else if(this->nome.at(0) == DELTA) {
        return "\u0394";
    }
#endif
    return this->nome;
}

void Simbolo::imprimir()
{
     cout << "simbolo=" << texto() << endl;
}
