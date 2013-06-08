#include "arquivoapd.h"
#include <iostream>
#include <fstream>

ArquivoApd::ArquivoApd(string nomeArquivo)
{
    string linha = "";
    ifstream arquivoApd(nomeArquivo.c_str(), std::ifstream::in);
    EstadosLeitura* estadosLeitura = new LerEstados();
    while(arquivoApd.good()) {
        while(linha == "") {
            if(!getline(arquivoApd, linha)) {
                return;
            }
        }
        std::cout << "linha = " << linha << std::endl;
        EstadosLeitura* pEstadosLeitura = estadosLeitura;
        estadosLeitura = estadosLeitura->ler(this, linha);
        delete pEstadosLeitura;
        linha = "";
    }
}

Apd ArquivoApd::getApd()
{
    Apd apd;

    apd.setEstados(this->estados);
    apd.setAlfabetoFita(this->alfabetoFita);
    apd.setAlfabetoPilha(this->alfabetoPilha);
    apd.setTransicoes(this->transicoes);
    apd.setEstadoInicial(this->estadoInicial);
    apd.setEstadosFinais(this->estadosFinais);

    return apd;
}
