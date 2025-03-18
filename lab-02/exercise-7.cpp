#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void fill_arithmetic_sequence(vector<T>& A, T start, T step) {
    for (size_t i = 0; i < A.size(); ++i) {
        A[i] = start + i * step;
    }
}

int main() {

    vector<int> v (10, 0);
    fill_arithmetic_sequence(v, 1, 3);
    for (int elem : v) {
        cout << elem << " ";
    }
    cout << endl;

	return 0;
}
