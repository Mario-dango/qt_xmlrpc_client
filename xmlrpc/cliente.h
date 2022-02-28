#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "XmlRpc.h"
using namespace XmlRpc;

class cliente_xmlrpc
{
public:
    cliente_xmlrpc(char*, int);
    bool estado = false;
    bool conectar ();
    bool movimiento(char*, XmlRpcClient);
    XmlRpc::XmlRpcValue vacio, tecla, resultado;
    void ejecutar(string, XmlRpcValue, XmlRpcValue);
    ~cliente_xmlrpc();
private:
//    ~cliente_xmlrpc;
    char* _ip_host;
    int _puerto;
};

#endif // CLIENTE_H

/*Los Codigos mas importantes
+-----------------------+
| Cod ASCII | Tecla |
+-----------------------+
| 9 | TAB |
| 13 | Enter |
| 27 | ESC |
| 32 | Espacio |
+-----------------------+
| 72 | (Arriba) |
| 80 | (Abajo) |
| 75 | (Izqrda) |
| 77 | (Dercha) |
+-----------------------+ */
