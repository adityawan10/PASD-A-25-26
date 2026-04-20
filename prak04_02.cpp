#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

struct Kasir {
    string ID ;
    char Nama ;
	double Total ;
};
struct Ksr;
struct biodata dataQueue[MAX];  
void init(void);
int full(void);
int empty(void);
struct biodata entridata(void);
void enqueue(struct biodata ksr);
struct biodata dequeue(void);
void display(struct biodata ksr);
void baca(void);
int awal, akhir;
char nocomment[10];

int main() {
    char pilih;
    cout << "== Program Entri Data Mahasiswa==\n";
    init();
    do {
        cout << "MENU PILIHAN :\n";
        cout << "1. ID Pelanggana\n";
        cout << "2. Nama Pelanggan\n";
        cout << "3. Total Belanja\n";
        cout << "4. Keluar.\n";
        cout << "Pilih menu : ";
        cin >> pilih;
        switch(pilih) {
            case '1' :  ksr = entridata(); enqueue(ksr); break;
            case '2' :  cout << "\nData Pelanggan : \n";
                        ksr = dequeue(); display(ksr); break;
            case '3' :  baca(); break;
            case '4' :  init(); cout << "\nSelesai\n";
                        break;
            default  :  cout << "Pilih 1 sd 4!";
                        break;        }
        cout << "\n";
    }while(pilih != '4');
    return 0; }

void init(void) {
    awal = -1;
    akhir = -1;
}

void enqueue(struct Kasir ksr) {
    if(empty() == true) {
        awal = 0;
        akhir = 0;
        dataQueue[awal] = ksr;  
    }else if(full() != true) {
        akhir++;
        dataQueue[akhir]=ksr;   
    }else cout << "Queue sudah penuh... \n";
}

struct Kasir dequeue(void) {
    int i;
    if(empty() != true) {
        ksr=dataQueue[awal];
        for(i=awal;i<=akhir;i++)
            dataQueue[i]=dataQueue[i+1];
        akhir--;
        return(ksr);
    }else {
        cout << "Queue Pelanggan ...\n";
        return(mhs);  
    }
}

int full(void) {
    if(akhir==MAX-1) return(true);
    else return(false);
}

int empty(void) {
    if(akhir == -1) return(true);
    else return(false);
}

void baca(void) {
    int i;
    cout << "\nIsi Queue : \n";
    if(empty() != true) {
        for(i=awal;i<=akhir;i++) {
            display(dataQueue[i]);  
        }
    }else cout << "Data kosong.";
    cout << "\n";
}

struct biodata entridata(void) {
    struct Kasir ksr;
    cout << "\n";
    cout << "Masukkan ID Pelanggan : ";cin >> ksr.ID \n;
    cout << "Masukkan Nama Pelanggan : ";cin >> ksr.Nama ;
    return(ksr);
}

void display(struct ksr) {
    cout << "\n";
    cout << "ID : " << ksr.ID  << "\n";
    cout << "Nama : " << ksr.Nama  << "\n";
}
