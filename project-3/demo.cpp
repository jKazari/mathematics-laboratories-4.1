#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "mergesort.cpp"
#include "quicksort.cpp"

using namespace std;

vector<int> readFromFile(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);
    int value;

    if (!file) {
        cout << "Error: Cannot open file \"" << filename << "\"\n";
        return numbers;
    }

    while (file >> value) {
        numbers.push_back(value);
    }

    return numbers;
}

bool writeToFile(const string& filename, const vector<int>& data,
                 long long mergeTime, long long quickTime) {
    ofstream out(filename);
    if (!out) {
        cout << "Error: Cannot write to file \"" << filename << "\"\n";
        return false;
    }

    out << "Merge Sort Time (microseconds): " << mergeTime << "\n";
    out << "Quick Sort Time (microseconds): " << quickTime << "\n\n";
    out << "Sorted Data:\n";
    for (int val : data) {
        out << val << " ";
    }
    out << "\n";

    return true;
}

bool writeRandomSetToFile(const string& filename, int count) {
    ofstream out(filename);
    if (!out) {
        cout << "Error: Cannot write to file \"" << filename << "\"\n";
        return false;
    }

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < count; ++i) {
        int val = rand() % (count + 1);
        out << val << " ";
    }
    out << "\n";

    return true;
}

int main() {
    cout << "Choose mode:\n";
    cout << "1. Sort a dataset from a file\n";
    cout << "2. Generate random dataset and save to file\n";
    cout << "Enter choice (1 or 2): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        string inputFilename;
        cout << "Enter input file name: ";
        cin >> inputFilename;

        vector<int> original = readFromFile(inputFilename);
        if (original.empty()) {
            cout << "Error: Unable to read data or file is empty.\n";
            return 1;
        }

        vector<int> mergeVec = original;
        vector<int> quickVec = original;

        auto start = chrono::high_resolution_clock::now();
        mergeSort(mergeVec, 0, static_cast<int>(mergeVec.size()) - 1);
        auto end = chrono::high_resolution_clock::now();
        long long mergeTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        start = chrono::high_resolution_clock::now();
        quickSort(quickVec, 0, static_cast<int>(quickVec.size()) - 1);
        end = chrono::high_resolution_clock::now();
        long long quickTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "\n--- Sorting Completed ---\n";
        cout << "Merge Sort Time: " << mergeTime << " microseconds\n";
        cout << "Quick Sort Time: " << quickTime << " microseconds\n";

        string outputFilename;
        cout << "Enter output file name: ";
        cin >> outputFilename;

        if (!writeToFile(outputFilename, mergeVec, mergeTime, quickTime)) {
            return 1;
        }

        cout << "Results written to \"" << outputFilename << "\"\n";

    }
	else if (choice == 2) {
        string filename;
        int size;
        cout << "Enter output file name for generated set: ";
        cin >> filename;
        cout << "Enter number of random integers to generate: ";
        cin >> size;

        if (writeRandomSetToFile(filename, size)) {
            cout << "Random set written to \"" << filename << "\"\n";
        }
		else {
            return 1;
        }
    }
	else {
        cout << "Error: Invalid choice.\n";
        return 1;
    }

    return 0;
}
