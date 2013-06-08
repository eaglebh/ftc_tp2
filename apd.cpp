#include "apd.h"
#include "palavra.h"
#include <iostream>
#include <algorithm>

Apd::Apd()
{
    pilha = new Pilha();
}

void Apd::setEstados(list<Estado> estados)
{
    this->estados = estados;
}

void Apd::setAlfabetoFita(list<Simbolo> alfabetoFita)
{
    this->alfabetoFita = alfabetoFita;
}

void Apd::setAlfabetoPilha(list<Simbolo> alfabetoPilha)
{
    this->alfabetoPilha = alfabetoPilha;
}

void Apd::setTransicoes(list<Transicao> transicoes)
{
    this->transicoes = transicoes;
}

void Apd::setEstadoInicial(Estado *estadoInicial)
{
    this->estadoInicial = estadoInicial;
}

void Apd::setEstadosFinais(list<Estado *> estadosFinais)
{
    this->estadosFinais = estadosFinais;
}

bool Apd::executar(const string palavraEntrada)
{
    palavra = new Palavra(palavraEntrada);
    Estado estadoAtual(*this->estadoInicial);
    pilha->empilha( Simbolo(Simbolo::DELTA));
    Simbolo proximoSimbolo = palavra->prox();
    Simbolo desempilhar = pilha->topo();

    executarTransicoes(estadoAtual, proximoSimbolo, desempilhar);

    if(proximoSimbolo.igual(Simbolo(Simbolo::DELTA)) && pilha->topo().igual(Simbolo(Simbolo::DELTA)) ) {
        for (std::list<Estado*>::iterator it=this->estadosFinais.begin(); it != this->estadosFinais.end(); ++it){
            if(estadoAtual.igual(**it)) {
                return true;
            }
        }
    }

    return false;
}

bool Apd::procuraTransicaoProxSimboloTopo(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar) {
    if (!procuraTransicao(estadoAtual, transicao, proximoSimbolo, desempilhar)) {
        // tenta com proximoSimbolo e Lambda
        return procuraTransicaoProxSimboloLambda(estadoAtual, transicao, proximoSimbolo, desempilhar);
    }
    return true;
}


bool Apd::procuraTransicaoProxSimboloLambda(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar) {
    Simbolo lambda = Simbolo(Simbolo::LAMBDA);
    if (!procuraTransicao(estadoAtual, transicao, proximoSimbolo, lambda)) {
        // tenta com lambda e topo
        return procuraTransicaoLambdaTopo(estadoAtual, transicao, proximoSimbolo, desempilhar);
    }
    desempilhar = lambda;
    return true;
}

bool Apd::procuraTransicaoLambdaTopo(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar) {
    Simbolo lambda = Simbolo(Simbolo::LAMBDA);
    if (!procuraTransicao(estadoAtual, transicao, lambda, desempilhar)) {
        // tenta com lambda e lambda
        return procuraTransicaoLambdaLambda(estadoAtual, transicao, proximoSimbolo, desempilhar);
    }
    proximoSimbolo = lambda;
    return true;
}

bool Apd::procuraTransicaoLambdaLambda(Estado estadoAtual, Transicao &transicao, Simbolo &proximoSimbolo, Simbolo &desempilhar) {
    Simbolo lambda = Simbolo(Simbolo::LAMBDA);
    if(!procuraTransicao(estadoAtual, transicao, lambda, lambda)) {
        return false;
    }
    proximoSimbolo = lambda;
    desempilhar = lambda;
    return true;

}

bool Apd::procuraTransicao(Estado estadoAtual, Transicao &transicao, Simbolo &simboloEntrada, Simbolo &desempilhar)
{
    transicao = Transicao(&estadoAtual, &simboloEntrada, &desempilhar);
    std::list<Transicao>::iterator findIter = std::find(this->transicoes.begin(), this->transicoes.end(), transicao);
    if(findIter == this->transicoes.end()){
//        cout << "nao encontrou transicao: " << estadoAtual.texto() << " " << simboloEntrada.texto() << " " << desempilhar.texto() << endl;
        return false;
    } else {
//        cout << "encontrou transicao: " << (*findIter).texto() << endl;
        transicao = (*findIter);
        return true;
    }
}

void Apd::executarTransicoes(Estado &estadoAtual, Simbolo &proximoSimbolo, Simbolo &desempilhar)
{
    // tenta com proximoSimbolo e topo
    Simbolo simboloNaoUtilizado(proximoSimbolo);
    Transicao *transicao = new Transicao(&estadoAtual, &proximoSimbolo, &desempilhar);
    if(!procuraTransicaoProxSimboloTopo(estadoAtual, *transicao, proximoSimbolo, desempilhar)){
        return;
    }
    cout << "[" << estadoAtual.texto() << ", " << palavra->texto() << ", " << pilha->texto() <<"] "<< transicao->texto() << endl;
    if(!proximoSimbolo.igual(Simbolo(Simbolo::LAMBDA))) {
        proximoSimbolo = palavra->prox();
    } else {
        proximoSimbolo = simboloNaoUtilizado;
    }

    if(!desempilhar.igual(Simbolo(Simbolo::LAMBDA))) {
        pilha->desempilha();
    }
    pilha->empilha(transicao->getSimbolosAEmpilhar());
    estadoAtual = *transicao->getEstadoSeguinte();

    desempilhar = pilha->topo();
    executarTransicoes(estadoAtual, proximoSimbolo, desempilhar);
}

void Apd::imprimir()
{
    cout << "Estados : ";
    for (std::list<Estado>::iterator it=this->estados.begin(); it != this->estados.end(); ++it){
        cout << (*it).texto() << " ";
    }

    cout << ";\nAlfabeto Fita : ";
    for (std::list<Simbolo>::iterator it=this->alfabetoFita.begin(); it != this->alfabetoFita.end(); ++it){
        cout << (*it).texto() << " ";
    }

    cout << "\nAlfabeto Pilha : ";
    for (std::list<Simbolo>::iterator it=this->alfabetoPilha.begin(); it != this->alfabetoPilha.end(); ++it){
        if(!Simbolo(Simbolo::LAMBDA).igual(*it)) {
            cout << (*it).texto() << " ";
        }
    }

    cout << "\nTransicoes : ";
    for (std::list<Transicao>::iterator it=this->transicoes.begin(); it != this->transicoes.end(); ++it){
        cout << (*it).texto() << " ";
    }

    cout << "\nEstado inicial : " << this->estadoInicial->texto();

    cout << "\nEstados finais : ";
    for (std::list<Estado*>::iterator it=this->estadosFinais.begin(); it != this->estadosFinais.end(); ++it){
        cout << (*it)->texto() << " ";
    }

    cout << endl;
}
