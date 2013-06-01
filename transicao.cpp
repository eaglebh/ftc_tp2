#include "transicao.h"

Transicao::Transicao(Estado estadoAtual, Simbolo simboloEntrada, Simbolo simboloADesemplilhar,
                     Estado estadoSeguinte, Simbolo simboloAEmpilhar)
    :estadoAtual(estadoAtual),simboloEntrada(simboloEntrada), simboloADesemplilhar(simboloADesemplilhar),
      estadoSeguinte(estadoSeguinte), simboloAEmpilhar(simboloAEmpilhar)
{
}
