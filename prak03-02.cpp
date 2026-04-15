#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();
void HAPUS_DEPAN();

struct Node {
    int INFO;       
    struct Node *LINK;
};

typedef struct Node Simpul;
Simpul *P, *FIRST, *LAST, *Q;
int X;

int main() {
    
    int NomorAntrian[5] = {101, 102, 103, 104, 105};
    int I;

    FIRST = NULL; 

    I = 0;
    X = NomorAntrian[I];
    BUAT_SIMPUL(X);
    AWAL();

    for(I = 1; I <= 4; I++) {
        X = NomorAntrian[I];
        BUAT_SIMPUL(X);
        INSERTKANAN();
    }

    cout << "=== SISTEM ANTRIAN PELANGGAN DI LOKET PEMBAYARAN ===" << endl;
    cout << endl;
    cout << "Antrian saat ini (Depan -> Belakang) : ";
    CETAK();
    cout << endl << endl;

    cout << "Pelanggan baru datang dengan Nomor Antrian 6..." << endl;
    X = 6;
    BUAT_SIMPUL(X);
    INSERTKANAN();
    cout << "Antrian setelah pelanggan baru masuk         : ";
    CETAK();
    cout << endl << endl;

    cout << "Pelanggan terdepan selesai dilayani, keluar dari antrian..." << endl;
    HAPUS_DEPAN();
    cout << "Antrian setelah pelanggan terdepan keluar    : ";
    CETAK();
    cout << endl << endl;

    cout << "Pelanggan baru datang dengan Nomor Antrian 7..." << endl;
    X = 7;
    BUAT_SIMPUL(X);
    INSERTKANAN();
    cout << "Antrian akhir                                : ";
    CETAK();
    cout << endl;

    cin.get();
    return 0;
}

void BUAT_SIMPUL(int X) 
{
    P = (Simpul*) malloc(sizeof(Simpul));
    if(P != NULL) {
        P->INFO = X;
        P->LINK = NULL;
    } else {
        cout << "Pembuatan Simpul Tidak Berhasil" << endl;
        cin.get();
        exit(1);
    }
}

void AWAL() 
{
    FIRST = P;
    LAST  = P;
    P->LINK = NULL;
}

void INSERTKANAN() 
{
    LAST->LINK = P;
    LAST       = P;
    P->LINK    = NULL;
}

void HAPUS_DEPAN() 
{
    if(FIRST == NULL) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    Simpul *temp = FIRST;
    FIRST = FIRST->LINK;
    if(FIRST == NULL) LAST = NULL; 
    free(temp);
}

void CETAK() 
{
    if(FIRST == NULL) {
        cout << "(Antrian Kosong)";
        return;
    }
    Q = FIRST;
    while(Q != NULL) {
        cout << "[" << Q->INFO << "]";
        if(Q->LINK != NULL) cout << " -> ";
        Q = Q->LINK;
    }
}