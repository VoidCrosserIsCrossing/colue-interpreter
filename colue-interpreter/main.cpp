#include <iostream>
#include <fstream>
#include <sstream>

// vars
std::string source_file_str;

// functions
void ReadSourceFileToStr()
{
	const auto* file_address = "F:/test.cb";
	std::fstream source_file(file_address, std::ios::in);
	std::stringstream buf;
	buf << source_file.rdbuf();
	source_file_str = buf.str();
	source_file.close();
}

int main(int argc, char* argv[])
{
	ReadSourceFileToStr();
	std::cout << source_file_str;
	return 0;
}
