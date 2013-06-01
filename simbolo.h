#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <string>

using namespace std;

class Simbolo
{
public:
    static const char LAMBDA = '_';
    static const char DELTA = 3; // ETX - end of text

    Simbolo(string nome);
    Simbolo(char nome);
    bool igual(const Simbolo outro);
    string texto();
    void imprimir();

private:
    string nome;


};

#endif // SIMBOLO_H
