#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <list>
#include "estado.h"
#include "simbolo.h"

class Transicao
{
private:
    Estado* estadoAtual;
    Simbolo* simboloEntrada;
    Simbolo* simboloADesempilhar;

    Estado* estadoSeguinte;
    list<Simbolo*> simbolosAEmpilhar;

public:
    Transicao(Estado* estadoAtual, Simbolo* simboloEntrada, Simbolo* simboloADesempilhar,
              Estado* estadoSeguinte, list<Simbolo*> simbolosAEmpilhar);
    Transicao(Estado* estadoAtual, Simbolo* simboloEntrada, Simbolo* simboloADesempilhar);
    string texto();
    void imprimir();
};

#endif // TRANSICAO_H
