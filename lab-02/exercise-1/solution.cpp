#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
void print_std_vector(const vector<T>& A) {
    for (T a : A) {
        cout << a << " ";
    }
    cout << endl;
}


int main() {
	vector<int> v1 = {1, 2, 3, 4, 5};
	print_std_vector(v1);

	vector<char> v2 = {'h', 'e', 'l', 'l', 'o'};
	print_std_vector(v2);

	vector<string> v3 = {"hello", "world"};
	print_std_vector(v3);

	return 0;
}
