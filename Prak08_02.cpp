#include<iostream>
using namespace std;

class SequentialSearch {
private:
    int data[11];
    int jmlElemen;

public:
    SequentialSearch() {
        jmlElemen = 11;
        int temp[] = {22, 61, 15, 66, 18, 25, 34, 87, 55, 45, 18};
        for(int i = 0; i < jmlElemen; i++) {
            data[i] = temp[i];
        }
    }

    void tampilkanData() {
        cout << "******************************************" << endl;
        cout << "***       SEQUENTIAL SEARCH           ***" << endl;
        cout << "******************************************" << endl;
        cout << "Isi data nya adalah :" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
        for(int count = 0; count < jmlElemen; count++) {
            cout << "\t" << "Data [" << count << "]" << " --> " << data[count] << endl;
        }
    }

    int cariElemen(int elemen) {
        int flag = -1;
        for(int count = 0; count < jmlElemen; count++) {
            if(elemen == data[count]) {
                flag = count;
                break;
            }
        }
        return flag;
    }

    void prosesSearch(int searchElemen) {
        cout << "******************************************" << endl;
        cout << "Data yang akan dicari : " << searchElemen << endl;
        int flag = cariElemen(searchElemen);
        if(flag != -1)
            cout << "Data yang dicari ditemukan pada posisi : Data[" << flag << "]" << endl;
        else
            cout << "Data yang Anda cari tidak ditemukan" << endl;
    }
};

int main() {
    SequentialSearch obj;
    obj.tampilkanData();
    int searchElemen = 25;
    obj.prosesSearch(searchElemen);
    searchElemen = 99;
    obj.prosesSearch(searchElemen);

    cin.get();
    return 0;
}