#ifndef ARQUIVOAPD_H
#define ARQUIVOAPD_H

#include "apd.h"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

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
        virtual EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) = 0;
    };

    class LerEstados : public EstadosLeitura {
        EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream estado;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(estado.str() != "") {
                        arquivoApd->estados.push_back(Estado(estado.str()));
                    }

                    estado.str("");
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
        EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream simbolo;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(simbolo.str() != "") {
                        arquivoApd->alfabetoFita.push_back(Simbolo(simbolo.str()));
                    }

                    simbolo.str("");
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
        EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream simbolo;
            for ( std::string::iterator it=linha.begin(); it!=linha.end(); ++it) {
                if( (*it) == ' ' || (*it) == ';') {
                    if(simbolo.str() != "") {
                        arquivoApd->alfabetoPilha.push_back(Simbolo(simbolo.str()));
                    }

                    simbolo.str("");
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
        EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
            std::stringstream estado;
            linha.erase(remove_if(linha.begin(), linha.end(), (int(*)(int))isspace), linha.end());
            // remove abertura de parenteses (
            linha.erase(0,1);
            // remove fechamento de parenteses (
            linha.erase(linha.length()-2,1);
            bool ultimaTransicao = (linha.at(linha.length()-1) == ';');
            if(ultimaTransicao) {
                // remove ponto e virgula final ;
                linha.erase(linha.length()-1,1);
            }

            char * c_linha = (char*)linha.c_str();
            char * pch = strtok (c_linha,",");

            Estado* estadoAtual = new Estado(pch);
            for (std::list<Estado>::iterator it=arquivoApd->estados.begin(); it != arquivoApd->estados.end(); ++it){
                if(estadoAtual->igual(*it)) {
                    estadoAtual = &(*it);
                    break;
                }
            }

            pch = strtok (NULL,",");
            Simbolo* simboloEntrada = new Simbolo(pch);
            for (std::list<Simbolo>::iterator it=arquivoApd->alfabetoFita.begin(); it != arquivoApd->alfabetoFita.end(); ++it){
                if(simboloEntrada->igual(*it)) {
                    simboloEntrada = &(*it);
                    break;
                }
            }

            pch = strtok (NULL,",");
            Simbolo* simboloADesempilhar = new Simbolo(pch);
            for (std::list<Simbolo>::iterator it=arquivoApd->alfabetoPilha.begin(); it != arquivoApd->alfabetoPilha.end(); ++it){
                if(simboloADesempilhar->igual(*it)) {
                    simboloADesempilhar = &(*it);
                    break;
                }
            }
            arquivoApd->alfabetoPilha.push_back(Simbolo(Simbolo::LAMBDA));

            pch = strtok (NULL,",");
            Estado* estadoSeguinte = new Estado(pch);
            for (std::list<Estado>::iterator it=arquivoApd->estados.begin(); it != arquivoApd->estados.end(); ++it){
                if(estadoSeguinte->igual(*it)) {
                    estadoSeguinte = &(*it);
                    break;
                }
            }

            pch = strtok (NULL,",");
            list<Simbolo*> simbolosAEmpilhar;
            string simbolosAEmpilharStr(pch);
            for ( std::string::iterator it=simbolosAEmpilharStr.begin(); it!=simbolosAEmpilharStr.end(); ++it) {
                Simbolo* simboloAEmpilhar = new Simbolo(*it);
                for (std::list<Simbolo>::iterator it=arquivoApd->alfabetoPilha.begin(); it != arquivoApd->alfabetoPilha.end(); ++it){
                    if(simboloAEmpilhar->igual(*it)) {
                        simboloAEmpilhar = &(*it);
                        simbolosAEmpilhar.push_back(simboloAEmpilhar);
                        break;
                    }
                }
            }

            Transicao transicao(estadoAtual, simboloEntrada, simboloADesempilhar, estadoSeguinte, simbolosAEmpilhar);
            arquivoApd->transicoes.push_back(transicao);

            if(ultimaTransicao) {
                return new LerEstadoInicial();
            } else {
                return new LerTransicoes();
            }
        }
    };

    class LerEstadoInicial : public EstadosLeitura {
        EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
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

                    estadoStr.str("");
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
        EstadosLeitura* ler(ArquivoApd *arquivoApd, string linha) {
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

                    estadoStr.str("");
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
