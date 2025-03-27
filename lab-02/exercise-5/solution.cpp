#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void reverse_array(vector<T>& A) {
    size_t left = 0;
	size_t right = A.size() - 1;
    while (left < right) {
        swap(A[left], A[right]);
        ++left;
        --right;
    }
}

int main() {
	// Test funkcji odwracającej
	vector<int> v = {1, 2, 3, 4, 5, 3, 7, 4, 8, 2, 2};
	reverse_array(v);
    for (int x : v) cout << x << " ";
    cout << endl;

	return 0;
}
