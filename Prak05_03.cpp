#include <iostream>
#include <string>
using namespace std;
 
struct NilaiMK {
    string npm;
    string nama_mhs;
    double nilai;
};
 
struct elemen {
    NilaiMK Kontainer;
    elemen *next;
};
 
class Queue {
private:
    elemen *first;
    elemen *last;
 
public:
    Queue() {
        first = NULL;
        last  = NULL;
    }
    bool isKosong() {
        return (first == NULL);
    }
    int jmlElemen() {
        int hasil = 0;
        if (first != NULL) {
            elemen *bantu = first;
            while (bantu != NULL) {
                hasil = hasil + 1;
                bantu = bantu->next;
            }
        }
        return hasil;
    }
    void add(string npm, string nama_mhs, double nilai) {
        elemen *info = new elemen;
        info->Kontainer.npm       = npm;
        info->Kontainer.nama_mhs  = nama_mhs;
        info->Kontainer.nilai     = nilai;
        info->next                = NULL;
 
        if (first == NULL) {
            first = info;
        } else {
            last->next = info;
        }
        last = info;
        info = NULL;
    }
    void del() {
        if (first != NULL) {
            elemen *hapus = first;
 
            if (jmlElemen() == 1) {
                first = NULL;
                last  = NULL;
            } else {
                first        = first->next;
                hapus->next  = NULL;
            }
            delete hapus;
        }
    }
    void CetakQueue() {
        if (first != NULL) {
            cout << "MENAMPILKAN QUEUE" << endl;
            elemen *bantu = first;
            int i = 1;
            while (bantu != NULL) {
                cout << "--------------------------------------------" << endl;
                cout << "Elemen ke   : " << i << " / " << jmlElemen() << endl;
                cout << "NPM         : " << bantu->Kontainer.npm       << endl;
                cout << "Nama Mahasiswa  : " << bantu->Kontainer.nama_mhs  << endl;
                cout << "Nilai Mahasiswa : " << bantu->Kontainer.nilai      << endl;
                bantu = bantu->next;
                i     = i + 1;
            }
            cout << "--------------------------------------------" << endl;
        } else {
            cout << "Queue Kosong" << endl;
        }
    }
    void inputData() {
        string npm, nama;
        double nilai;
        cout << "Masukkan NPM       : ";
        cin >> npm;
        cin.ignore();
        cout << "Masukkan Nama MHS  : ";
        getline(cin, nama);
        cout << "Masukkan Nilai     : ";
        cin >> nilai;
        add(npm, nama, nilai);
        cout << "Data berhasil ditambahkan ke queue." << endl;
    }
};
int main() {
    Queue Q;
    int pilihan;
 
    do {
        cout << "\n========== MENU QUEUE NILAI MK ==========" << endl;
        cout << "1. Tambah Data (Enqueue)" << endl;
        cout << "2. Hapus Data  (Dequeue)" << endl;
        cout << "3. Tampilkan Queue" << endl;
        cout << "4. Cek Queue Kosong" << endl;
        cout << "5. Jumlah Elemen" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
 
        switch (pilihan) {
            case 1:
                Q.inputData();
                break;
            case 2:
                Q.del();
                cout << "Elemen pertama telah dihapus." << endl;
                break;
            case 3:
                cout << endl;
                Q.CetakQueue();
                break;
            case 4:
                if (Q.isKosong())
                    cout << "Queue KOSONG." << endl;
                else
                    cout << "Queue TIDAK kosong." << endl;
                break;
            case 5:
                cout << "Jumlah elemen : " << Q.jmlElemen() << endl;
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
 
    return 0;
}