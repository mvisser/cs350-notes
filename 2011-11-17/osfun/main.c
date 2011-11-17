#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MSGLENGTH 100
/* port number: 1976 */
#define PORT_NUMBER 1976

int main(int argc, char ** argv)
{
	int s;
	struct sockaddr_in sis;
	int sislen = sizeof(sis);
	char buf[MSGLENGTH] = "test message";
	char strIP[20] = "35.9.20.14";

	memset((char *) &sis, 0, sizeof(sis));


	// adritic.cse.smu.edu

	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(s==-1){
		abort();
	}

	/* set up SIS */
	sis.sin_family = AF_INET;
	sis.sin_port = htons(PORT_NUMBER);
	inet_aton(strIP, &sis.sin_addr);

	/* send message */
	sendto(s,buf,strlen(buf), 0, (struct sockaddr *) &sis, sislen);

	close(s);
	return 0;
}
