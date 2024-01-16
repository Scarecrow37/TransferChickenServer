#pragma once
#include <exception>
#include <string>

class Exception
{
public:
    static std::exception MakeException(const std::string& Message);
};
