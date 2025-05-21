#include <vector>
#include <utility>

using namespace std;

template <typename T>
int partition(vector<T>& array, int start, int end) {
    T pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (array[j] <= pivot) {
            ++i;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[end]);
    return i + 1;
}

template <typename T>
void quickSort(vector<T>& array, int start, int end) {
    if (start < end) {
        int p = partition(array, start, end);
        quickSort(array, start, p - 1);
        quickSort(array, p + 1, end);
    }
}
