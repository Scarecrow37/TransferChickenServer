#pragma once
#include <cstdio>

class FileSystem
{
public:
    FileSystem();
    ~FileSystem();

    bool Open(const char* FileName, const char* Mode);
    FILE* GetFile() const;
    size_t ReadFile(char* Buffer) const;
    size_t WriteByte(const char* Buffer, size_t Size) const;
    bool Close();

private:
    FILE* File;
    char* Bytes;
    
    bool IsOpened;
    bool IsClosed;
};
