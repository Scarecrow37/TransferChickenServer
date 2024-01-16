#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")


int main()
{
    FILE* ChickenImage = {};
    const errno_t _ = fopen_s(&ChickenImage, "./Resource/chicken.jpg", "rb");
    char Buffer[100000] = {};
    size_t FileSize = fread_s(Buffer, sizeof(Buffer), sizeof(char), sizeof(Buffer), ChickenImage);
    fclose(ChickenImage);
    
    WSADATA WsaData;
    WSAStartup(MAKEWORD(2, 2), &WsaData);

    SOCKET ListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKADDR_IN ServerAddress = {};
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.s_addr = ADDR_ANY;
    ServerAddress.sin_port = htons(8080);

    bind(ListenSocket, reinterpret_cast<SOCKADDR*>(&ServerAddress), sizeof(ServerAddress));
    listen(ListenSocket, 1);

    SOCKADDR_IN ClientAddress = {};
    int ClientAddressLength = sizeof(ClientAddress);
    SOCKET ClientSocket = accept(ListenSocket, reinterpret_cast<SOCKADDR*>(&ClientAddress), &ClientAddressLength);

    send(ClientSocket, Buffer, static_cast<int>(FileSize), 0);
    
    return 0;
}
