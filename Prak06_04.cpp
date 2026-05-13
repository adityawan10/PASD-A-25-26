#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string npm;
    string nama;
    double nilai;
};

void Q_Sort(Mahasiswa Angka[], int Kiri, int Kanan);
 
void tampilData(Mahasiswa data[], int n) {
    cout << left
         << setw(15) << "NPM"
         << setw(25) << "Nama"
         << setw(10) << "Nilai" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << left
             << setw(15) << data[i].npm
             << setw(25) << data[i].nama
             << fixed << setprecision(2) << data[i].nilai << endl;
    }
}
 
int main() {
    Mahasiswa MhsList[9] = {
        {"45232210666", "Asep",  77.69},
        {"45232210777", "Lisa",  68.80},
        {"45232210888", "Tia ",  86.79},
        {"45232210999", "Didi",  89.95},
        {"45232210444", "Riko",  68.75},
        {"45232210222", "ajja",  98.85},
        {"45232210333", "Ali ",  95.70},
        {"45232210111", "pitra", 75.50},
        {"45232210555", "iren",  88.75}
    };
 
    int n = 9;
    cout << "=================================================" << endl;
    cout << "   PROGRAM QUICK SORT - ASCENDING (PASD6-04)"    << endl;
    cout << "=================================================" << endl;
    cout << "\nData SEBELUM diurutkan:" << endl;
    tampilData(MhsList, n);
    Q_Sort(MhsList, 0, n - 1);
    cout << "\nData SETELAH diurutkan (Ascending - Nilai):" << endl;
    tampilData(MhsList, n);
    cout << "\n=================================================" << endl;
    cout << "                  SELESAI"                          << endl;
    cout << "=================================================" << endl;
 
    cin.get();
    return 0;
}
 
void Q_Sort(Mahasiswa Angka[], int Kiri, int Kanan) {
    int       Kiri_Hold, Kanan_Hold;
    Mahasiswa pivot;
 
    Kiri_Hold  = Kiri;
    Kanan_Hold = Kanan;
    pivot      = Angka[Kiri];   
 
    while (Kiri < Kanan) {
        while ((Angka[Kanan].nilai >= pivot.nilai) && (Kiri < Kanan))
            Kanan--;
 
        if (Kiri != Kanan) {
            Angka[Kiri] = Angka[Kanan];
            Kiri++;
        }
        while ((Angka[Kiri].nilai <= pivot.nilai) && (Kiri < Kanan))
            Kiri++;
 
        if (Kiri != Kanan) {
            Angka[Kanan] = Angka[Kiri];
            Kanan--;
        }
    }
    Angka[Kiri] = pivot;
    int pivot_pos = Kiri;
    Kiri  = Kiri_Hold;
    Kanan = Kanan_Hold;
    if (Kiri < pivot_pos)
        Q_Sort(Angka, Kiri, pivot_pos - 1);
    if (Kanan > pivot_pos)
        Q_Sort(Angka, pivot_pos + 1, Kanan);
}