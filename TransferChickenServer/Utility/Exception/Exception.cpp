#include <minwindef.h>
#include <errhandlingapi.h>
#include "Exception.h"


std::exception Exception::MakeException(const std::string& Message)
{
    const DWORD ErrorCode = GetLastError();
    std::string ExceptionMessage;
    ExceptionMessage.append("[");
    ExceptionMessage.append(std::to_string(ErrorCode));
    ExceptionMessage.append("] ");
    ExceptionMessage.append(Message);
    return std::exception(ExceptionMessage.c_str());
}
