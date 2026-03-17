#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct Produk {
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};

Produk arr[100];
int n = 0;
const char* FILE_NAME = "lelele.csv";

void load() {
    FILE* f = fopen(FILE_NAME, "r");
    if (f == NULL) { n = 0; return; }
    n = 0;
    while (fscanf(f, " %[^,],%f,%[^,],%d\n", arr[n].nama, &arr[n].harga, arr[n].kategori, &arr[n].stok) == 4) {
        n++;
    }
    fclose(f);
}

void save() {
    FILE* f = fopen(FILE_NAME, "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s,%.1f,%s,%d\n", arr[i].nama, arr[i].harga, arr[i].kategori, arr[i].stok);
    }
    fclose(f);
}

void tambah() {
    if (n >= 100) { cout << "Penuh!\n"; return; }
    
    cout << "Nama: "; cin.ignore(); cin.getline(arr[n].nama, 50);
    cout << "Harga: "; cin >> arr[n].harga;
    
    string kat;
    do {
        cout << "Kategori (makanan/minuman): "; cin >> kat;
    } while (kat != "makanan" && kat != "minuman");
    strcpy(arr[n].kategori, kat.c_str());
    
    cout << "Stok: "; cin >> arr[n].stok;
    
    n++;
    save();
    cout << "Berhasil ditambahkan!\n";
}

void bubbleSort() {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j].nama, arr[j+1].nama) > 0) {
                Produk temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quickSort(int low, int high) {
    if (low >= high) return;
    float pivot = arr[high].harga;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].harga > pivot) {
            i++;
            Produk temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    i++;
    Produk temp = arr[i]; arr[i] = arr[high]; arr[high] = temp;
    
    quickSort(low, i-1);
    quickSort(i+1, high);
}

void tampil() {
    if (n == 0) { cout << "Kosong!\n"; return; }
    cout << "\nNo  Nama                Harga     Kategori    Stok\n";
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        printf("%-3d %-20s Rp%.1f   %-10s  %d\n", i+1, arr[i].nama, arr[i].harga, arr[i].kategori, arr[i].stok);
    }
}

void seqSearch() {
    char cari[50];
    cout << "Cari nama: "; cin.ignore(); cin.getline(cari, 50);
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].nama, cari) == 0) {
            cout << "Ditemukan! Harga: Rp" << arr[i].harga << " | Stok: " << arr[i].stok << endl;
            return;
        }
    }
    cout << "Tidak ditemukan!\n";
}

int binSearch(char* key) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arr[mid].nama, key);
        if (cmp == 0) return mid;
        if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void binarySearch() {
    bubbleSort();
    char cari[50];
    cout << "Cari nama: "; cin.ignore(); cin.getline(cari, 50);
    int idx = binSearch(cari);
    if (idx != -1) {
        cout << "Ditemukan! Harga: Rp" << arr[idx].harga << " | Stok: " << arr[idx].stok << endl;
    } else {
        cout << "Tidak ditemukan!\n";
    }
}

int main() {
    load();
    
    int pilih;
    while (true) {
        cout << "\n=== MENU LELELE ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Urutkan (1=Nama Bubble | 2=Harga Quick)\n";
        cout << "3. Cari (1=Sequential | 2=Binary)\n";
        cout << "4. Tampilkan Semua\n";
        cout << "5. Keluar\nPilih: ";
        cin >> pilih;
        
        if (pilih == 1) tambah();
        else if (pilih == 2) {
            int m; cin >> m;
            if (m == 1) { bubbleSort(); cout << "Sudah diurut nama!\n"; }
            else if (m == 2) { quickSort(0, n-1); cout << "Sudah diurut harga!\n"; }
            tampil();
        }
        else if (pilih == 3) {
            int m; cin >> m;
            if (m == 1) seqSearch();
            else if (m == 2) binarySearch();
        }
        else if (pilih == 4) tampil();
        else if (pilih == 5) break;
        else cout << "Pilihan salah!\n";
    }
    return 0;
}