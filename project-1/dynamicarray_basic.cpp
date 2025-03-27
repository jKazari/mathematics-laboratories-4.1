#include <iostream>
#include <fstream>
#include <stdexcept>

namespace AiSD {
    template<typename T>
    class DynamicArray {
    private:
        static const size_t capacity = 100;
        T data[capacity];
        size_t size;
    
    public:
        DynamicArray() : size(0) {}
    
        bool IsEmpty() const { return size == 0; }
        bool IsFull() const { return size == capacity; }
        size_t Space() const { return capacity - size; }
    
        T& operator[](size_t i) { return data[i]; }
        T Get(size_t i) const { return data[i]; }
        void Set(size_t i, T t) { data[i] = t; }
    
        void PushBack(T t) { data[size++] = t; }
        void PopBack() { if (size > 0) --size; }
    
        void PushFront(T t) {
            for (size_t i = size; i > 0; --i) data[i] = data[i - 1];
            data[0] = t;
            ++size;
        }
    
        void PopFront() {
            for (size_t i = 0; i < size - 1; ++i) data[i] = data[i + 1];
            --size;
        }
    
        void Insert(T t, size_t i) {
            for (size_t j = size; j > i; --j) data[j] = data[j - 1];
            data[i] = t;
            ++size;
        }
    
        void Erase(size_t i) {
            for (size_t j = i; j < size - 1; ++j) data[j] = data[j + 1];
            --size;
        }
    
        void Display() const {
            for (size_t i = 0; i < size; ++i) std::cout << data[i] << " ";
            std::cout << "(Free space: " << Space() << ")\n";
        }
    
        void SaveToFile(const std::string& filename) const {
            std::ofstream file(filename);
            for (size_t i = 0; i < size; ++i) file << data[i] << " ";
            file << "\nFree space: " << Space() << "\n";
        }
    };
}

int main() {
    AiSD::DynamicArray arr;
    arr.PushBack(10);
    arr.PushBack(20);
    arr.PushFront(5);
    arr.Insert(15, 2);
    arr.Display();
    arr.PopFront();
    arr.Erase(1);
    arr.Display();
    arr.SaveToFile("array_output.txt");
    return 0;
}