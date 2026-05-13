#include <iostream>
#include <string>
using namespace std;

struct elemen {
    string data;
    elemen *next;
};
struct queue {
    elemen *first;  
    elemen *last;   
};
void buatQKosong(queue *Q) {
    Q->first = NULL;
    Q->last  = NULL;
}
bool isKosong(queue Q) {
    return (Q.first == NULL);
}
int jmlElemen(queue Q) {
    int hasil = 0;
    elemen *bantu = Q.first;
    while (bantu != NULL) {
        hasil++;
        bantu = bantu->next;
    }
    return hasil;
}
void enqueue(queue *Q, string val) {
    elemen *info  = new elemen;
    info->data    = val;
    info->next    = NULL;
 
    if (Q->first == NULL) {
        Q->first = info;
    } else {
        Q->last->next = info;
    }
    Q->last = info;
}
void dequeue(queue *Q) {
    if (Q->first != NULL) {
        elemen *hapus = Q->first;
        if (jmlElemen(*Q) == 1) {
            Q->first = NULL;
            Q->last  = NULL;
        } else {
            Q->first       = Q->first->next;
            hapus->next    = NULL;
        }
        cout << "  >> Elemen \"" << hapus->data << "\" dikeluarkan dari queue." << endl;
        delete hapus;
    } else {
        cout << "  >> Queue kosong, tidak ada yang dihapus." << endl;
    }
}
void insertAfter(queue *Q, string target, string val) {
    if (isKosong(*Q)) {
        cout << "  >> Queue kosong!" << endl;
        return;
    }
    elemen *bantu = Q->first;
    while (bantu != NULL && bantu->data != target) {
        bantu = bantu->next;
    }
    if (bantu == NULL) {
        cout << "  >> Elemen \"" << target << "\" tidak ditemukan!" << endl;
        return;
    }
    elemen *info = new elemen;
    info->data   = val;
    info->next   = bantu->next;
    bantu->next  = info;
    if (info->next == NULL) {
        Q->last = info;
    }
    cout << "  >> Elemen \"" << val << "\" disisipkan setelah \"" << target << "\"." << endl;
}
void cetakQueue(queue Q) {
    if (isKosong(Q)) {
        cout << "  [ Queue Kosong ]" << endl;
        return;
    }
    cout << "  FRONT -> ";
    elemen *bantu = Q.first;
    while (bantu != NULL) {
        cout << "[ " << bantu->data << " ]";
        if (bantu->next != NULL) cout << " -> ";
        bantu = bantu->next;
    }
    cout << " <- REAR" << endl;
    cout << "  Jumlah elemen : " << jmlElemen(Q) << endl;
}
int main() {
    queue Q;
    buatQKosong(&Q);
    cout << "========================================================" << endl;
    cout << "        PROGRAM QUEUE LINKED LIST - PASD5-4"             << endl;
    cout << "========================================================" << endl;
    cout << "\n[INISIALISASI] Memasukkan A, B, C ke dalam queue..." << endl;
    enqueue(&Q, "A");
    enqueue(&Q, "B");
    enqueue(&Q, "C");
    cout << "  Kondisi awal queue:" << endl;
    cetakQueue(Q);
    cout << "\n--------------------------------------------------------" << endl;
    cout << "  (a) Memasukkan D setelah A" << endl;
    cout << "--------------------------------------------------------" << endl;
    insertAfter(&Q, "A", "D");
    cout << "  Kondisi queue setelah operasi (a):" << endl;
    cetakQueue(Q);
    cout << "\n--------------------------------------------------------" << endl;
    cout << "  (b) Memasukkan F paling akhir, A B C hilang" << endl;
    cout << "--------------------------------------------------------" << endl;
    buatQKosong(&Q);
    enqueue(&Q, "A");
    enqueue(&Q, "B");
    enqueue(&Q, "C");
    cout << "  Reset queue ke kondisi awal [A, B, C]:" << endl;
    cetakQueue(Q);
    cout << "  Menghapus A, B, C dari queue..." << endl;
    dequeue(&Q); 
    dequeue(&Q); 
    dequeue(&Q); 
    cout << "  Memasukkan F ke queue..." << endl;
    enqueue(&Q, "F");
    cout << "  Kondisi queue setelah operasi (b):" << endl;
    cetakQueue(Q);
    cout << "\n--------------------------------------------------------" << endl;
    cout << "  (c) Memasukkan F paling akhir, A B C hilang (ulang)" << endl;
    cout << "--------------------------------------------------------" << endl;
    buatQKosong(&Q);
    enqueue(&Q, "A");
    enqueue(&Q, "B");
    enqueue(&Q, "C");
    cout << "  Reset queue ke kondisi awal [A, B, C]:" << endl;
    cetakQueue(Q);
    cout << "  Dequeue A, lalu B, lalu C, kemudian Enqueue F..." << endl;
    dequeue(&Q);
    cetakQueue(Q);
    dequeue(&Q); 
    cetakQueue(Q);
    dequeue(&Q); 
    cetakQueue(Q);
    enqueue(&Q, "F");
    cout << "  Kondisi queue setelah operasi (c):" << endl;
    cetakQueue(Q);
    cout << "\n--------------------------------------------------------" << endl;
    cout << "  (d) Memasukkan E setelah B" << endl;
    cout << "--------------------------------------------------------" << endl;
    buatQKosong(&Q);
    enqueue(&Q, "A");
    enqueue(&Q, "B");
    enqueue(&Q, "C");
    cout << "  Reset queue ke kondisi awal [A, B, C]:" << endl;
    cetakQueue(Q);
    insertAfter(&Q, "B", "E");
    cout << "  Kondisi queue setelah operasi (d):" << endl;
    cetakQueue(Q);
    cout << "\n========================================================" << endl;
    cout << "                    SELESAI"                               << endl;
    cout << "========================================================" << endl;
 
    return 0;
}