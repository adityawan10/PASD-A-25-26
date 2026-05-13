#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 
struct Mahasiswa {
    string npm;
    string nama;
    double nilai;
};
 
class MergeSortClass {
private:
    Mahasiswa *data;
    int        size;
	
    void merge(int Kiri, int mid, int Kanan) {
        int n1 = mid - Kiri + 1;
        int n2 = Kanan - mid;
        Mahasiswa *L = new Mahasiswa[n1];
        Mahasiswa *R = new Mahasiswa[n2];
        for (int i = 0; i < n1; i++)
            L[i] = data[Kiri + i];
        for (int j = 0; j < n2; j++)
            R[j] = data[mid + 1 + j];
        int i = 0;
        int j = 0;
        int k = Kiri;
        while (i < n1 && j < n2) {
            if (L[i].nilai <= R[j].nilai) {
                data[k] = L[i];
                i++;
            } else {
                data[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            data[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            data[k] = R[j];
            j++;
            k++;
        }
 
        delete[] L;
        delete[] R;
    }

    void mergeSort(int Kiri, int Kanan) {
        if (Kiri < Kanan) {
            int mid = Kiri + (Kanan - Kiri) / 2;
            mergeSort(Kiri, mid);
            mergeSort(mid + 1, Kanan);
            merge(Kiri, mid, Kanan);
        }
    }
 
public:
    MergeSortClass(Mahasiswa arr[], int n) {
        size = n;
        data = new Mahasiswa[n];
        for (int i = 0; i < n; i++)
            data[i] = arr[i];
    }
    ~MergeSortClass() {
        delete[] data;
    }
    void sort() {
        mergeSort(0, size - 1);
    }
    void cetakData() {
        cout << left
             << setw(15) << "NPM"
             << setw(25) << "Nama"
             << setw(10) << "Nilai" << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < size; i++) {
            cout << left
                 << setw(15) << data[i].npm
                 << setw(25) << data[i].nama
                 << fixed << setprecision(2) << data[i].nilai << endl;
        }
    }
};
int main() {
    Mahasiswa MhsList[9] = {
        {"45232210666", "Sisi",  80.65},
        {"45232210777", "Sasa",  98.75},
        {"45232210888", "Nila",  78.95},
        {"45232210999", "Doni",  78.85},
        {"45232210444", "Rian",  58.85},
        {"45232210222", "Elis",  77.95},
        {"45232210333", "Anto",  85.90},
        {"45232210111", "Cici",  88.70},
        {"45232210555", "Aris",  79.95}
    };
 
    int n = 9;
    MergeSortClass ms(MhsList, n);
    cout << "=================================================" << endl;
    cout << "   PROGRAM MERGE SORT - ASCENDING (PASD6-18)"    << endl;
    cout << "=================================================" << endl;
    cout << "\nData SEBELUM diurutkan:" << endl;
    ms.cetakData();    
    ms.sort();
    cout << "\nData SETELAH diurutkan (Ascending - Nilai):" << endl;
    ms.cetakData();
    cout << "\n=================================================" << endl;
    cout << "                  SELESAI"                          << endl;
    cout << "=================================================" << endl;
    cin.get();
    return 0;
}