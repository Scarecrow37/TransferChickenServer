#pragma once
#include <WinSock2.h>
#include <xstring>

class TcpSocket
{
public:
    TcpSocket(SOCKET Socket);

    static std::exception MakeException(const std::string& Message);

    void Send(const char* Data, int Size) const;

    void SendString(const std::string& Message) const;
    std::string ReceiveString() const;

    void SendFile(FILE* File) const;
    FILE* ReceiveFile() const;

private:
    SOCKET Socket;
};
