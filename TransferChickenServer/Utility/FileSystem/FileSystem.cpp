#include "FileSystem.h"

FileSystem::FileSystem(): File(nullptr), IsOpened(false), IsClosed(false)
{
}

FileSystem::~FileSystem()
{
    if (IsOpened && !IsClosed)
    {
        const int _ = fclose(File);
    }
}

bool FileSystem::Open(const char* FileName, const char* Mode)
{
    const errno_t Error = fopen_s(&File, FileName, Mode);
    if (Error == 0)
    {
        IsOpened = true;
        IsClosed = false;
    }
    return IsOpened;
}

FILE* FileSystem::GetFile() const
{
    return File;
}

size_t FileSystem::ReadFile() const
{
    if (!IsOpened || IsClosed)
    {
        return 0;
    }
    const size_t Size = fread_s(Buffer, sizeof(Buffer), sizeof(char), sizeof(Buffer), File);
    return Size;
}

size_t FileSystem::WriteByte(const char* Buffer, const size_t Size) const
{
    if (!IsOpened || IsClosed)
    {
        return 0;
    }
    const size_t WriteSize = fwrite(Buffer, sizeof(char), Size, File);
    return WriteSize;
}

bool FileSystem::Close()
{
    const int Error = fclose(File);
    if (Error == 0)
    {
        IsOpened = false;
        IsClosed = true;
    }
    return IsClosed;
}
