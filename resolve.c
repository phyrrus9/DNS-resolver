#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
#include <signal.h>
#include <time.h>
#include <time.h>

#define OFFSET MOFFSET

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
	printf("Missing args\n");
	return -1;
    }
    else
    {
	for (int i = 1; i < argc; i++)
	{
		struct hostent *hp;
		hp = gethostbyname2(argv[i], AF_INET);
		if (hp == NULL)
		{
			printf("%s: Can not resolve\n", argv[i]);
		}
		else
		{
			printf("%s: %s\n", argv[i], inet_ntoa(*((struct in_addr *)hp->h_addr)));
		}
	}
    }

    return 0;
}
