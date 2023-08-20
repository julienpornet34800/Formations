#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

#define MY_IP_ADDR "192.168.1.42"

int main(int argc, char** argv)
{
  int client_sock;
  int server_sock;
  int error;
  if(argc != 2){
    std::cerr << "args issue, 1st arg == integer" << std::endl;
    return 1;
  }
  //create the client socket
  client_sock = socket(PF_INET, SOCK_STREAM, 0);
  // Need the address of the server to connect to
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_addr.s_addr = inet_addr(MY_IP_ADDR);
  server_address.sin_family = PF_INET;
  server_address.sin_port = htons(2222);
  error = server_sock = connect(client_sock, (struct sockaddr *)&server_address,
  sizeof(server_address));
  if (error == -1)
  {
    std::cerr << "Failed to connect.\n" << std::endl;
    return 1;
  }
  int value_sent = atoi(argv[1]);
  std::cout << "Here is the integer send to the server: " << value_sent << std::endl;
  write(server_sock, &value_sent, 1);
  return 0;
}
