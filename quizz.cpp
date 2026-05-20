#include <iostream>
#include <iomanip>
using namespace std;

struct Barang {
    string kode;
    string nama;
    int stok;
};

int main() {
    const int MAX = 10;
    Barang data[MAX];
    int jumlah = 0;
    int pilihan;

    do {
        cout << "Sistem Data Barang Toko";
        cout << "=========================";
        cout << "1. Input Data Barang";
        cout << "2. Cari Barang";
        cout << "3. Keluar";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "Masukkan jumlah barang : ";
            cin >> jumlah;

            for (int i = 0; i < jumlah; i++) {
                cout << "Data ke-" << i + 1 << endl;
                cout << "Kode : ";
                cin >> data[i].kode;
                cout << "Nama : ";
                cin >> data[i].nama;
                cout << "Stok : ";
                cin >> data[i].stok;
            }

            cout << "=== Data Barang ===";
            cout << left << setw(15) << "Kode"
                 << setw(15) << "Nama"
                 << setw(10) << "Stok" << endl;

            for (int i = 0; i < jumlah; i++) {
                cout << left << setw(15) << data[i].kode
                     << setw(15) << data[i].nama
                     << setw(10) << data[i].stok << endl;
            }
            cout << endl;
            break;

        case 2: {
            string cariKode;
            bool ditemukan = false;

            cout << "Masukkan kode barang yang dicari : ";
            cin >> cariKode;

            for (int i = 0; i < jumlah; i++) {
                if (data[i].kode == cariKode) {
                    cout << "Barang ditemukan";
                    cout << "Kode : " << data[i].kode << endl;
                    cout << "Nama : " << data[i].nama << endl;
                    cout << "Stok : " << data[i].stok << endl;

                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Barang tidak ditemukan";
            }

            cout << endl;
            break;
        }

        case 3:
            cout << "Program selesai";
            break;

        default:
            cout << "Pilihan tidak valid";
        }

    } while (pilihan != 3);

    return 0;
}