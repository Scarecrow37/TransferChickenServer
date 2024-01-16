#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

#include "Network/TCPServer.h"

int main()
{
    TcpServer* Server = new TcpServer();
    Server->Initialize();
    Server->Bind(8080);
    Server->Listen();
    const TcpSocket* Socket = Server->Accept();


    FILE* Image = fopen("/Resource/chicken.jpg", "rb");
    char Buffer[100000] = {};
    int BufferSize = sizeof(Buffer);
    int ReadSize = fread(Buffer, sizeof(char), BufferSize, Image);
    Socket->Send(Buffer, ReadSize);
    std::cout << ReadSize;
    fclose(Image);
    return 0;
}
