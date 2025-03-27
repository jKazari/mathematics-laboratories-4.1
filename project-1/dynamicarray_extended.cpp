#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

namespace AiSD {

struct Record {
    std::string name;
    unsigned grade;
};

class DynamicArray {
private:
    std::vector<Record> data;

public:
    // Constructors
    DynamicArray(size_t capacity) { data.reserve(capacity); }
    DynamicArray(size_t capacity, size_t N, const Record& t) {
        data.reserve(capacity);
        for (size_t i = 0; i < N; ++i) {
            data.push_back(t);
        }
    }
    
    // Element Access
    Record& at(size_t i) {
        if (i >= data.size()) throw std::out_of_range("Index out of range");
        return data[i];
    }
    
    // Modification
    void Clear() { data.clear(); }
    
    size_t Search(const Record& t) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i].name == t.name && data[i].grade == t.grade) return i;
        }
        return data.size();
    }
    
    bool EraseFirst(const Record& t) {
        size_t index = Search(t);
        if (index != data.size()) {
            data.erase(data.begin() + index);
            return true;
        }
        return false;
    }
    
    size_t EraseAll(const Record& t) {
        size_t count = 0;
        for (auto it = data.begin(); it != data.end(); ) {
            if (it->name == t.name && it->grade == t.grade) {
                it = data.erase(it);
                count++;
            } else {
                ++it;
            }
        }
        return count;
    }
    
    size_t Erase(size_t from, size_t to) {
        if (from >= data.size() || to > data.size() || from >= to) {
            throw std::out_of_range("Invalid range");
        }
        size_t count = to - from;
        data.erase(data.begin() + from, data.begin() + to);
        return count;
    }
    
    // File Operations
    void SaveToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& record : data) {
            file << record.name << " " << record.grade << "\n";
        }
    }
    
    void LoadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        data.clear();
        Record temp;
        while (file >> temp.name >> temp.grade) {
            data.push_back(temp);
        }
    }
    
    // Insert elements at position i
    void Insert(size_t i, const std::vector<Record>& records) {
        if (i > data.size()) throw std::out_of_range("Index out of range");
        data.insert(data.begin() + i, records.begin(), records.end());
    }
    
    // Utility
    void Print() {
        for (const auto& record : data) {
            std::cout << "(" << record.name << ", " << record.grade << ") ";
        }
        std::cout << "\n";
    }
};

} // namespace AiSD

// Testing
int main() {
    using namespace AiSD;
    DynamicArray arr(10);
    arr.Insert(0, {{"Alice", 90}, {"Bob", 85}, {"Charlie", 78}});
    arr.Print();
    arr.SaveToFile("data.txt");
    
    arr.EraseFirst({"Bob", 85});
    arr.Print();
    
    arr.LoadFromFile("data.txt");
    arr.Print();
    
    return 0;
}