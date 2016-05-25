#include "ofMain.h"
#include "ofApp.h"
#ifdef _WIN32
	#include <WinSock2.h>
#endif
//========================================================================

#define PORT 11111
#define DUMMY_PORT 12111
#define PORT_SERVER 20001

#ifdef _WIN32

BOOL CheckPortUDP(short int dwPort, char *ipAddressStr)
{
	struct sockaddr_in client;
	int sock;

	client.sin_family = AF_INET;
	client.sin_port = htons(dwPort);
	client.sin_addr.s_addr = inet_addr(ipAddressStr);

	sock = (int)socket(AF_INET, SOCK_DGRAM, 0);

	int result = ::bind(sock, (SOCKADDR FAR *) &client, sizeof(SOCKADDR_IN));
	return result == SOCKET_ERROR;
}
#endif

int main( ){
	ofSetupOpenGL(20,20,OF_WINDOW);			// <-------- setup the GL context

	ofApp* app = new ofApp();
#ifdef _WIN32
	WSADATA wsaData;

	if (WSAStartup(0x0101, &wsaData) == 0)
	{
		int availablePort = PORT;
		int dummyPort = DUMMY_PORT;
		while (CheckPortUDP(dummyPort, "127.0.0.1")) {
			availablePort++;
			dummyPort++;
			printf("Checking next available port %d...\r\n", availablePort);
		}

		printf("Opened OSC on port %d\r\n", availablePort);
		app->oscPort = availablePort;
	}

#else
	app->oscPort = PORT;
#endif

	FreeConsole();
	ofRunApp(app);

#ifdef _WIN32
	WSACleanup();
#endif
}
