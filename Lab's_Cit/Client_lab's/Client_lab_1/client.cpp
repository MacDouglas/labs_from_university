#include "client.h"

using namespace std;

namespace clients_objects {
	client::client(int port)
	{
		WSADATA WsaData;
		err = WSAStartup(0x0101, &WsaData);
		if (err == SOCKET_ERROR) {
			printf("WSAStartup() failed: %ld\n", GetLastError());
			throw "Error with a creation socked";
		}
		int s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		struct sockaddr_in sin;

		sin.sin_family = AF_INET;
		sin.sin_port = htons(port);
		inet_pton(AF_INET, "192.168.1.14", &(sin.sin_addr.S_un.S_addr));

		err = connect(s, (const struct sockaddr*) & sin, sizeof(sin));

		int sz = recv(s, buf, sizeof(buf), 0);

		//cout << "Buf = " << buf << endl;
		string str = (char*)buf;
		param = stod(str);

		closesocket(s);
	}

	double client::get_param() const
	{
		return param;
	}

	
}
