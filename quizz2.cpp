#include<iostream>
#include<string>
using namespace std;

struct Barang {
    string kodeBarang;
    string namaBarang;
    int stokBarang;
};

int Search01(Barang[], int, string);

int main()
{
    const int JmlElemenArray = 5;
    Barang toko[JmlElemenArray] = {
        {"BRG001", "Sabun Mandi",    50},
        {"BRG002", "Shampo",         30},
        {"BRG003", "Pasta Gigi",     75},
        {"BRG004", "Sikat Gigi",     40},
        {"BRG005", "Minyak Rambut",  20}
    };

    cout << "****************************************" << endl;
    cout << "** S E A R C H   D A T A   B A R A N G **" << endl;
    cout << "****************************************" << endl;
    cout << "Isi data barang adalah" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    for (int count = 0; count < JmlElemenArray; count++)
    {
        cout << "\t" << "Barang [" << count << "] --> "
             << toko[count].kodeBarang << " | "
             << toko[count].namaBarang << " | Stok: "
             << toko[count].stokBarang << endl;
    }

    string SearchElemen = "";
    int flaq = 0;

    cout << "****************************************" << endl;
    cout << endl;
    cout << "Masukkan kode barang yang akan dicari ? ";
    cin >> SearchElemen;

    flaq = Search01(toko, JmlElemenArray, SearchElemen);

    if (flaq != -1) {
        cout << "Barang ditemukan pada posisi : Barang[" << flaq << "]" << endl;
        cout << "  Kode  : " << toko[flaq].kodeBarang << endl;
        cout << "  Nama  : " << toko[flaq].namaBarang << endl;
        cout << "  Stok  : " << toko[flaq].stokBarang << " unit" << endl;
    } else {
        cout << "Barang yang Anda cari tidak ditemukan" << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}

int Search01(Barang toko[], int JmlElemenArray, string Elemen)
{
    int flaq = -1;
    for (int count = 0; count < JmlElemenArray; count++)
    {
        if (Elemen == toko[count].kodeBarang)
        {
            flaq = count;
            break;
        }
    }
    return flaq;
}