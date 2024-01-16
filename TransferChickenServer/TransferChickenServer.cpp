#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

#include "Network/TCPServer.h"
#include "Utility/Exception/Exception.h"
#include "Utility/FileSystem/FileSystem.h"

int main()
{
    FileSystem* FSystem = new FileSystem();
    if (FSystem->Open("./Resource/chicken.jpg", "rb"))
    {
        throw Exception::MakeException("File open fail.");
    }
    char Buffer[100000] = {};
    if (FSystem->ReadFile(Buffer) == 0)
    {
        throw Exception::MakeException("File read fail.");
    }
    
    std::cout << (Result ? "True" : "False");
    /*
    TcpServer* Server = new TcpServer();
    Server->Initialize();
    Server->Bind(8080);
    Server->Listen();
    const TcpSocket* Socket = Server->Accept();


    FILE* Image = fopen("C:/Work/Resource/chicken.jpg", "rb");
    char Buffer[100000] = {};
    int BufferSize = sizeof(Buffer);
    int ReadSize = fread(Buffer, sizeof(char), BufferSize, Image);
    Socket->Send(Buffer, ReadSize);
    std::cout << ReadSize;
    fclose(Image);
    */
    return 0; 
}
