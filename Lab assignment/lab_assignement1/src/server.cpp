#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdint.h>

int main(int argc, char** argv)
{
  int server_sock;
  int client_sock;
  int error;
  //create the server socket
  server_sock = socket(PF_INET, SOCK_STREAM, 0);
  // Need an address to bind the serversocket to
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_family = PF_INET;
  server_address.sin_port = htons(2222);
  // bind the server socket to a local address
  error = bind(server_sock,
  (struct sockaddr *)&server_address,
  sizeof(server_address));
  if (error == -1)
  {
    std::cerr << "bind failed." << std::endl;
    return 1;
  }
  // listen for a connection
  error = listen(server_sock, 10);
  if (error == -1)
  {
    std::cerr << "listen failed.";
    return 3;
  }
  std::cout<< "Now listening for connections...\n";
  // accept a connection
  struct sockaddr_in client_address;
  socklen_t client_addr_len;
  error = client_sock = accept(server_sock,
  (struct sockaddr *) &client_address,
  &client_addr_len);
  if (error == -1)
  {
    std::cerr << "accept failed." << std::endl;
    return 0;
  }
  std::cout<< "Connection request received.\n";
  
  //Wait for an integer
  std::cout << "Wait for an integer... " << std::endl;
  int value_received;
  while (read(server_sock, &value_received, 1) > 0)
  {
    write(1, &value_received, 1);
  }
  
  std::cout << "Integer received :" << value_received << std::endl;
  int value_sent = value_received*value_received;
  std::cout << "Integer sent:" << value_sent << std::endl;
  write(client_sock, &value_sent, 4);
  close(client_sock);
  close(server_sock);
  return 0;
}
