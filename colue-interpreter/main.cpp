#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_map>
#include <utility>

enum class SymbolTableResults { kUnknownError = -1, kError, kSuccess };

class Identifier	// 标识符。
{
	std::string name_;
	std::string value_;
	std::string type_;
	

public:
	Identifier(std::string key, std::string value, std::string type) :
		name_(std::move(key)),
		value_(std::move(value)),
		type_(std::move(type)) {}

	friend class SymbolTable;
};

class SymbolTable	// 符号表。将被实例化为 一个全局符号表 与 各调用帧的符号表 。
{
	std::unordered_map<std::string, Identifier> identifiers_;
	
public:
	auto insert(std::string key, std::string value, std::string type)
	{
		return SymbolTableResults::kUnknownError;
	}
};

// functions
std::string ReadSourceFileToStr(const std::filesystem::path& file_path)
{
	std::fstream source_file(file_path, std::ios::in);
	std::stringstream buf;
	buf << source_file.rdbuf();
	return buf.str();
}

int main(int argc, char* argv[])
{
	const auto* file_address = "F:/test.cb";
	const auto src = ReadSourceFileToStr(file_address);
	std::cout << src;
	return 0;
}
