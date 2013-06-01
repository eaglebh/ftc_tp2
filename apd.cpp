#include "apd.h"

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
