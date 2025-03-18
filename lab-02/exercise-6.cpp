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
        if (elem > min) max = elem;
    }
    return max;
}

int main() {


	return 0;
}
