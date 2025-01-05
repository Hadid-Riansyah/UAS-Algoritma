#include <iostream>
#include <vector>
using namespace std;

int linear_search(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // Target ditemukan
        }
    }
    return -1;  // Target tidak ditemukan
}

int main() {
    cout << "NAMA : Hadid Riansyah" << endl;
    cout << "NIM  : 241011400908" << endl;

    vector<int> unsorted_dataset = {10, 5, 8, 3, 6, 1, 12};
    int target_value = 8;

    int result = linear_search(unsorted_dataset, target_value);
    if (result != -1) {
        cout << "Elemen " << target_value << " ditemukan di indeks " << result << "." << endl;
    } else {
        cout << "Elemen " << target_value << " tidak ditemukan. " << endl;
    }

    return 0;
}
