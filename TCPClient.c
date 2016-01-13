#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void DieWithError(char *errorMessage);

int main(int argc, char *argv[])
{
  int sock; /* Socket descriptor */
  struct sockaddr_in ServAddr; /* Echo server address */
  unsigned short ServPort;
  char *servlP;
  char *mode;
  char Buffer[1024];
  unsigned int stringLen;
  int bytesRcvd, totalBytesRcvd;

  if(argc<3 || argc>4)
  {
    fprintf(stderr, "error", argv[0]);
    exit(1);
  }
  mode=argv[1];
  servlP=argv[2];
  if(argc==4) ServPort=atoi(argv[3]);
  //create socket
  if((sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))<0)
    DieWithError("socket() failed");

  //construct server address structure
  memset(&ServAddr, 0, sizeof(ServAddr));
  ServAddr.sin_family=AF_INET;
  ServAddr.sin_addr.s_addr=inet_addr(servlP);
  ServAddr.sin_port=htons(ServPort);

  //establish the connection to the server
  if(connect(sock, (struct sockaddr *) &ServAddr, sizeof(ServAddr))<0)
    DieWithError("connect() failed");

  stringLen=strlen(mode);

  //send
  if(send(sock, mode, stringLen, 0)!=stringLen)
    DieWithError("send() failed");

  //RCV
  totalBytesRcvd=0;
  printf("Received: ");
  while((n=recv(sock, Buffer, RCVBUFSIZE-1, 0))>0)
  {
    printf(Buffer);
  }
  printf("\n");
}
