#ifndef TRANSICAO_H
#define TRANSICAO_H

#include "estado.h"
#include "simbolo.h"

class Transicao
{
private:
    Estado estadoAtual;
    Simbolo simboloEntrada;
    Simbolo simboloADesemplilhar;

    Estado estadoSeguinte;
    Simbolo simboloAEmpilhar;

public:
    Transicao(Estado estadoAtual, Simbolo simboloEntrada, Simbolo simboloADesemplilhar,
              Estado estadoSeguinte, Simbolo simboloAEmpilhar);
};

#endif // TRANSICAO_H
