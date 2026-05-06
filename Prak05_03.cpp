#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 
struct NilaiMK {
    string npm;
    string nama_mhs;
    double nilai;
};
struct elemen {
    NilaiMK Kontainer;
    elemen* next;
};
class Queue {
private:
    elemen* first;
    elemen* last;
    int jumlah;
 
    elemen* createNode(string npm, string nama, double nilai) {
        elemen* node = new elemen;
        node->Kontainer.npm       = npm;
        node->Kontainer.nama_mhs  = nama;
        node->Kontainer.nilai     = nilai;
        node->next                = NULL;
        return node;
    }
 
public:
    Queue() {
        first  = NULL;
        last   = NULL;
        jumlah = 0;
    }
    ~Queue() {
        while (first != NULL) {
            elemen* hapus = first;
            first = first->next;
            delete hapus;
        }
    }
    bool isKosong() {
        return first == NULL;
    }
    int jmlElemen() {
        return jumlah;
    }
    void add(string npm, string nama, double nilai) {
        elemen* node = createNode(npm, nama, nilai);
        if (first == NULL) {
            first = node;
        } else {
            last->next = node;
        }
        last = node;
        jumlah++;
        cout << "  [OK] Data '" << nama << "' berhasil ditambahkan ke antrian." << endl;
    }
    void del() {
        if (first == NULL) {
            cout << "  [!] Queue kosong, tidak ada data yang dihapus." << endl;
            return;
        }
        elemen* hapus = first;
        cout << "  [OK] Data '" << hapus->Kontainer.nama_mhs << "' (NPM: "
             << hapus->Kontainer.npm << ") berhasil dihapus dari antrian." << endl;
 
        if (jumlah == 1) {
            first = NULL;
            last  = NULL;
        } else {
            first       = first->next;
            hapus->next = NULL;
        }
        delete hapus;
        jumlah--;
    }
    void cetakQueue() {
        if (first == NULL) {
            cout << "  Queue Kosong." << endl;
            return;
        }
        cout << endl;
        cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "              MENAMPILKAN ISI QUEUE                  " << endl;
        cout << "          Jumlah Elemen : " << setw(2) << jumlah
             << "                          " << endl;
        cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	    cout << "   |  NPM     |      Nama Mahasiswa      |   Nilai  |" << endl;
        cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
 
        elemen* bantu = first;
        int i = 1;
        while (bantu != NULL) {
            cout << "   " << setw(1) << i << "  "
                 << setw(12) << left  << bantu->Kontainer.npm      << "  "
                 << setw(20) << left  << bantu->Kontainer.nama_mhs << "  "
                 << setw(6)  << right << fixed << setprecision(2)
                 << bantu->Kontainer.nilai << " " << endl;
            bantu = bantu->next;
            i++;
        }
        cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
    }
    void peek() {
        if (first == NULL) {
            cout << "  [!] Queue kosong." << endl;
            return;
        }
        cout << "  [FRONT] NPM: " << first->Kontainer.npm
             << " | Nama: " << first->Kontainer.nama_mhs
             << " | Nilai: " << fixed << setprecision(2) << first->Kontainer.nilai << endl;
    }
};
void cetakMenu() {
    cout << endl;
    cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "         MENU QUEUE MAHASISWA         " << endl;
    cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "     1. Tambah Data (Enqueue / ADD)   " << endl;
    cout << "     2. Hapus Data  (Dequeue / DEL)   " << endl;
    cout << "     3. Tampilkan Queue               " << endl;
    cout << "     4. Lihat Antrian Terdepan        " << endl;
    cout << "     5. Cek Jumlah Elemen             " << endl;
    cout << "     0. Keluar                        " << endl;
    cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "  Pilihan : ";
}
 
double inputNilai() {
    double n;
    while (true) {
        cin >> n;
        if (cin.fail() || n < 0 || n > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  [!] Nilai harus antara 0 - 100. Masukkan lagi: ";
        } else {
            cin.ignore(1000, '\n');
            return n;
        }
    }
}
int main() {
    Queue Q;
    int pilihan;
    string npm, nama;
    double nilai;
 
    cout << endl;
    cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       PROGRAM QUEUE NILAI MAHASISWA (CLASS)        " << endl;
    cout << "           Algoritma dan Struktur Data              " << endl;
    cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
 
    // Input data awal
    cout << endl;
    cout << "  Masukkan data awal mahasiswa." << endl;
    cout << "  Ketik 'selesai' pada NPM untuk mengakhiri input." << endl;
    cout << endl;
 
    int urutan = 1;
    while (true) {
        cout << "  --- Data ke-" << urutan << " ---" << endl;
        cout << "  NPM          : ";
        getline(cin, npm);
 
        if (npm == "selesai" || npm == "SELESAI") break;
        if (npm.empty()) {
            cout << "  [!] NPM tidak boleh kosong." << endl;
            continue;
        }
 
        cout << "  Nama Mahasiswa : ";
        getline(cin, nama);
        if (nama.empty()) {
            cout << "  [!] Nama tidak boleh kosong." << endl;
            continue;
        }
 
        cout << "  Nilai (0-100)  : ";
        nilai = inputNilai();
 
        Q.add(npm, nama, nilai);
        urutan++;
        cout << endl;
    }
 
    cout << endl;
    cout << "  Data awal berhasil dimasukkan." << endl;
    Q.cetakQueue();
 
    // Loop menu
    do {
        cetakMenu();
        while (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  [!] Input tidak valid. Masukkan angka: ";
        }
        cin.ignore(1000, '\n');
        cout << endl;
 
        switch (pilihan) {
            case 1:
                cout << "  === TAMBAH DATA (ENQUEUE) ===" << endl;
                cout << "  NPM            : ";
                getline(cin, npm);
                cout << "  Nama Mahasiswa : ";
                getline(cin, nama);
                cout << "  Nilai (0-100)  : ";
                nilai = inputNilai();
                Q.add(npm, nama, nilai);
                Q.cetakQueue();
                break;
 
            case 2:
                cout << "  === HAPUS DATA (DEQUEUE) ===" << endl;
                Q.del();
                Q.cetakQueue();
                break;
 
            case 3:
                Q.cetakQueue();
                break;
 
            case 4:
                cout << "  === ELEMEN TERDEPAN ===" << endl;
                Q.peek();
                cout << endl;
                break;
 
            case 5:
                cout << "  Jumlah elemen dalam queue : " << Q.jmlElemen() << endl;
                cout << "  Status queue              : "
                     << (Q.isKosong() ? "KOSONG" : "TIDAK KOSONG") << endl;
                cout << endl;
                break;
 
            case 0:
                cout << "  Program selesai. Terima kasih!" << endl;
                cout << endl;
                break;
 
            default:
                cout << "  [!] Pilihan tidak valid, coba lagi." << endl;
        }
 
    } while (pilihan != 0);
 
    return 0;
}