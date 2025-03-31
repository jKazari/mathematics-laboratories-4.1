#include <iostream>
#include <fstream>

using namespace std;

namespace AiSD {
	template <typename T>
	class DLLNode {
	public:
		T data;
		DLLNode* prev;
		DLLNode* next;

		DLLNode(const T& value) : data(value), prev(nullptr), next(nullptr) {}
	};

	template <typename T>
	class DLL {
	private:
		DLLNode<T>* head;
		DLLNode<T>* tail;
		size_t size;

	public:
		DLL() : head(nullptr), tail(nullptr), size(0) {}

		~DLL() {
			Clear();
		}

		void PushFront(const T& el) {
			DLLNode<T>* newNode = new DLLNode<T>(el);
			if (head == nullptr) {
				head = tail = newNode;
			}
			else {
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			size++;
		}

		void PopFront() {
			if (head == nullptr) return;
			
			DLLNode<T>* temp = head;
			if (head == tail) {
				head = tail = nullptr;
			} 
			else {
				head = head->next;
				head->prev = nullptr;
			}
			delete temp;
			size--;
		}

		void PushBack(const T& el) {
			DLLNode<T>* newNode = new DLLNode<T>(el);
			if (tail == nullptr) {
				head = tail = newNode;
			}
			else {
				newNode->prev = tail;
				tail->next = newNode;
				tail = newNode;
			}
			size++;
		}

		void PopBack() {
			if (tail == nullptr) return;

			DLLNode<T>* temp = tail;
			if (head == tail) {
				head = tail = nullptr;
			}
			else {
				tail = tail->prev;
				tail->next = nullptr;
			}
			delete temp;
			size--;
		}

		T& Front() {
			return head->data;
		}

		T& Back() {
			return tail->data;
		}

		bool IsEmpty() const {
			return head == nullptr;
		}

		size_t Size() const {
			return size;
		}

		void Clear() {
			while (head != nullptr) {
				PopFront();
			}
		}

		void DisplayFromFront() const {
			DLLNode<T>* current = head;
			while (current != nullptr) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}

		void DisplayFromBack() const {
			DLLNode<T>* current = tail;
			while (current != nullptr) {
				cout << current->data << " ";
				current = current->prev;
			}
			cout << endl;
		}

		void SaveToFile(const string& filename) const {
			ofstream file(filename);
			if (file.is_open()) {
				DLLNode<T>* current = head;
				while (current != nullptr) {
					file << current->data << " ";
					current = current->next;
				}
				file.close();
			}
		}
	};
}

int main() {
	AiSD::DLL<int> dll;

	// Test PushFront and DisplayFromFront
	dll.PushFront(3);
	dll.PushFront(2);
	dll.PushFront(1);
	cout << "List after PushFront operations: ";
	dll.DisplayFromFront();

	// Test PushBack and DisplayFromBack
	dll.PushBack(4);
	dll.PushBack(5);
	cout << "List after PushBack operations: ";
	dll.DisplayFromFront();
	cout << "List displayed from back: ";
	dll.DisplayFromBack();

	// Test Front and Back
	cout << "Front element: " << dll.Front() << endl;
	cout << "Back element: " << dll.Back() << endl;

	// Test PopFront
	dll.PopFront();
	cout << "List after PopFront: ";
	dll.DisplayFromFront();

	// Test PopBack
	dll.PopBack();
	cout << "List after PopBack: ";
	dll.DisplayFromFront();

	// Test IsEmpty and Size
	cout << "Is list empty? " << (dll.IsEmpty() ? "Yes" : "No") << endl;
	cout << "Size of the list: " << dll.Size() << endl;

	// Test SaveToFile
	dll.SaveToFile("output.txt");
	cout << "List saved to file 'output.txt'." << endl;

	// Test Clear
	dll.Clear();
	cout << "List cleared";
	cout << "Is list empty? " << (dll.IsEmpty() ? "Yes" : "No") << endl;

	return 0;
}