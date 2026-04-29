#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaOS;
    Node* next;
};

void tampilkanAntrian(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "[" << temp->namaOS << "] ";
        temp = temp->next;
    }
    cout << endl;
}

void sisipSebelum(Node*& head, string target, string dataBaru) {
    if (head == nullptr) return;

    if (head->namaOS == target) {
        Node* baru = new Node();
        baru->namaOS = dataBaru;
        baru->next = head;
        head = baru;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->namaOS != target) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* baru = new Node();
        baru->namaOS = dataBaru;
        baru->next = temp->next;
        temp->next = baru;
    }
}

void sisipSetelah(Node* head, string target, string dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->namaOS != target) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        Node* baru = new Node();
        baru->namaOS = dataBaru;
        baru->next = temp->next;
        temp->next = baru;
    }
}

void sisipDiAkhir(Node*& head, string dataBaru) {
    Node* baru = new Node();
    baru->namaOS = dataBaru;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = baru;
}

int main() {
    Node* listOS = nullptr;
    sisipDiAkhir(listOS, "Maemo");
    sisipDiAkhir(listOS, "Symbian");
    sisipDiAkhir(listOS, "Mac");
    sisipDiAkhir(listOS, "Windows");
    sisipDiAkhir(listOS, "Iphone");

    cout << "Antrian Awal: " << endl;
    tampilkanAntrian(listOS);
    cout << "------------------------------------------" << endl;

    sisipSebelum(listOS, "Iphone", "Iphone 5");
    cout << "a. Setelah Iphone 5 masuk diatas Iphone:" << endl;
    tampilkanAntrian(listOS);

    sisipSebelum(listOS, "Windows", "Windows Phone");
    cout << "b. Setelah Windows Phone masuk diatas Windows:" << endl;
    tampilkanAntrian(listOS);

    sisipSetelah(listOS, "Mac", "SnowLeopard");
    cout << "c. Setelah SnowLeopard masuk setelah Mac:" << endl;
    tampilkanAntrian(listOS);

    sisipSetelah(listOS, "Symbian", "Symbian Belle");
    cout << "d. Setelah Symbian Belle masuk setelah Symbian:" << endl;
    tampilkanAntrian(listOS);

    sisipDiAkhir(listOS, "Maemo 4");
    cout << "e. Setelah Maemo 4 masuk di paling bawah:" << endl;
    tampilkanAntrian(listOS);

    return 0;
}
