#pragma once
#include <string>
#include <source_location>
#include <exception>
#include <stacktrace>

template<typename DATA>
class Exception : std::exception
{
public:
//	Exception()



private:
	std::string err_string_;
	DATA data_;
	const std::source_location location_;
	const std::stacktrace stacktrace_;
};