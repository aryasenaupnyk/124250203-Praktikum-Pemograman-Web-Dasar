#include <iostream>
using namespace std;

int main(){
    // deklarasi
    int n;
    cout << "masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    int *ptr = arr;

    // input isi array
    cout << "masukkan nilai array:\n";
    for(int i = 0; i < n; i++){
        cout << "elemen ke-" << i+1 << ": ";
        cin >> *(ptr + i);
    }

    // cetak isi array
    cout << "\nisi array: ";
    for(int i = 0; i < n; i++){
        cout << *(ptr + i) << " ";
    }

    // cari max, min, jumlah
    int max = *ptr;
    int min = *ptr;
    int jumlah = 0;

    for(int i = 0; i < n; i++){
        if(*(ptr + i) > max){
            max = *(ptr + i);
        }
        if(*(ptr + i) < min){
            min = *(ptr + i);
        }
        jumlah += *(ptr + i);
    }

    // hitung rata-rata
    float rata = (float)jumlah / n;

    // tampilkan hasil
    cout << "\n\nnilai maksimum : " << max << endl;
    cout << "nilai minimum  : " << min << endl;
    cout << "jumlah         : " << jumlah << endl;
    cout << "rata-rata      : " << rata << endl;

}
