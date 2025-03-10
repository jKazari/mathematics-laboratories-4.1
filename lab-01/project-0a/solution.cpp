#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;
using namespace chrono;

// Funkcja sumująca iteracyjnie
unsigned long long SumUpTo_addition(unsigned long long k) {
    unsigned long long sum = 0;
    for (unsigned long long i = 0; i <= k; ++i) {
        sum += i;
    }
    return sum;
}

// Funkcja sumująca ze wzoru
unsigned long long SumUpTo_formula(unsigned long long k) {
    return k * (k + 1) / 2;
}

// Funkcja wyświetlająca liczby od 1 do k
void PrintNumbers(unsigned long long k) {
    for (unsigned long long i = 1; i <= k; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

// Funkcja sumująca i wypisująca sumy cząstkowe
void PrintPartialSums(unsigned long long k) {
    unsigned long long sum = 0;
    for (unsigned long long i = 1; i <= k; ++i) {
        sum += i;
        cout << "Suma do " << i << ": " << sum << endl;
    }
}

// Funkcja testująca czas działania
void MeasureTime(const string &functionName, unsigned long long (*func)(unsigned long long), 
                 vector<unsigned long long> &testValues, ofstream &output) {
    for (unsigned long long k : testValues) {
        unsigned long long result;
        auto start = steady_clock::now();
        for (int i = 0; i < 10; ++i) {  // Powtórzenia dla uśrednienia czasu
            result = func(k);
        }
        auto end = steady_clock::now();
        duration<double, milli> elapsed = (end - start) / 10.0;
        output << functionName << "," << k << "," << result << "," << elapsed.count() << "\n";
    }
}

int main() {
    ofstream output("results.csv");
    output << "Function,k,Sum,Time (ms)\n";

    vector<unsigned long long> testValues;
    for (unsigned long long i = 100; i < 1000; i += 100) testValues.push_back(i);
    for (unsigned long long i = 1000; i < 10000; i += 1000) testValues.push_back(i);
    for (unsigned long long i = 10000; i < 100000; i += 10000) testValues.push_back(i);
	for (unsigned long long i = 100000; i < 1000000; i += 100000) testValues.push_back(i);

    MeasureTime("Addition", SumUpTo_addition, testValues, output);
    MeasureTime("Formula", SumUpTo_formula, testValues, output);

	// Testy PrintNumbers
	for (unsigned long long k : testValues) {
		ostringstream oss;
		auto start = steady_clock::now();
		for (int i = 0; i < 10; ++i) {
			streambuf* oldCoutBuffer = cout.rdbuf(oss.rdbuf());
			PrintNumbers(k);
			cout.rdbuf(oldCoutBuffer);
		}
		auto end = steady_clock::now();
		duration<double, milli> elapsed = (end - start) / 10.0;
		output << "PrintNumbers," << k << ",," << elapsed.count() << "\n";
	}

	// Testy PrintPartialSums
	for (unsigned long long k : testValues) {
		ostringstream oss;
		auto start = steady_clock::now();
		for (int i = 0; i < 10; ++i) {
			streambuf* oldCoutBuffer = cout.rdbuf(oss.rdbuf());
			PrintPartialSums(k);
			cout.rdbuf(oldCoutBuffer);
		}
		auto end = steady_clock::now();
		duration<double, milli> elapsed = (end - start) / 10.0;
		output << "PrintPartialSums," << k << ",," << elapsed.count() << "\n";
	}
	

    // Testy std::accumulate
    for (unsigned long long k : testValues) {
        vector<unsigned long long> numbers(k + 1);
        iota(numbers.begin(), numbers.end(), 0);
        auto start = steady_clock::now();
        for (int i = 0; i < 10; ++i) {
            accumulate(numbers.begin(), numbers.end(), 0ULL);
        }
        auto end = steady_clock::now();
        duration<double, milli> elapsed = (end - start) / 10.0;
        output << "Accumulate," << k << "," << accumulate(numbers.begin(), numbers.end(), 0ULL) << "," << elapsed.count() << "\n";
    }
    
    // Testy std::partial_sum
    for (unsigned long long k : testValues) {
        vector<unsigned long long> numbers(k + 1);
        iota(numbers.begin(), numbers.end(), 0);
        vector<unsigned long long> results(k + 1);
        auto start = steady_clock::now();
        for (int i = 0; i < 10; ++i) {
            partial_sum(numbers.begin(), numbers.end(), results.begin());
        }
        auto end = steady_clock::now();
        duration<double, milli> elapsed = (end - start) / 10.0;
        output << "Partial_Sum," << k << "," << results.back() << "," << elapsed.count() << "\n";
    }
    
    output.close();
    cout << "Dane zapisane do results.csv" << endl;
    return 0;
}