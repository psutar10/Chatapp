#include<iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
using namespace std;

class client
{
    public:
	client();
	void createSocket(char *);
	void connectToServer();
	void readMessage();
    private:
	int sockfd,readInt;
	char recvBuff[1024];
	struct sockaddr_in serv_addr;
};
