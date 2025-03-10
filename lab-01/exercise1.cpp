#include <iostream>
#include <iomanip>
 
int main() {
    std::cout << "Hello World!\n";
	std::cout << "AiSD\n";

	int n = 5;
	while (n <= 302) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 20; j++) {
				std::cout << std::setw(4) << n;
				n += 3;
			}
			std::cout << "\n"; 
		}
	}

    return 0;
}