#include<iostream>
#include<string.h>	//strlen
#include<stdlib.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include<pthread.h>

using namespace std;
int main(int argc, char* argv[])
{
	int listenfd=0,connfd=0;
	struct sockaddr_in serv_addr;
	char sendbuff[1024];
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	memset(&serv_addr,0,sizeof(serv_addr));
	memset(sendbuff,0,sizeof(sendbuff));
	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(5000);
	
	bind(listenfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	cout<<"server bind successful"<<endl;
	
	if(listen(listenfd,10)==-1)
	    {
		cout<<"failed to listen"<<endl;
		return -1;
	    }
	cout<<"listening"<<endl;
	while(1)
	    {
		connfd=accept(listenfd,(struct sockaddr*)NULL,NULL);
		cout<<"accepted"<<endl;
		strcpy(sendbuff,"Hi there");
		write(connfd,sendbuff,strlen(sendbuff));
		close(connfd);
		sleep(1);
	    }
	return 0;
}


