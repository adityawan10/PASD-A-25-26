#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;
Node* createNode(string val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertTail(string val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
Node* findNode(string val) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == val) return curr;
        curr = curr->next;
    }
    return NULL;
}

void deleteNode(string val) {
    Node* target = findNode(val);
    if (target == NULL) {
        cout << "  Node '" << val << "' tidak ditemukan, tidak bisa dihapus!" << endl;
        return;
    }
    if (target->prev != NULL)
        target->prev->next = target->next;
    else
        head = target->next; 
    if (target->next != NULL)
        target->next->prev = target->prev;
    else
        tail = target->prev;
    cout << "  Node '" << val << "' berhasil dihapus." << endl;
    delete target;
}

void insertAfter(string target, string val) {
    Node* targetNode = findNode(target);
    if (targetNode == NULL) {
        cout << "  Node '" << target << "' tidak ditemukan!" << endl;
        return;
    }
    Node* newNode = createNode(val);
    Node* nextNode = targetNode->next;

    newNode->prev = targetNode;
    newNode->next = nextNode;
    targetNode->next = newNode;

    if (nextNode != NULL)
        nextNode->prev = newNode;
    else
        tail = newNode;

    cout << "  Node '" << val << "' berhasil ditambahkan setelah '" << target << "'." << endl;
}

void insertAtTail(string val) {
    insertTail(val);
    cout << "  Node '" << val << "' berhasil ditambahkan di paling bawah (tail)." << endl;
}

void tampilkan() {
    cout << "Antrian: ";
    Node* curr = head;
    while (curr != NULL) {
        cout << "[" << curr->data << "]";
        if (curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
}

void resetList() {
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = NULL;
}

int main() {
    cout << "=== SOAL 6: Double Linked List - Insert dengan Menghapus Node ===" << endl;
    cout << endl;
    insertTail("Maemo");
    insertTail("Symbian");
    insertTail("Mac");
    insertTail("Windows");
    insertTail("Iphone");

    cout << "Antrian awal:" << endl;
    tampilkan();
    cout << endl;
    cout << "a. Tambah 'Maemo 4' paling bawah dengan menghapus 'Mac':" << endl;
    deleteNode("Mac");
    insertAtTail("Maemo 4");
    tampilkan();
    cout << endl;
    resetList();
    insertTail("Maemo"); insertTail("Symbian"); insertTail("Mac");
    insertTail("Windows"); insertTail("Iphone");
    cout << "--- Reset ke antrian awal ---" << endl;
    tampilkan();
    cout << endl;
    cout << "b. Tambah 'Windows Mobile' dibawah 'Windows' dengan menghapus 'Iphone':" << endl;
    deleteNode("Iphone");
    insertAfter("Windows", "Windows Mobile");
    tampilkan();
    cout << endl;
    resetList();
    insertTail("Maemo"); insertTail("Symbian"); insertTail("Mac");
    insertTail("Windows"); insertTail("Iphone");
    cout << "--- Reset ke antrian awal ---" << endl;
    tampilkan();
    cout << endl;
    cout << "c. Tambah 'Java Midlet' dibawah 'Symbian' dengan menghapus 'Maemo':" << endl;
    deleteNode("Maemo");
    insertAfter("Symbian", "Java Midlet");
    tampilkan();
    cout << endl;
    resetList();
    insertTail("Maemo"); insertTail("Symbian"); insertTail("Mac");
    insertTail("Windows"); insertTail("Iphone");
    cout << "--- Reset ke antrian awal ---" << endl;
    tampilkan();
    cout << endl;
    cout << "d. Tambah 'Lion OS X' dibawah 'Mac' dengan menghapus 'Maemo':" << endl;
    deleteNode("Maemo");
    insertAfter("Mac", "Lion OS X");
    tampilkan();
    cout << endl;
    resetList();
    insertTail("Maemo"); insertTail("Symbian"); insertTail("Mac");
    insertTail("Windows"); insertTail("Iphone");
    cout << "--- Reset ke antrian awal ---" << endl;
    tampilkan();
    cout << endl;
    cout << "e. Tambah 'Android' dibawah 'Iphone' dengan menghapus 'Maemo':" << endl;
    deleteNode("Maemo");
    insertAfter("Iphone", "Android");
    tampilkan();
    cout << endl;

    return 0;
}
