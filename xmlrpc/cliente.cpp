/* cliente_basico.cpp : ejemplo sencillo de cliente XMLRPC.
   Se usa la libreria XmlRpc++
   disponible en http://sourceforge.net/projects/xmlrpcpp/
   y documentacion general en http://xmlrpcpp.sourceforge.net/
*/
// ejemplo de compilación que funciona
//g++ -Wall cliente_basico.cpp XmlRpcClient.cpp XmlRpcUtil.cpp XmlRpcValue.cpp XmlRpcSocket.cpp XmlRpcSource.cpp XmlRpcDispatch.cpp -o cliente
//funciona para compilar~~~~~~~

#include "cliente.h"

cliente_xmlrpc::cliente_xmlrpc(char* ip, int puerto)
{
  //Se indica el servidor deseado
  _ip_host = ip;
  _puerto = puerto;
}

bool cliente_xmlrpc::conectar()
{
try{
    XmlRpc::XmlRpcClient client(_ip_host, _puerto);
    //XmlRpc::setVerbosity(5);

    XmlRpc::XmlRpcValue vacio, tecla, resultado;
    return true;
}catch(XmlRpc::XmlRpcException e){
    cout << "Error numero " << e.getCode() << ", " << e.getMessage() << endl;
    return false;
}
}

void ejecutar(string metodo, string mensaje){
    XmlRpcValue respuesta;
    XmlRpcClient::XmlRpcClient execute(metodo, mensaje, respuesta);
}

bool movimiento(string opcion, XmlRpcClient client)
{
    string comando = opcion;
    int tecla;
    XmlRpcClient cliente = client;
    XmlRpc::XmlRpcValue vacio, resultado;
    system ("/bin/stty raw");
    std::cout << "Por favor ingresar valores númericos correspondinte a los movimientos" << endl;
    while ((tecla=getchar()) != 27)
    {
    printf("Se ha presionado: %c\n", tecla);
    if ((tecla == 72)||(comando == "avanzar")){
      if (cliente.execute("avanzar", vacio, resultado)){
        std::cout << resultado << "\n";
        return true;
      }else{
        std::cout << "Error en la llamada avanzar!" << "\n";
        return false;
      }
    }else if ((tecla == 80)||(comando == "retroceder")){
      if (cliente.execute("retroceder", vacio, resultado)){
        std::cout << resultado << "\n";
        return true;
      }else{
        std::cout << "Error en la llamada Retroceder!" << "\n";
        return false;
      }
    }else if ((tecla == 75)||(comando == "izquierda")){
      if (cliente.execute("izquierda", vacio, resultado)){
        std::cout << resultado << "\n";
        return true;
      }else{
        std::cout << "Error en la llamada Izquierda!" << "\n";
        return false;
      }
    }else if ((tecla == 77)||(comando == "derecha")){
      if (cliente.execute("derecha", vacio, resultado)){
        std::cout << resultado << "\n";
        return true;
      }else{
        std::cout << "Error en la llamada Derecha!" << "\n";
        return false;
      }
    }else if ((tecla == 32)||(comando == "detener")){
      if (cliente.execute("detenerse", vacio, resultado)){
        std::cout << resultado << "\n";
        return true;
      }else{
        std::cout << "Error en la llamada Detener!" << "\n";
        return false;
      }
    }else if ((tecla == 9)||(comando == "off_cliente")){
      std::cout << "se procede a salir de la conexión." << "\n\n";
      break;
    }
    }
    system ("/bin/stty cooked");
    return true;

}
