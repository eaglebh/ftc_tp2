#include "apd.h"
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
