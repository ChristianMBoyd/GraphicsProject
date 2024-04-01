// std
#include <string>
#include <source_location>
#include <exception>
#include <stacktrace>

/*
This is the OmegaException as provided in the cppcon talk "Exceptionally Bad : The Story on the Misuse of Exceptions and How to Do Better."
The slides can be found at https://github.com/CppCon/CppCon2023.
*/
template<typename DATA>
class Exception : std::exception
{
public:
	Exception(std::string description, DATA data, const std::source_location& location = std::source_location::current(), std::stacktrace stacktrace = std::stacktrace::current()) :
		description_{ std::move(description) }, data_{ std::move(data) }, location_{ location }, stacktrace_{ stacktrace }
	{}



private:
	std::string description_;
	DATA data_;
	const std::source_location location_;
	const std::stacktrace stacktrace_;
};