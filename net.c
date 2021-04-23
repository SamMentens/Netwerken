#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
int main()
{
	WSADATA wsaData;
	WSAStartup( MAKEWORD(2,0), &wsaData);
	
	printf("hey");
	// stuurt naar 84.194.77.34
	int internet_socket = 0;
	internet_socket = socket( AF_INET, SOCK_DGRAM, 0 );
	
	struct sockaddr address;
	address.sa_family = AF_INET; 
	address.sa_data[0] = 0x5D;
	address.sa_data[1] = 0xD4;
	address.sa_data[2] = 84;
	address.sa_data[3] = 194;
	address.sa_data[4] = 77;
	address.sa_data[5] = 34;
	address.sa_data[6] = 0;
	address.sa_data[7] = 0;
	address.sa_data[8] = 0;
	address.sa_data[9] = 0;
	
	sendto( socket, "Hallo", 14, 0, &address, sizeof (address));
	
	
	close( internet_socket );
	
	return 0;
}