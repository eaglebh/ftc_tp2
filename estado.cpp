#include "estado.h"
#include <iostream>

unsigned int Estado::chaveAtual = 1;

using namespace std;

Estado::Estado(string nome):
    nome(nome)
{
    this->chave = geraChaveDeEstado();
}

bool Estado::igual(const Estado outro)
{
    return (outro.nome == this->nome);
}

unsigned int Estado::geraChaveDeEstado() {
    return ++chaveAtual;
}

void Estado::reiniciaChaveDeEstado(){
    chaveAtual = 1;
}

string Estado::texto()
{
    return this->nome;
}

void Estado::imprimir()
{
    cout << "estado=" << texto() << endl;
}
