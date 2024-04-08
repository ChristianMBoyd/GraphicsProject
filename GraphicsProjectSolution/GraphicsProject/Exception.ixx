export module Exception;
import std;

/*
This is the OmegaException as provided in the cppcon talk "Exceptionally Bad : The Story on the Misuse of Exceptions and How to Do Better."
The slides can be found at https://github.com/CppCon/CppCon2023.
*/

export template<typename Data>
class Exception : std::exception
{
public:
	Exception(std::string description, Data data, const std::source_location& location = std::source_location::current(), std::stacktrace stacktrace = std::stacktrace::current()) :
		description_{ std::move(description) }, data_{ std::move(data) }, location_{ location }, stacktrace_{ stacktrace }
	{}

	auto what() const noexcept -> const char* { return description_.c_str(); }

	auto description() -> std::string& { return description_; }
	auto description() const noexcept -> const std::string& { return description_; }

	auto where() const noexcept -> const std::source_location& { return location_; }

	auto stacktrace() const noexcept -> const std::stacktrace& { return stacktrace_; }

	auto data() -> Data& { return data_; }
	auto data() const noexcept -> const Data& { return data_; }

private:
	std::string description_;
	Data data_;
	const std::source_location location_;
	const std::stacktrace stacktrace_;
};