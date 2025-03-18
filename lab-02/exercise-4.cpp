#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int count_occurrences(const vector<T>& A, const T& value) {
	size_t counter = 0; 
	for (T element : A) {
		if (element == value) ++counter; 
	}
	return counter;
}

int main() {
	// Test funkcji zliczającej
	vector<int> v = {1, 2, 3, 4, 5, 3, 7, 4, 8, 2, 2};
	cout << count_occurrences(v, 2) << endl;

	return 0;
}
