#include "transicao.h"
#include <iostream>
#include <sstream>

using namespace std;

Transicao::Transicao(Estado *estadoAtual, Simbolo *simboloEntrada, Simbolo *simboloADesemplilhar,
                     Estado *estadoSeguinte, list<Simbolo *> simbolosAEmpilhar)
    :estadoAtual(estadoAtual),simboloEntrada(simboloEntrada), simboloADesempilhar(simboloADesemplilhar),
      estadoSeguinte(estadoSeguinte), simbolosAEmpilhar(simbolosAEmpilhar)
{
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
