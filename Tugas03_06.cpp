#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string data;
    Node* next;
};

void cetakAntrian(Node* head) {
    if (!head) {
        cout << "Antrian Kosong" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << "[" << temp->data << "] ";
        if (temp->next) cout << "-> ";
        temp = temp->next;
    }
    cout << endl << "---------------------------------------------------" << endl;
}

void hapusNode(Node*& head, string target) {
    if (head == NULL) return;

    if (head->data == target) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
    }
}
void tambahSetelah(Node* head, string target, string dataBaru) {
    Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* baru = new Node();
        baru->data = dataBaru;
        baru->next = temp->next;
        temp->next = baru;
    }
}

void tambahBelakang(Node*& head, string dataBaru) {
    Node* baru = new Node();
    baru->data = dataBaru;
    baru->next = NULL;
    if (head == NULL) {
        head = baru;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = baru;
}

int main() {
    Node* antrian = NULL;
    string awal[] = {"Maemo", "Symbian", "Mac", "Windows", "Iphone"};
    for (string s : awal) tambahBelakang(antrian, s);
    cout << "Kondisi Awal:" << endl;
    cetakAntrian(antrian);
    hapusNode(antrian, "Mac");
    tambahBelakang(antrian, "Maemo 4");
    cout << "a. Hapus Mac, Tambah Maemo 4 di akhir:" << endl;
    cetakAntrian(antrian);
    hapusNode(antrian, "Iphone");
    tambahSetelah(antrian, "Windows", "Windows Mobile");
    cout << "b. Hapus Iphone, Tambah Windows Mobile di bawah Windows:" << endl;
    cetakAntrian(antrian);
    hapusNode(antrian, "Maemo");
    tambahSetelah(antrian, "Symbian", "Java Midlet");
    cout << "c. Hapus Maemo, Tambah Java Midlet di bawah Symbian:" << endl;
    cetakAntrian(antrian);
    tambahSetelah(antrian, "Mac", "Lion OS X"); 
    cout << "d. Tambah Lion OS X di bawah Mac (Mac sudah tidak ada di list):" << endl;
    cetakAntrian(antrian);
    tambahSetelah(antrian, "Iphone", "Android");
    cout << "e. Tambah Android di bawah Iphone (Iphone sudah tidak ada di list):" << endl;
    cetakAntrian(antrian);

    return 0;
}