#include <iostream>
#include <string>
using namespace std;

struct NODE {
    string INFO;
    NODE*  LEFT;
    NODE*  RIGHT;
};
 
struct TREE {
    NODE* root;
};

NODE* buatNode(string data) {
    NODE* n  = new NODE;
    n->INFO  = data;
    n->LEFT  = NULL;
    n->RIGHT = NULL;
    return n;
}
 
void inisialisasi(TREE &T) {
    T.root = NULL;
}
 
void preOrder(NODE* root) {
    if (root != NULL) {
        cout << "    " << root->INFO << endl;
        preOrder(root->LEFT);
        preOrder(root->RIGHT);
    }
}
 
void inOrder(NODE* root) {
    if (root != NULL) {
        inOrder(root->LEFT);
        cout << "    " << root->INFO << endl;
        inOrder(root->RIGHT);
    }
}
 
void postOrder(NODE* root) {
    if (root != NULL) {
        postOrder(root->LEFT);
        postOrder(root->RIGHT);
        cout << "    " << root->INFO << endl;
    }
}
 
void tampilkanSemua(TREE &T) {
    cout << "  --------------------------------" << endl;
    cout << "  PreOrder   : " << endl;
    preOrder(T.root);
    cout << "  --------------------------------" << endl;
    cout << "  InOrder    : " << endl;
    inOrder(T.root);
    cout << "  --------------------------------" << endl;
    cout << "  PostOrder  : " << endl;
    postOrder(T.root);
    cout << "  --------------------------------" << endl;
}
 
NODE* cariNode(NODE* root, string target) {
    if (root == NULL) return NULL;
    if (root->INFO == target) return root;
    NODE* hasil = cariNode(root->LEFT, target);
    if (hasil != NULL) return hasil;
    return cariNode(root->RIGHT, target);
}
 
void gantiNode(NODE* root, string lama, string baru) {
    NODE* target = cariNode(root, lama);
    if (target != NULL) {
        cout << "  >> Menghapus \"" << lama
             << "\" dan memasukkan \"" << baru << "\"" << endl;
        target->INFO = baru;
    } else {
        cout << "  >> Node \"" << lama << "\" tidak ditemukan!" << endl;
    }
}

void bangunTreeAwal(TREE &T) {
    T.root              = buatNode("Maemo");
    T.root->LEFT        = buatNode("Symbian");
    T.root->RIGHT       = buatNode("Mac");
    T.root->LEFT->LEFT  = buatNode("Windows");
    T.root->LEFT->RIGHT = buatNode("Iphone");
    T.root->RIGHT->LEFT = buatNode("IOS");
}
 
void resetTree(TREE &T) {
    inisialisasi(T);
    bangunTreeAwal(T);
}
 
void soalA(TREE &T) {
    cout << "============================================" << endl;
    cout << "  [SOAL A]" << endl;
    cout << "  Menambahkan \"Maemo 4\" paling akhir" << endl;
    cout << "  dengan menghapus \"Mac\"" << endl;
    cout << "============================================" << endl;
    gantiNode(T.root, "Mac", "Maemo 4");
    NODE* nodeIOS = cariNode(T.root, "IOS");
    if (nodeIOS != NULL) {
        nodeIOS->RIGHT = buatNode("Maemo 4");
        cout << "  >> Menambahkan node baru \"Maemo 4\" sebagai"
             << " child kanan IOS (posisi paling akhir)" << endl;
    }
 
    tampilkanSemua(T);
}
 
void soalB(TREE &T) {
    cout << "============================================" << endl;
    cout << "  [SOAL B]" << endl;
    cout << "  Menambahkan \"Windows Mobile\" di bawah \"Windows\"" << endl;
    cout << "  dengan menghapus \"Iphone\"" << endl;
    cout << "============================================" << endl;
    NODE* nodeSymbian = cariNode(T.root, "Symbian");
    NODE* nodeWindows = cariNode(T.root, "Windows");
    if (nodeSymbian == NULL || nodeWindows == NULL) {
        cout << "  >> Error: node tidak ditemukan!" << endl;
        return;
    }
    NODE* nodeIphone = nodeSymbian->RIGHT;   
    nodeSymbian->RIGHT = NULL;               
    if (nodeIphone != NULL) {
        cout << "  >> Menghapus \"Iphone\" dan memasukkan \"Windows Mobile\"" << endl;
        nodeIphone->INFO  = "Windows Mobile";
        nodeIphone->LEFT  = NULL;
        nodeIphone->RIGHT = NULL;
        cout << "  >> \"Windows Mobile\" dipindah sebagai child kiri \"Windows\"" << endl;
    }
    tampilkanSemua(T);
}

void soalC(TREE &T) {
    cout << "============================================" << endl;
    cout << "  [SOAL C]" << endl;
    cout << "  Menambahkan \"Java Midlet\" setelah \"Symbian\"" << endl;
    cout << "  dengan menghapus \"Maemo\"" << endl;
    cout << "============================================" << endl;
 
    NODE* oldRoot = T.root;              
    NODE* nodeSymbian = oldRoot->LEFT;   
    NODE* nodeMac     = oldRoot->RIGHT;  
    if (nodeSymbian == NULL) {
        cout << "  >> Error: Symbian tidak ditemukan!" << endl;
        return;
    }
    cout << "  >> Menghapus \"Maemo\" dan memasukkan \"Java Midlet\"" << endl;
    cout << "  >> \"Symbian\" naik menjadi root baru" << endl;
    T.root = nodeSymbian;
    oldRoot->INFO  = "Java Midlet";
    oldRoot->LEFT  = nodeSymbian->RIGHT; 
    oldRoot->RIGHT = nodeMac;           
    nodeSymbian->RIGHT = oldRoot;
    cout << "  >> \"Java Midlet\" ditempatkan sebagai child kanan \"Symbian\"" << endl;
    tampilkanSemua(T);
}
void soalD(TREE &T) {
    cout << "============================================" << endl;
    cout << "  [SOAL D]" << endl;
    cout << "  Menambahkan \"Lion OS X\" setelah \"Mac\"" << endl;
    cout << "  dengan menghapus \"Maemo\"" << endl;
    cout << "============================================" << endl;
    NODE* nodeMac     = cariNode(T.root, "Mac");
    NODE* nodeIOS     = cariNode(T.root, "IOS");
    NODE* nodeSymbian = T.root->LEFT; 
    if (nodeMac == NULL) {
        cout << "  >> Error: Mac tidak ditemukan!" << endl;
        return;
    }
    nodeMac->RIGHT = buatNode("Lion OS X");
    cout << "  >> Menambahkan \"Lion OS X\" sebagai child kanan \"Mac\"" << endl;
    cout << "  >> Menghapus \"Maemo\", \"Mac\" naik menjadi root baru" << endl;
    NODE* oldRoot = T.root;
    T.root = nodeMac;
    if (nodeIOS != NULL) {
        nodeIOS->LEFT = nodeSymbian;
        cout << "  >> \"Symbian\" (subtree kiri) disambung ke bawah \"IOS\"" << endl;
    }
    delete oldRoot;  
 
    tampilkanSemua(T);
}
void soalE(TREE &T) {
    cout << "============================================" << endl;
    cout << "  [SOAL E]" << endl;
    cout << "  Menambahkan \"Android\" setelah \"Iphone\"" << endl;
    cout << "  dengan menghapus \"Maemo\"" << endl;
    cout << "============================================" << endl;
 
    NODE* nodeIphone  = cariNode(T.root, "Iphone");
    NODE* nodeSymbian = T.root->LEFT;    
    NODE* nodeMac     = T.root->RIGHT;   
    if (nodeIphone == NULL) {
        cout << "  >> Error: Iphone tidak ditemukan!" << endl;
        return;
    }
    nodeIphone->RIGHT = buatNode("Android");
    cout << "  >> Menambahkan \"Android\" sebagai child kanan \"Iphone\"" << endl;
    cout << "  >> Menghapus \"Maemo\", \"Symbian\" naik menjadi root baru" << endl;
    NODE* oldRoot = T.root;
    T.root = nodeSymbian;
    nodeIphone->LEFT = nodeMac;
    cout << "  >> \"Mac\" (subtree kanan) disambung sebagai child kiri \"Iphone\"" << endl;
	
    delete oldRoot;  
 
    tampilkanSemua(T);
}
 
int main() {
    TREE T;
 
    cout << "============================================" << endl;
    cout << "  BINARY TREE - String Data                " << endl;
    cout << "  Maemo, Symbian, Mac, Windows, Iphone, IOS" << endl;
    cout << "============================================" << endl;
 
    inisialisasi(T);
    bangunTreeAwal(T);
    cout << "\n[TREE AWAL]" << endl;
    tampilkanSemua(T);
 
    resetTree(T);
    soalA(T);
 
    resetTree(T);
    soalB(T);

    resetTree(T);
    soalC(T);
 
    resetTree(T);
    soalD(T);
 
    resetTree(T);
    soalE(T);
 
    return 0;
}