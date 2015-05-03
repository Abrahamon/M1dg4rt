/*
 * SocketServer.h
 *
 *  Created on: May 1, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_DATAACCESS_WEB_SOCKETSERVER_H_
#define SRC_COM_MIDGARD_DATAACCESS_WEB_SOCKETSERVER_H_
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

using namespace std;

struct dataSocket{
    int descriptor;
    sockaddr_in info;
};

class SocketServer
{
public:
    SocketServer();
    void run(int pPort);
    void sendMessage(const char *msn);
private:
    int descriptor;
    sockaddr_in info;
    bool createSocket(int pPort);
    bool setKernel();
    static void * clienteManager(void *obj);
    vector<int> clientes;
};

//#################### METODOS #########################

SocketServer::SocketServer(){}


bool SocketServer::createSocket(int pPort)
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(pPort);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}

bool SocketServer::setKernel()
{
    if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
        return false;

    listen(descriptor,5);
    return true;
}


void SocketServer::run(int pPort)
{
    if(!createSocket(pPort))
        throw string("Error al crear el socket");
    if(!setKernel())
        throw string("Error al  ligar kernel");

    while (true) {
        cout << "Esperando nuevo cliente"<<endl;
        dataSocket data;
        socklen_t tam = sizeof(data.info);
        data.descriptor = accept(descriptor,(sockaddr*)&data.info,&tam);
        if(data.descriptor < 0)
            cout << "Error al acceptar al cliente"<<endl;
        else
        {
            clientes.push_back(data.descriptor);
            pthread_t hilo;
            pthread_create(&hilo,0,SocketServer::clienteManager,(void *)&data);
            pthread_detach(hilo);
        }
    }
    close(descriptor);
}



void * SocketServer::clienteManager(void *obj)
{
    dataSocket *data = (dataSocket*)obj;
    while (true) {
        string mensaje;
        while (1) {
            char buffer[10] = {0};
            int bytes = recv(data->descriptor,buffer,10,0);
            mensaje.append(buffer,bytes);
            if(bytes < 10)
                break;
        }
        cout << mensaje << endl;
    }

    close(data->descriptor);
    pthread_exit(NULL);
}


void SocketServer::sendMessage(const char *msn)
{
    for(unsigned int i = 0 ; i < clientes.size() ; i++)
        cout << "bytes enviados "<< send(clientes[i],msn,strlen(msn),0);
}



#endif /* SRC_COM_MIDGARD_DATAACCESS_WEB_SOCKETSERVER_H_ */
