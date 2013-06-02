#include "apd.h"
#include "palavra.h"
#include <iostream>

Apd::Apd()
{
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

bool Apd::executar(string palavraEntrada)
{
    palavra = new Palavra(palavraEntrada);
    Estado *estadoAtual = this->estadoInicial;
    Simbolo *proximoSimbolo = &(palavra->prox());
    Simbolo *desempilhar = &(pilha->topo());

    executarTransicoes(estadoAtual, proximoSimbolo, desempilhar);

    if(proximoSimbolo->igual(Simbolo(Simbolo::DELTA)) && pilha->topo().igual(Simbolo(Simbolo::DELTA)) ) {
        for (std::list<Estado*>::iterator it=this->estadosFinais.begin(); it != this->estadosFinais.end(); ++it){
            if(estadoAtual->igual(**it)) {
                return true;
            }
        }
    }

    return false;
}

void Apd::executarTransicoes(Estado *estadoAtual, Simbolo *proximoSimbolo, Simbolo *desempilhar)
{
    // tenta com proximoSimbolo e topo
    Transicao *transicao = new Transicao(estadoAtual, proximoSimbolo, desempilhar);
    // tenta com proximoSimbolo e lambda
    transicao = new Transicao(estadoAtual, proximoSimbolo, new Simbolo(Simbolo::LAMBDA));
    // tenta com lambda e topo
    transicao = new Transicao(estadoAtual, new Simbolo(Simbolo::LAMBDA), desempilhar);
    // tenta com lambda e lambda
    transicao = new Transicao(estadoAtual, new Simbolo(Simbolo::LAMBDA), new Simbolo(Simbolo::LAMBDA));

    if(!proximoSimbolo->igual(Simbolo(Simbolo::LAMBDA))) {
        proximoSimbolo = &(palavra->prox());
    }

    if(!desempilhar->igual(Simbolo(Simbolo::LAMBDA))) {
        pilha->desempilha();
        desempilhar = &(pilha->topo());
    }
    pilha->empilha(transicao->getSimbolosAEmpilhar());
    estadoAtual = transicao->getEstadoSeguinte();

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
        cout << (*it).texto() << " ";
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
