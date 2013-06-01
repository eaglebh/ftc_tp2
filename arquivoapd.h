#ifndef ARQUIVOAPD_H
#define ARQUIVOAPD_H

#include "apd.h"
#include <sstream>
#include <iostream>

class ArquivoApd
{
private:
    list<Estado> estados;
    list<Simbolo> alfabetoFita;
    list<Simbolo> alfabetoPilha;
    list<Transicao> transicoes;
    Estado* estadoInicial;
    list<Estado*> estadosFinais;

    class EstadosLeitura
    {
    public:
        static EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha){
            std::cout << "padrao " << std::endl;
        }
    };

    class LerEstados : public EstadosLeitura {
        static EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream estado;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(estado.str() != "") {
                        std::cout << "estado = " << estado;
                        arquivoApd->estados.push_back(Estado(estado.str()));
                    }

                    estado.clear();
                    if( (*it) == ';') {
                        break;
                    }
                    continue;
                }

                estado << *it;
            }
            return new LerAlfabetoFita();
        }
    };

    class LerAlfabetoFita : public EstadosLeitura {
        static EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream simbolo;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(simbolo.str() != "") {
                        arquivoApd->alfabetoFita.push_back(Simbolo(simbolo.str()));
                    }

                    simbolo.clear();
                    if( (*it) == ';') {
                        break;
                    }
                    continue;
                }

                simbolo << *it;
            }
            return new LerAlfabetoPilha();
        }
    };

    class LerAlfabetoPilha : public EstadosLeitura {
        static EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream simbolo;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(simbolo.str() != "") {
                        arquivoApd->alfabetoPilha.push_back(Simbolo(simbolo.str()));
                    }

                    simbolo.clear();
                    if( (*it) == ';') {
                        break;
                    }
                    continue;
                }

                simbolo << *it;
            }
            return new LerTransicoes();
        }
    };

    class LerTransicoes : public EstadosLeitura {
        static EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream estado;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(estado.str() != "") {
                        arquivoApd->estados.push_back(Estado(estado.str()));
                    }

                    estado.clear();
                    if( (*it) == ';') {
                        break;
                    }
                    continue;
                }

                estado << *it;
            }
            return new LerEstadoInicial();
        }
    };

    class LerEstadoInicial : public EstadosLeitura {
        static EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream estadoStr;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(estadoStr.str() != "") {
                        Estado* estadoAtual = new Estado(estadoStr.str());
                        for (std::list<Estado>::iterator it=arquivoApd->estados.begin(); it != arquivoApd->estados.end(); ++it){
                            if(estadoAtual->igual(*it)) {
                                estadoAtual = &(*it);
                                arquivoApd->estadoInicial = estadoAtual;
                                break;
                            }
                        }

                    }

                    estadoStr.clear();
                    if( (*it) == ';') {
                        break;
                    }
                    continue;
                }

                estadoStr << *it;
            }
            return new LerEstadosFinais();
        }
    };

    class LerEstadosFinais : public EstadosLeitura {
        static EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream estadoStr;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(estadoStr.str() != "") {
                        Estado* estadoAtual = new Estado(estadoStr.str());
                        for (std::list<Estado>::iterator it=arquivoApd->estados.begin(); it != arquivoApd->estados.end(); ++it){
                            if(estadoAtual->igual(*it)) {
                                estadoAtual = &(*it);
                                arquivoApd->estadosFinais.push_back(estadoAtual);
                                break;
                            }
                        }
                    }

                    estadoStr.clear();
                    if( (*it) == ';') {
                        break;
                    }
                    continue;
                }

                estadoStr << *it;
            }
            return NULL;
        }
    };


public:
    ArquivoApd(string nomeArquivo);

    Apd getApd();
};

#endif // ARQUIVOAPD_H
