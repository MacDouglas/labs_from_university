#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cmath>  
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

namespace clients_objects {
	
	class client
	{
	public:
		int err;
		char buf[4];
		double param;

		client(int port);
		double get_param() const;
	};

}
#endif BASE_H