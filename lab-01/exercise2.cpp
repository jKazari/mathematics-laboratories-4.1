#include <iostream>
#include <iomanip>
 
int main()
{
    std::cout << "char: " 		<< sizeof(char) 		<< "\n";
	std::cout << "int: " 		<< sizeof(int) 			<< "\n";
	std::cout << "float: " 		<< sizeof(float) 		<< "\n";
	std::cout << "double: " 	<< sizeof(double) 		<< "\n";
	std::cout << "bool: " 		<< sizeof(bool) 		<< "\n";

	std::cout << "char*: " 		<< sizeof(char*) 		<< "\n";
	std::cout << "int*: " 		<< sizeof(int*) 		<< "\n";
	std::cout << "float*: " 	<< sizeof(float*) 		<< "\n";
	std::cout << "double*: "	<< sizeof(double*) 		<< "\n";
	std::cout << "bool*: "		<< sizeof(bool*) 		<< "\n";


    return 0;
}