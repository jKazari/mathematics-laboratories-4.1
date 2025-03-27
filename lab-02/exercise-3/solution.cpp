#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<typename T>
void write_std_vector(string filename, const vector<T>& A) {
	ofstream output_file(filename);
	for (T elem : A) {
		output_file << elem << " ";
	}
	output_file << endl;
	output_file.close();
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	write_std_vector("output.txt", v);

	return 0;
}
