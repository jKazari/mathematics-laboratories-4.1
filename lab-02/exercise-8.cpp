#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename Func>
void transform_array(std::vector<T>& A, Func foo) {
    for (auto& elem : A) {
        elem = foo(elem);
    }
}

int main() {


	return 0;
}
