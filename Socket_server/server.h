#include<iostream>
#include<string.h>	//strlen
#include<stdlib.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include<pthread.h>

using namespace std;

class server
{
    public:
	server();
	~server(){close(connfd);}
	void createSocket();
	void bindToServer();
	void serverListen();
	void serverAccept();
	void sendMessage();

    private:
	int listenfd,connfd;
	char sendbuff[1024],choice,message[1024];	;
	struct sockaddr_in serv_addr; 
         
};
