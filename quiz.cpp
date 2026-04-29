#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string kode;
    string nama_barang;
    int stock;
} NilaiKRYWN;

typedef struct elm *alamatelm;
typedef struct elm {
    NilaiKRYWN Kontainer;
    alamatelm next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} Queue;

void buatQUkosong(Queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isKosong(Queue Q) {
    bool hasil = false;

    if(Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

int jmlElemen(Queue Q) {
    int hasil = 0;

    if(Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;

        while(bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu -> next;
        }
    }
    return hasil;
}

void add(string kode, string nama_barang, int stock, Queue *Q) {
    elemen *info;
    info = new elemen;
    info -> Kontainer.kode = kode;
    info -> Kontainer.nama_barang = nama_barang;
    info -> Kontainer.stock = stock;
    info -> next = NULL;

    if((*Q).first == NULL) {
        (*Q).first = info;
    }
    else {
        (*Q).last -> next = info;
    }
    (*Q).last = info;
    info = NULL;
}

void del(Queue *Q) {
    if((*Q).first != NULL) {
        elemen *hapus = (*Q).first;

        if(jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else {
            (*Q).first = (*Q).first -> next;
            hapus -> next = NULL;
        }
        delete hapus;
    }
}

void CetakQueue(Queue Q)
{
    if(Q.first != NULL)
    {
        cout << " MENAMPILKAN QUEUE " << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while(bantu != NULL)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke          : " << i << endl;
            cout << "Nomor kode Barang : " << bantu -> Kontainer.kode << endl;
            cout << "Nama Mahasiswa        : " << bantu -> Kontainer.nama_barang << endl;
            cout << "Nilai Mahasiswa       : " << bantu -> Kontainer.stock << endl;
        bantu = bantu -> next;
        i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    else
    {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    Queue Q;
    buatQUkosong(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    add("210666", "Lampu", 200, &Q);
    add("210777", "Sapu", 300, &Q);
    add("210888", "piring",400, &Q);
    add("210999", "Gelas", 500, &Q);
    add("210555", "sikat", 800, &Q);
    add("210444", "sabun", 100, &Q);
    add("210222", "bangku", 300, &Q);
    CetakQueue(Q);
    cout << "=====================" << endl;
    cout << endl;
    cout << endl;
    del(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    del(&Q);
    CetakQueue(Q);
    cout << "=====================" << endl;
    return 0;
}