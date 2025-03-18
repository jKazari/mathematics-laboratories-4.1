#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void fill_arithmetic_sequence(std::vector<T>& A, T start, T step) {
    for (size_t i = 0; i < A.size(); ++i) {
        A[i] = start + i * step;
    }
}

template<typename T, typename Func>
void transform_array(std::vector<T>& A, Func foo) {
    for (auto& elem : A) {
        elem = foo(elem);
    }
}

int main() {


	return 0;
}
