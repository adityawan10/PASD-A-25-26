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
 
void insertBefore(string target, string val) {
    Node* targetNode = findNode(target);
    if (targetNode == NULL) {
        cout << "Node '" << target << "' tidak ditemukan!" << endl;
        return;
    }
    Node* newNode = createNode(val);
    Node* prevNode = targetNode->prev;
 
    newNode->next = targetNode;
    newNode->prev = prevNode;
    targetNode->prev = newNode;
 
    if (prevNode != NULL)
        prevNode->next = newNode;
    else
        head = newNode; 
}

void insertAfter(string target, string val) {
    Node* targetNode = findNode(target);
    if (targetNode == NULL) {
        cout << "Node '" << target << "' tidak ditemukan!" << endl;
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
}
 
void insertAtTail(string val) {
    insertTail(val);
}
 
void tampilkan() {
    cout << "Isi antrian: ";
    Node* curr = head;
    while (curr != NULL) {
        cout << "[" << curr->data << "]";
        if (curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
}
 
int main() {
    insertTail("Maemo");
    insertTail("Symbian");
    insertTail("Mac");
    insertTail("Windows");
    insertTail("Iphone");
 
    cout << "=== SOAL 5: Double Linked List - Insert di Berbagai Posisi ===" << endl;
    cout << endl;
    cout << "Antrian awal:" << endl;
    tampilkan();
    cout << endl;
 
    cout << "a. Menambahkan 'Iphone 5' diatas 'Iphone':" << endl;
    insertBefore("Iphone", "Iphone 5");
    tampilkan();
    cout << endl;
 
    cout << "b. Menambahkan 'Windows Phone' diatas 'Windows':" << endl;
    insertBefore("Windows", "Windows Phone");
    tampilkan();
    cout << endl;
 
    cout << "c. Menambahkan 'SnowLeopard' setelah 'Mac':" << endl;
    insertAfter("Mac", "SnowLeopard");
    tampilkan();
    cout << endl;
 
    cout << "d. Menambahkan 'Symbian Belle' setelah 'Symbian':" << endl;
    insertAfter("Symbian", "Symbian Belle");
    tampilkan();
    cout << endl;
 
    cout << "e. Menambahkan 'Maemo 4' paling bawah (tail):" << endl;
    insertAtTail("Maemo 4");
    tampilkan();
    cout << endl;
 
    return 0;
}