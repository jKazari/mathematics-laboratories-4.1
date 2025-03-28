#include <iostream>

using namespace std;

template <typename T>
struct SLLNode {
    T data;
    SLLNode<T>* next;

    SLLNode(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
struct DLLNode {
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;

    DLLNode(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

int main() {
    // Create nodes n0 to n9
    SLLNode<int>* nodes[10];
    for (int i = 0; i < 10; ++i) {
        nodes[i] = new SLLNode<int>(i);
    }

    // Link the nodes according to the pattern: n(i) -> n(i+3 mod 10)
    for (int i = 0; i < 10; ++i) {
        nodes[i]->next = nodes[(i + 3) % 10];
    }

    // Print the values in order of node numbering (n0 to n9)
    cout << "Values in node order (n0 to n9):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "n" << i << ".data = " << nodes[i]->data << endl;
    }

    // Print the values following the links
	cout << "\nValues following the links:" << endl;
	SLLNode<int>* current = nodes[0];
	for (int i = 0; i < 10; ++i) {
		// Find which node this is (n0 to n9)
		int node_index = 0;
		for (int j = 0; j < 10; ++j) {
			if (nodes[j] == current) {
				node_index = j;
				break;
			}
		}
		cout << "n" << node_index << ".data = " << current->data << endl;
		current = current->next;
	}

    // Clean up memory
    for (int i = 0; i < 10; ++i) {
        delete nodes[i];
    }

    return 0;
}
