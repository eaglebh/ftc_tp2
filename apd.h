#ifndef APD_H
#define APD_H

#include <list>
#include "simbolo.h"
#include "estado.h"
#include "transicao.h"

class Apd
{
private:
    list<Estado> estados;
    list<Simbolo> alfabetoFita;
    list<Simbolo> alfabetoPilha;

    list<Transicao> transicoes;

    Estado* estadoInicial;
    list<Estado*> estadosFinais;

public:
    Apd();

    void setEstados(list<Estado> estados);
    void setAlfabetoFita(list<Simbolo> alfabetoFita);
    void setAlfabetoPilha(list<Simbolo> alfabetoPilha);

    void setTransicoes(list<Transicao> transicoes);

    void setEstadoInicial(Estado* estadoInicial);
    void setEstadosFinais(list<Estado*> estadosFinais);

    void imprimir();
};

#endif // APD_H
