#ifndef TRANSICAO_H
#define TRANSICAO_H

#include "estado.h"
#include "simbolo.h"

class Transicao
{
private:
    Estado* estadoAtual;
    Simbolo* simboloEntrada;
    Simbolo* simboloADesempilhar;

    Estado* estadoSeguinte;
    Simbolo* simbolosAEmpilhar;

public:
    Transicao(Estado* estadoAtual, Simbolo* simboloEntrada, Simbolo* simboloADesempilhar,
              Estado* estadoSeguinte, Simbolo* simbolosAEmpilhar);
    string texto();
    void imprimir();
};

#endif // TRANSICAO_H
