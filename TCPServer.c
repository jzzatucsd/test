#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAXPENDING 5

void DieWithError(char *errorMessage);
void HandleTCPClient(int clntSocket);

int main(int argc, char *argv[])
{
  int servSock;
  int clntSock;
  struct sockaddr_in ServAddr;
  struct sockaddr_in ClntAddr;
  unsigned short ServPort;
  unsigned int clntLen;
  char Buffer[1024];
  int msgsize;

  if(argc!=2)
  {
    fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
    exit(1);
  }

  ServPort=atoi(argv[1]);

  //create socket
  if((servSock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))<0)
    DieWithError("socket() failed");

  //construct local address structure
  memset(&ServAddr, 0, sizeof(ServAddr));
  ServAddr.sin_family=AF_INET;
  ServAddr.sin_addr.s_addr=htonl(INADDR_ANY);
  ServAddr.sin_port=htons(ServPort);

  //bind to the local address
  if(bind(servSock, (struct sockaddr *) &ServAddr, sizeof(ServAddr))<0)
    DieWithError("bind() failed");

  if(listen(servSock, MAXPENDING)<0)
    DieWithError("listen() failed");

  for(;;)
  {
    clntLen=sizeof(ClntAddr);
    if((clntSock=accept(servSock, (struct sockaddr*) &ClntAddr, &clntLen))<0);
      DieWithError("accept() failed");
    int n=0;
    char
    while(n!=4)
    {
      if((msgsize=recv(clntSocket, Buffer+n, 1024, 0))<0)
      DieWithError("recv() failed");
      n+=msgsize;
    }

    //get time
    time_t rawtime;
    rawtime=time(NULL);
    //send time or date
    
    if(Buffer=='date')
  }
}
