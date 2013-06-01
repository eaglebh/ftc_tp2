#include "transicao.h"
#include <iostream>
#include <sstream>

using namespace std;

Transicao::Transicao(Estado *estadoAtual, Simbolo *simboloEntrada, Simbolo *simboloADesemplilhar,
                     Estado *estadoSeguinte, Simbolo *simbolosAEmpilhar)
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
             this->estadoSeguinte->texto() << ',' <<
             this->simbolosAEmpilhar->texto() << ')';

    return texto.str();
}

void Transicao::imprimir()
{
    cout << "transicao=" << texto() << endl;
}
