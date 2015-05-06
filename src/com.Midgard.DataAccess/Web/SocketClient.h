/*
 * SocketClient.h
 *
 *  Created on: May 1, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_DATAACCESS_WEB_SOCKETCLIENT_H_
#define SRC_COM_MIDGARD_DATAACCESS_WEB_SOCKETCLIENT_H_
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

class SocketClient{
public:
	SocketClient();
    bool connect(const char* targetIP,int targetPORT);
    void sendMessage(const char *msn);
private:
    int descriptor;
    sockaddr_in info;
    static void * controlador(void *obj);
};


#endif /* SRC_COM_MIDGARD_DATAACCESS_WEB_SOCKETCLIENT_H_ */
