#include "estado.h"

unsigned int Estado::chaveAtual = 1;

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
