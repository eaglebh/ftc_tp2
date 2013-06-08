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

    Estado *getEstadoSeguinte();
    list<Simbolo*> getSimbolosAEmpilhar();

    string texto();
    void imprimir();
    bool operator ==(const Transicao &other) const;
};

#endif // TRANSICAO_H
