#include"server.h"

server::server():listenfd(0),connfd(0)
{
   memset(&serv_addr,0,sizeof(serv_addr));
   memset(sendbuff,0,sizeof(sendbuff)); 
}

void server::createSocket()
{
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(5000);
}

void server::bindToServer()
{
    bind(listenfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    cout<<"server bind successful"<<endl;
}

void server::serverListen()
{
    if(listen(listenfd,10)==-1)
	    {
		cout<<"failed to listen"<<endl;
                exit(0);
	    }
	cout<<"listening"<<endl;

        connfd=accept(listenfd,(struct sockaddr*)NULL,NULL);
        cout<<"accepted"<<endl;
}

void server::sendMessage(char *message)
{
    strcpy(sendbuff,message);
    write(connfd,sendbuff,strlen(sendbuff));
}

int main(int argc,char *argv[])
{
    server serverObj;
    serverObj.createSocket();
    serverObj.bindToServer();
    serverObj.serverListen();
    char message[1024]="Hi There";
    serverObj.sendMessage(message);
    return 0;
}
