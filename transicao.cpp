#include "transicao.h"
#include <iostream>
#include <sstream>

using namespace std;

Transicao::Transicao(Estado *estadoAtual, Simbolo *simboloEntrada, Simbolo *simboloADesempilhar,
                     Estado *estadoSeguinte, list<Simbolo *> simbolosAEmpilhar)
    :estadoAtual(estadoAtual),simboloEntrada(simboloEntrada), simboloADesempilhar(simboloADesempilhar),
      estadoSeguinte(estadoSeguinte), simbolosAEmpilhar(simbolosAEmpilhar)
{
}

Transicao::Transicao(Estado *estadoAtual, Simbolo *simboloEntrada, Simbolo *simboloADesempilhar)
    :estadoAtual(estadoAtual),simboloEntrada(simboloEntrada), simboloADesempilhar(simboloADesempilhar)
{
}

bool Transicao::operator==(const Transicao &other) const {
    return (this->estadoAtual->igual(*other.estadoAtual) &&
            this->simboloEntrada->igual(*other.simboloEntrada) &&
            this->simboloADesempilhar->igual(*other.simboloADesempilhar) );
}

Estado *Transicao::getEstadoSeguinte()
{
    return this->estadoSeguinte;
}

list<Simbolo *> Transicao::getSimbolosAEmpilhar()
{
    return this->simbolosAEmpilhar;
}

string Transicao::texto()
{
    stringstream texto;

    texto << '(' << this->estadoAtual->texto() << ',' <<
             this->simboloEntrada->texto() << ',' <<
             this->simboloADesempilhar->texto() << ',' <<
             this->estadoSeguinte->texto() << ',';
    for (std::list<Simbolo*>::iterator it=this->simbolosAEmpilhar.begin(); it != this->simbolosAEmpilhar.end(); ++it){
        texto << (*it)->texto();
    }
    texto << ')';

    return texto.str();
}

void Transicao::imprimir()
{
    cout << "transicao=" << texto() << endl;
}
