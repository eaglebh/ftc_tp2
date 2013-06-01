#ifndef ESTADO_H
#define ESTADO_H

#include <string>

using namespace std;

class Estado {

private:
    string nome;
    unsigned int chave;

    static unsigned int chaveAtual;

    static unsigned int geraChaveDeEstado();

public:
    Estado(string nome);
    bool igual(const Estado outro);

    static void reiniciaChaveDeEstado();

    string texto();
    void imprimir();
};

#endif // ESTADO_H
