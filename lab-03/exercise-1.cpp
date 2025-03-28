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
	SLLNode<int> singleNode(10);
    DLLNode<int> doubleNode(20);

    cout << "Singly linked list node data: " << singleNode.data << endl;
    cout << "Doubly linked list node data: " << doubleNode.data << endl;

    return 0;
}
