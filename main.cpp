#include <iostream>
#include <fstream>
#include "arquivoapd.h"

using namespace std;

/**
 * @brief main
 * @return
 *
 *Entrada: (1) o APD, dado por i, F e D, e
(2) a palavra de entrada, dada por prox .
Saída: sim ou não .
e   i; empilhe (5); ps   prox ();
enquanto D[e; a; b] é definido p/ a 2 fps; g e b 2 ftopo (); g faça
seja D[e; a; b] = [e
0
; z ];
se a 6 =  então ps   prox () fimentão;
se b 6 =  então desempilhe () fimentão;
empilhe (z );
e   e
0
fimenquanto;
se ps = fs e topo () = 5 e e 2 F então
retorne sim
senão
retorne não
fimse
 */

int main(int argc, char* argv[])
{
    string palavraEntrada = "";
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " arquivoComAPD palavraEntrada" << endl;
        return -1;
    } else {
        ifstream arqEntrada(argv[1]);
        if (!arqEntrada.good())
        {
            cerr << "Arquivo de entrada inválido!" << endl;
            return -1;
        }
        if(argc > 2) {
            palavraEntrada = string(argv[2]);
            if(palavraEntrada == "_") {
                palavraEntrada = "";
            }
        }
        //cout << "arquivoApd: " << argv[1] << "\npalavra: " << palavraEntrada << endl;
    }

    ArquivoApd arquivoApd(argv[1]);
    //arquivoApd.getApd().imprimir();

    if(arquivoApd.getApd().executar(palavraEntrada)) {
        cout << "sim" << endl;
    } else {
        cout << "nao" << endl;
    }

    return 0;
}

