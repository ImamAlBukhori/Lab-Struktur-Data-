#include <iostream>
#include <vector>
using namespace std;

// untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
   
    int n1 = mid - left + 1;  // Jumlah elemen di bagian kiri
    int n2 = right - mid;  // Jumlah elemen di bagian kanan  

    vector<int> L(n1), R(n2); // Membuat array sementara untuk kiri dan kanan

    // Menyalin data ke array sementara
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    int i = 0;   
    int j = 0;      
    int k = left;

    // Menggabungkan kedua subarray ke dalam array utama
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Menyalin sisa elemen dari subarray kiri (jika ada)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Menyalin sisa elemen dari subarray kanan (jika ada)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    if (left >= right) // mengecek apakah kiri lebih besar sama dengan dari kanan
        return;

    int mid = left + (right - left) / 2; // untuk menentukan titik tengah array 

    mergeSort(arr, left, mid); // untuk mengurutkan bagian kiri
    mergeSort(arr, mid + 1, right); // untuk mengurutkan bagian kanan
   
    merge(arr, left, mid, right); // menggabungkan kedua bagian yang sudah terurut
}

// untuk mencetak isi dari array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n); // menggunakan vector untuk menampung data
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    mergeSort(data, 0, n - 1); // memanggil fungsi merge sort
   
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}