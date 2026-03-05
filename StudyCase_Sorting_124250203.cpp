#include <iostream>
#include <string>
using namespace std;

int n;
string nama[100];

void bubblesort() {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (nama[j] > nama[j+1]) {
                swap(nama[j], nama[j+1]);
            }
        }
    }
}


int pisah(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}



void quicksort(string arr[], int low, int high) {
    if (low < high) {
        int pi = pisah(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}




int main() {
    cout << "masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "nama ke -" << i+1 << ": ";
        cin >> nama[i];
    }



    bubblesort();
    cout << endl << "ascending (bubble sort):" << endl;
    for (int i = 0; i < n; i++) {
        cout << nama[i] << endl;
    }



    quicksort(nama, 0, n-1);
    cout << endl << "descending (quick sort):" << endl;
    for (int i = 0; i < n; i++) {
        cout << nama[i] << endl;
    }

}