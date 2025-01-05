#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk melakukan binary search
int binary_search(const vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (arr[middle] == target) {
            return middle;
        } else if (arr[middle] < target) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

int main() {
    cout << "NAMA : Hadid Riansyah" << endl;
    cout << "NIM  : 241011400908" << endl;

    // Contoh penggunaan
    vector<int> numbers = {1, 3, 5, 7, 9, 11};
    int search_value = 9;
    int result = binary_search(numbers, search_value);

    if (result != -1) {
        cout << "Angka " << search_value << " ditemukan di indeks " << result << "." << endl;
    } else {
        cout << "Angka " << search_value << " tidak ditemukan." << endl;
    }

    return 0;
}
