// Server_lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

int main()
{
	WSADATA WsaData;
	int err = WSAStartup(0x0101, &WsaData);
	if(err == SOCKET_ERROR) {
		printf("WSAStartup() failed: %ld\n", GetLastError());
		return 1;
	}
	int s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in sin;

	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	inet_pton(AF_INET, "192.168.1.14", &(sin.sin_addr.S_un.S_addr));

	err = bind(s, (LPSOCKADDR)& sin, sizeof(sin));
	err = listen(s, SOMAXCONN);

	int s1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN from;
	int fromlen = sizeof(from);
	s1 = accept(s, (struct sockaddr*) & from, &fromlen);

	char buf[] = "Hello world";
	int sz = send(s1, buf, sizeof(buf), 0);

	closesocket(s);
	closesocket(s1);

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
