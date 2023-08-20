#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define MY_INET_ADDR  "192.168.1.42"

int main(int argc, char** argv)
{
  int client_sock;
  int error;
  //create the client socket
  client_sock = socket(PF_INET, SOCK_STREAM, 0);
  // Need the address of the server to connect to
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_addr.s_addr = inet_addr(MY_INET_ADDR);
  server_address.sin_family = PF_INET;
  server_address.sin_port = htons(2222);
  error = connect(client_sock, (struct sockaddr *)&server_address,
  sizeof(server_address));
  if (error == -1)
  {
  perror("Failed to connect.");
  return 1;
  }
  cout << "Here is the message from the server:\n ";
  char ch;
  while (read(client_sock, &ch, 1) > 0)
  {
    write(1, &ch, 1);
  }
  close(client_sock);
  return 0;
}
