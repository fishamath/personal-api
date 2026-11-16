#include "include/server.h"
//#include "include/storage.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(void) {
	server();

	return 0;
}

void server(void) {
	int server_fd = server_setup();
	if (server_fd == -1) {
		return;
	}

	close(server_fd);
}

int server_setup(void) {
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	int addr_len = sizeof(addr);

	if (bind(server_fd, (struct sockaddr *) &addr, addr_len)) {
		perror("bind");
		close(server_fd);
		return -1;
	}

	if (listen(server_fd, 5) == -1) {
		perror("listen");
		close(server_fd);
		return -1;
	}

	return server_fd;
}