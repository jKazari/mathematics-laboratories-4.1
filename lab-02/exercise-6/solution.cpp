#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T find_min(const vector<T>& A) {
    T min = A[0];
    for (const T& elem : A) {
        if (elem < min) min = elem;
    }
    return min;
}

template<typename T>
T find_max(const vector<T>& A) {
    T max = A[0];
    for (const T& elem : A) {
        if (elem > max) max = elem;
    }
    return max;
}

int main() {
    // Test funkcji znajdujących najmniejszy i największy element
    vector<int> v = {-3, -2, -1, 0, 1, 2, 3};
    cout << find_min(v) << endl;
    cout << find_max(v) << endl;

	return 0;
}
