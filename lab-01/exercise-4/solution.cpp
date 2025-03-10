#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <vector>

using namespace std;
 
int main() {
    int A[] = {0,1,2,3,4,5,6,7,8,9};
	int a = A[2];     // Assigns the third element of the array 'A' (value '2') to the variable 'a'
	A[5] = 13;        // Sets the sixth element of the array 'A' to '13'
	A[-1] = -1;       // Attempts to assign '-1' to an element at an invalid negative index, resulting in undefined behavior
	int b = A[10];    // Attempts to access an out-of-bounds element, leading to undefined behavior

	array<int,10> B = {0,1,2,3,4,5,6,7,8,9};
	B[-1] = -1;       // Attempts to assign '-1' to an element at an invalid negative index, resulting in undefined behavior
	int c = B[10];    // Attempts to access an out-of-bounds element, leading to undefined behavior
	B[10] = 1;        // Attempts to access an out-of-bounds element, leading to undefined behavior
	B.at(-1) = 1;     // Throws std::out_of_range exception
	int d = B.at(10); // Throws std::out_of_range exception

	vector<int> C = {0,1,2,3,4,5,6,7,8,9};
	C[-1] = -1;       // Attempts to assign '-1' to an element at an invalid negative index, resulting in undefined behavior
	int e = C[10];    // Attempts to access an out-of-bounds element, leading to undefined behavior
	C[10] = 1;        // Attempts to access an out-of-bounds element, leading to undefined behavior
	C.at(-1) = 1;     // Throws std::out_of_range exception
	int f = C.at(10); // Throws std::out_of_range exception

	ofstream file("memory_locations.txt");
    
    cout << "Memory locations of A:" << endl;
    file << "Memory locations of A:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "A[" << i << "] = " << A[i] << " at " << &A[i] << endl;
        file << "A[" << i << "] = " << A[i] << " at " << &A[i] << endl;
    }
    
    cout << "\nMemory locations of B:" << endl;
    file << "\nMemory locations of B:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "B[" << i << "] = " << B[i] << " at " << &B[i] << endl;
        file << "B[" << i << "] = " << B[i] << " at " << &B[i] << endl;
    }
    
    cout << "\nMemory locations of C:" << endl;
    file << "\nMemory locations of C:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "C[" << i << "] = " << C[i] << " at " << &C[i] << endl;
        file << "C[" << i << "] = " << C[i] << " at " << &C[i] << endl;
    }
    
    file.close();

    return 0;
}