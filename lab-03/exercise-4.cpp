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

SLLNode<short>* reverseSLL(SLLNode<short>* head) {
    SLLNode<short>* prev = nullptr;
    SLLNode<short>* current = head;

    while (current) {
        SLLNode<short>* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
	
    return prev;
}

DLLNode<short>* reverseDLL(DLLNode<short>* head) {
    DLLNode<short>* current = head;
    DLLNode<short>* prevNode = nullptr;
    
    while (current) {
        prevNode = current->prev;
        current->prev = current->next;
        current->next = prevNode;
        current = current->prev;
    }

    return prevNode ? prevNode->prev : head;
}

int main() {
	// Create singly linked list: 1 -> 2 -> 3 -> 4
	SLLNode<short>* sllHead = new SLLNode<short>(1);
	sllHead->next = new SLLNode<short>(2);
	sllHead->next->next = new SLLNode<short>(3);
	sllHead->next->next->next = new SLLNode<short>(4);

	cout << "Original SLL: ";
	printSLL(sllHead);

	SLLNode<short>* reversedSLL = reverseSLL(sllHead);
	cout << "Reversed SLL: ";
	printSLL(reversedSLL);

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

	cout << "Original DLL: ";
	printDLLForward(dllHead);

	DLLNode<short>* reversedDLL = reverseDLL(dllHead);
	cout << "Reversed DLL: ";
	printDLLForward(reversedDLL);

    return 0;
}
