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

void printSLL(SLLNode<short>* head) {
    SLLNode<short>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void printDLLForward(DLLNode<short>* head) {
    DLLNode<short>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void printDLLBackward(DLLNode<short>* tail) {
    DLLNode<short>* current = tail;
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int main() {
	// Create singly linked list: 1 -> 2 -> 3 -> 4 -> NULL
	SLLNode<short>* sllHead = new SLLNode<short>(1);
	sllHead->next = new SLLNode<short>(2);
	sllHead->next->next = new SLLNode<short>(3);
	sllHead->next->next->next = new SLLNode<short>(4);

	cout << "Singly Linked List: ";
	printSLL(sllHead);

	// Create doubly linked list: 10 <-> 20 <-> 30 <-> 40
	DLLNode<short>* dllHead = new DLLNode<short>(10);
	DLLNode<short>* second = new DLLNode<short>(20);
	DLLNode<short>* third = new DLLNode<short>(30);
	DLLNode<short>* dllTail = new DLLNode<short>(40);

	dllHead->next = second;
	second->prev = dllHead;
	second->next = third;
	third->prev = second;
	third->next = dllTail;
	dllTail->prev = third;

	cout << "Doubly Linked List Forward: ";
	printDLLForward(dllHead);

	cout << "Doubly Linked List Backward: ";
	printDLLBackward(dllTail);

    return 0;
}
