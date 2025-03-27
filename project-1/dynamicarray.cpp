#include <iostream>
#include <fstream>

namespace AiSD {
	template <typename T>
	class DynamicArray {
	private:
		size_t capacity;
		size_t size;
		T* data;

	public:
		DynamicArray(size_t capacity) : capacity(capacity), size(0) {
			data = new T[capacity];
		}

		~DynamicArray() {
			delete[] data;
		}

		bool IsEmpty() const {
			return size == 0;
		}

		bool IsFull() const {
			return size == capacity;
		}

		size_t Space() const {
			return capacity - size;
		}

		T& operator[](size_t i) {
			return data[i];
		}

		const T& operator[](size_t i) const {
			return data[i];
		}

		void PushBack(T t) {
			data[size++] = t;
		}

		void PopBack() {
			if (size > 0) {
				size--;
			}
		}

		void PushFront(T t) {
			for (size_t i = size; i > 0; i--) {
				data[i] = data[i - 1];
			}
			data[0] = t;
			size++;
		}

		void PopFront() {
			for (size_t i = 0; i < size - 1; i++) {
				data[i] = data[i + 1];
			}
			size--;
		}

		void Insert(T t, size_t i) {
			for (size_t j = size; j > i; j--) {
				data[j] = data[j - 1];
			}
			data[i] = t;
			size++;
		}

		void Erase(size_t i) {
			for (size_t j = i; j < size - 1; j++) {
				data[j] = data[j + 1];
			}
			size--;
		}

		void Print() const {
			std::cout << "Array: ";
			for (size_t i = 0; i < size; i++) {
				std::cout << data[i] << " ";
			}
			std::cout << "\nFree space: " << Space() << "\n\n";
		}

		void SaveToFile(const std::string& filename) const {
			std::ofstream file(filename);
			for (size_t i = 0; i < size; i++) {
				file << data[i] << " ";
			}
			file << "\nFree space: " << Space() << "\n\n";
		}
	};
}

int main() {
    AiSD::DynamicArray<int> array(10);

	if (array.IsEmpty()) {
		std::cout << "Array empty" << "\n\n";
	}
	else {
		std::cout << "Array not empty" << "\n\n";
	}

    array.PushBack(1);
    array.PushBack(2);
    array.PushBack(3);
    array.Print();

    array.PushFront(0);
    array.Print();

    array.Insert(4, 2);
    array.Print();

    array.PopFront();
    array.Print();

    array.PopBack();
    array.Print();

    array.Erase(1);
    array.Print();

	array.SaveToFile("output.txt");

	for (size_t i = 3; i <= 10; i++) {
		array.PushBack(i);
	}

	array.Print();

	if (array.IsFull()) {
		std::cout << "Array full" << "\n\n";
	}
	else {
		std::cout << "Array not full" << "\n\n";
	}

    return 0;
}
