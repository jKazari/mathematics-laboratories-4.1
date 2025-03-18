#include <iostream>
#include <array>
#include <vector>

using namespace std;

// Funkcja kopiująca dla std::vector
template<typename T>
void copy_std_vector(const vector<T>& A, vector<T>& B, size_t offset = 0) {
    if (offset >= B.size()) return;
    size_t copy_size = (A.size() < (B.size() - offset)) ? A.size() : (B.size() - offset);
    for (size_t i = 0; i < copy_size; i++) {
        B[offset + i] = A[i];
    }
}

// Funkcja kopiująca dla tablic różnych typów
template<typename ArrayA, typename ArrayB>
void copy_generic(const ArrayA& A, ArrayB& B, size_t offset = 0) {
    if (offset >= B.size()) return;
    size_t copy_size = (A.size() < (B.size() - offset)) ? A.size() : (B.size() - offset);
    for (size_t i = 0; i < copy_size; ++i) {
        B[offset + i] = A[i];
    }
}

int main() {
    // Test dla vector
    vector<int> A3 = {1, 2, 3, 4, 5};
    vector<int> B3 = {10, 11, 12, 13, 14, 15, 16};
    copy_std_vector(A3, B3, 4);
    for (int x : B3) {
		cout << x << " ";
	}
    cout << endl;

    // Test dla uogólnionej funkcji kopiowania
    vector<int> A4 = {1, 2, 3, 4, 5};
    array<int, 7> B4 = {10, 11, 12, 13, 14, 15, 16};
    copy_generic(A4, B4, 5);
    for (int x : B4) {
		cout << x << " ";
	}
    cout << endl;
    
    return 0;
}
