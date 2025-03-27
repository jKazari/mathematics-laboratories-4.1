#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename Function>
void transform_array(vector<T>& A, Function foo) {
    for (auto& elem : A) {
        elem = foo(elem);
    }
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    transform_array(v, [](int x) { return x * x; });
    for (int elem : v) {
        cout << elem << " "; 
    }

	return 0;
}
