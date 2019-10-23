#include <iostream>
#include <cmath> 
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

int main()
{
	double num1,num2;
	cout << "Enter the fiest number" << endl;
	cin >> num1;
	cout << "Enter the second number" << endl;
	cin >> num2;
	if ((num1 == 0 || num1 < 0)||(num2 == 0 || num2 < 0)) {
		throw "Number must be > 0";
	}

	WSADATA WsaData;
	int err = WSAStartup(0x0101, &WsaData);
	if (err == SOCKET_ERROR) {
		printf("WSAStartup() failed: %ld\n", GetLastError());
		return 1;
	}
	int s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in sn;

	sn.sin_family = AF_INET;
	sn.sin_port = htons(1280);
	inet_pton(AF_INET, "192.168.1.14", &(sn.sin_addr.S_un.S_addr));

	err = bind(s, (LPSOCKADDR)& sn, sizeof(sn));
	err = listen(s, SOMAXCONN);

	int s1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN from;
	int fromlen = sizeof(from);
	s1 = accept(s, (struct sockaddr*) & from, &fromlen);

	double ans = num1 / num2;
	std::string str = to_string(ans);
	const char* buf = str.c_str();

	int sz = send(s1, buf, sizeof(buf), 0);

	closesocket(s);
	closesocket(s1);

	return 0;
}
