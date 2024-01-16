#include "TCPSocket.h"

#include <iostream>
#include <string>


TcpSocket::TcpSocket(const SOCKET Socket) : Socket(Socket)
{
}

void TcpSocket::SendString(const std::string& Message) const
{
    const int Byte = send(Socket, Message.c_str(), static_cast<int>(Message.size()), 0);
    if (Byte < 0)
    {
        throw MakeException("Send fail.");
    }
    if (Byte == 0)
    {
        throw MakeException("Disconnected.");
    }
}

std::string TcpSocket::ReceiveString() const
{
    char Buffer[1024] = {};
    const int Byte = recv(Socket, Buffer, sizeof(Buffer), 0);
    std::string ReceiveMessage(Buffer);
    return ReceiveMessage;
}

void TcpSocket::SendFile(FILE* File) const
{
    char Buffer[20000] = {};
    const int ReadSize = fread(Buffer, sizeof(char), sizeof(Buffer), File);
    if (ReadSize < sizeof(Buffer))
    {
        if (feof(File) != 0)
        {
            const int Byte = send(Socket, Buffer, (sizeof(Buffer)), 0);
            if (Byte < 0)
            {
                throw MakeException("Send fail.");
            }
            if (Byte == 0)
            {
                throw MakeException("Disconnected.");
            }
        }
        else
        {
            throw MakeException("File read fail.");
        }
    }
}

FILE* TcpSocket::ReceiveFile() const
{
    return nullptr;
}

std::exception TcpSocket::MakeException(const std::string& Message)
{
    const DWORD ErrorCode = GetLastError();
    std::string ExceptionMessage;
    ExceptionMessage.append("[");
    ExceptionMessage.append(std::to_string(ErrorCode));
    ExceptionMessage.append("] ");
    ExceptionMessage.append(Message);
    return std::exception(ExceptionMessage.c_str());
}

void TcpSocket::Send(const char* Data, const int Size) const
{
    const int Byte = send(Socket, Data, Size, 0);
        if (Byte < 0)
        {
            throw MakeException("Send fail.");
        }
        if (Byte == 0)
        {
            throw MakeException("Disconnected.");
        }
}
