#include <iostream>

int main(int argc, char* argv[])
{
	const auto maximum = 10000;
	const int a[] = { 0,0,1,1,2,2,3,3,4,4,5,5 };
	for (auto a1 : a)
	{
		std::cout << a1 << std::endl;
	}
	return 0;
}