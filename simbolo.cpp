#include "simbolo.h"

Simbolo::Simbolo(string nome):
    nome(nome)
{
}

bool Simbolo::igual(const Simbolo outro)
{
    return (outro.nome == this->nome);
}
