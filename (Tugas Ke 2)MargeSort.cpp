#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Struktur untuk menyimpan data pesanan
struct Pesanan {
    int id_pesanan;
    string lokasi_pengambilan;
    string lokasi_tujuan;
    string waktu_pengiriman;
};

// Fungsi untuk mengurutkan data pesanan berdasarkan waktu pengiriman
void merge(vector<Pesanan>& data, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<Pesanan> left(n1), right(n2);

    for (int i = 0; i < n1; ++i)
        left[i] = data[low + i];
    for (int j = 0; j < n2; ++j)
        right[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i].waktu_pengiriman < right[j].waktu_pengiriman) {
            data[k] = left[i];
            ++i;
        } else {
            data[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        data[k] = left[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        data[k] = right[j];
        ++j;
        ++k;
    }
}

// Fungsi untuk menerapkan merge sort
void mergeSort(vector<Pesanan>& data, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
        merge(data, low, mid, high);
    }
}

int main() {
    // Contoh data pesanan
    vector<Pesanan> pesanan = {
        {1, "A", "B", "2025-01-05 08:30"},
        {2, "C", "D", "2025-01-05 07:00"},
        {3, "E", "F", "2025-01-05 09:00"},
        {4, "G", "H", "2025-01-05 06:00"}
    };

    // Menampilkan identitas
    cout << "Hadid Riansyah\n";
    cout << "241011400908\n\n";

    // Mengurutkan data pesanan berdasarkan waktu pengiriman
    mergeSort(pesanan, 0, pesanan.size() - 1);

    // Menampilkan data yang sudah terurut
    for (const auto& pesanan_item : pesanan) {
        cout << "ID Pesanan: " << pesanan_item.id_pesanan
             << ", Waktu Pengiriman: " << pesanan_item.waktu_pengiriman << endl;
    }

    return 0;
}
