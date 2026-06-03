#include<iostream>
using namespace std;

struct DataArray {
    int data[100];
    int jmlElemen;
};

struct HasilSearch {
    int posisi;
    bool ditemukan;
};

int Search01(DataArray arr, int elemen) {
    int flag = -1;
    for(int count = 0; count < arr.jmlElemen; count++) {
        if(elemen == arr.data[count]) {
            flag = count;
            break;
        }
    }
    return flag;
}

void inputData(DataArray &arr) {
    cout << "******************************************" << endl;
    cout << "***       SEQUENTIAL SEARCH           ***" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    cout << "Masukkan jumlah elemen array : ";
    cin >> arr.jmlElemen;
    while(arr.jmlElemen <= 0 || arr.jmlElemen > 100) {
        cout << "Jumlah elemen harus antara 1-100!" << endl;
        cout << "Masukkan jumlah elemen array : ";
        cin >> arr.jmlElemen;
    }
    cout << endl;
    cout << "Masukkan isi elemen array :" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for(int count = 0; count < arr.jmlElemen; count++) {
        cout << "Data [" << count << "] : ";
        cin >> arr.data[count];
    }
}

void tampilkanData(DataArray arr) {
    cout << endl;
    cout << "Isi data nya adalah :" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
    for(int count = 0; count < arr.jmlElemen; count++) {
        cout << "\t" << "Data [" << count << "]" << " --> " << arr.data[count] << endl;
    }
}

void prosesSearch(DataArray arr) {
    int searchElemen;
    int flag;

    cout << endl;
    cout << "******************************************" << endl;
    cout << "Masukkan data yang akan Anda cari ? : ";
    cin >> searchElemen;

    flag = Search01(arr, searchElemen);

    cout << "******************************************" << endl;
    if(flag != -1)
        cout << "Data yang dicari ditemukan pada posisi : Data[" << flag << "]" << endl;
    else
        cout << "Data yang Anda cari tidak ditemukan" << endl;
}

int main() {
    DataArray arr;
    inputData(arr);
    tampilkanData(arr);
    prosesSearch(arr);
    cin.get();
    cin.get();
    return 0;
}