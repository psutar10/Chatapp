#include"client.h"

client::client():sockfd(0),readInt(0)
{
    memset(recvBuff,0,sizeof(recvBuff));
}

void client::createSocket(char* Ipaddr)
{
    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      cout<<"Error : Could not create socket"<<endl;
      exit(0);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = inet_addr(Ipaddr);
}

void client::connectToServer()
{
    
  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      cout<<"Error : Connect Failed "<<endl;
      exit(0);
    }
}
void client::readMessage()
{
    while((readInt = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
      recvBuff[readInt] = 0;
      if(fputs(recvBuff, stdout) == EOF)
    {
      cout<<"Error : Fputs error"<<endl;
    }
      cout<<endl;
    }
 
  if( readInt < 0)
    {
     	cout<<"Read Error "<<endl;
    }
}

int main(int argc,char* argv[])
{
    client clientObj;
    clientObj.createSocket(argv[1]);
    clientObj.connectToServer();
    clientObj.readMessage();
    return 0;
}
