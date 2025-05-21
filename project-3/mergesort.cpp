#include <vector>

using namespace std;

template <typename T>
void merge(vector<T>& array, int start, int mid, int end) {
    vector<T> startVec(array.begin() + start, array.begin() + mid + 1);
    vector<T> endVec(array.begin() + mid + 1, array.begin() + end + 1);

    int i = 0;
    int j = 0;
    int k = start;

    while (i < startVec.size() && j < endVec.size()) {
        if (startVec[i] <= endVec[j]) {
            array[k++] = startVec[i++];
        }
		else {
            array[k++] = endVec[j++];
        }
    }

    while (i < startVec.size()) {
        array[k++] = startVec[i++];
    }

    while (j < endVec.size()) {
        array[k++] = endVec[j++];
    }
}

template <typename T>
void mergeSort(vector<T>& array, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}
