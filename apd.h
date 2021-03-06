#ifndef APD_H
#define APD_H

#include <list>
#include "simbolo.h"
#include "estado.h"
#include "transicao.h"
#include "palavra.h"
#include "pilha.h"

class Apd
{
private:
    list<Estado> estados;
    list<Simbolo> alfabetoFita;
    list<Simbolo> alfabetoPilha;

    list<Transicao> transicoes;

    Estado* estadoInicial;
    list<Estado*> estadosFinais;

    Palavra *palavra;
    Pilha *pilha;

public:
    Apd();

    void setEstados(list<Estado> estados);
    void setAlfabetoFita(list<Simbolo> alfabetoFita);
    void setAlfabetoPilha(list<Simbolo> alfabetoPilha);

    void setTransicoes(list<Transicao> transicoes);

    void setEstadoInicial(Estado* estadoInicial);
    void setEstadosFinais(list<Estado*> estadosFinais);

    bool executar(const string palavraEntrada);

    void imprimir();
    void executarTransicoes(Estado &estadoAtual, Simbolo &proximoSimbolo, Simbolo &desempilhar);
    bool procuraTransicaoLambdaLambda(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar);
    bool procuraTransicao(Estado estadoAtual, Transicao &transicao, Simbolo &simboloEntrada, Simbolo &desempilhar);
    bool procuraTransicaoProxSimboloTopo(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar);
    bool procuraTransicaoProxSimboloLambda(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar);
    bool procuraTransicaoLambdaTopo(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar);
};

#endif // APD_H
