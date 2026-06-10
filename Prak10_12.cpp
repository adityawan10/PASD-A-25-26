// Contoh : B-Tree Sisip - dengan data berupa KATA (string)
// Nama File : PASD10-02.cpp
// Berdasarkan contoh B-Tree dengan minimum degree t
 
#include<iostream>
#include<string>
using namespace std;
 
//Membuat Node
class BTreeNode {
    string *Kunci;
    int t, n;
    bool leaf;
    BTreeNode **C;
 
public:
    BTreeNode(int tt, bool _leaf);   // Konstruktor
    void SisipTdkPenuh(string k);
    void splitAnak(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(string k);
    friend class BTree;
};
 
//BTree
class BTree {
    int t;
    BTreeNode *root;
 
public:
    BTree(int tt)
    { root = NULL;  t = tt; }
    void traverse()
    { if (root != NULL) root->traverse(); }
 
    BTreeNode* search(string k)
    { return (root == NULL) ? NULL : root->search(k); }
    void Sisip(string k);
};
 
//Konstruktor untuk kelas BTreeNode
BTreeNode::BTreeNode(int t1, bool leaf1)  {
    t    = t1;
    leaf = leaf1;
    Kunci = new string[2*t-1];
    C     = new BTreeNode *[2*t];
    n = 0;
}
 
//Fungsi untuk melintasi semua node dalam subpohon yang di-root
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false) {
            C[i]->traverse();
            cout << " " << Kunci[i];
        }
        else
            cout << " " << Kunci[i];
    }
    if (leaf == false)
        C[i]->traverse();
}
 
//Fungsi untuk mencari kunci k pada subpohon yang di-root
BTreeNode* BTreeNode::search(string k) {
    int i = 0;
    while (i < n && k > Kunci[i])
        i++;
    if (Kunci[i] == k)
        return this;
    if (leaf == true)
        return NULL;
    return C[i]->search(k);
}
 
// Fungsi menyisipkan kunci baru di B-Tree
void BTree::Sisip(string k)  {
    if (root == NULL)   {
        root = new BTreeNode(t, true);
        root->Kunci[0] = k;   //Sisip
        root->n = 1;
    }
    else  {
        if (root->n == 2*t-1)   {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitAnak(0, root);
            int i = 0;
            if (s->Kunci[0] < k)
                i++;
            s->C[i]->SisipTdkPenuh(k);
            root = s;
        }
        else
            root->SisipTdkPenuh(k);
    }
}
 
//Fungsi sisip
void BTreeNode::SisipTdkPenuh(string k)  {
    int i = n-1;
    if (leaf == true)  {
        while (i >= 0 && Kunci[i] > k)  {
            Kunci[i+1] = Kunci[i];
            i--;
        }
        Kunci[i+1] = k;
        n = n+1;
    }
    else  {
        while (i >= 0 && Kunci[i] > k)
            i--;
 
        if (C[i+1]->n == 2*t-1)  {
            splitAnak(i+1, C[i+1]);
            if (Kunci[i+1] < k)
                i++;
        }
        C[i+1]->SisipTdkPenuh(k);
    }
}
 
//Fungsi Split Anak
void BTreeNode::splitAnak(int i, BTreeNode *y)  {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
 
    for (int j = 0; j < t-1; j++)
        z->Kunci[j] = y->Kunci[j+t];
    if (y->leaf == false)  {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }
    y->n = t - 1;
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];
    C[i+1] = z;
    for (int j = n-1; j >= i; j--)
        Kunci[j+1] = Kunci[j];
    Kunci[i] = y->Kunci[t-1];
    n = n + 1;
}
 
// ============================================================
int main() {
    // B-Tree with minimum degree 3
    BTree t(3);
 
    // Sisipkan beberapa kata (nama-nama)
    t.Sisip("Andi");
    t.Sisip("Budi");
    t.Sisip("Citra");
    t.Sisip("Dedi");
    t.Sisip("Eka");
    t.Sisip("Fajar");
    t.Sisip("Gita");
    t.Sisip("Hana");
    t.Sisip("Irfan");
    t.Sisip("Joko");
    t.Sisip("Kiki");
    t.Sisip("Lina");
    t.Sisip("Mira");
    t.Sisip("Nanda");
    t.Sisip("Omar");
 
    cout << "=================================================\n";
    cout << "         B-TREE DENGAN DATA BERUPA KATA\n";
    cout << "=================================================\n";
    cout << "\nTraversal B-Tree (urut alfabet) :\n";
    t.traverse();
    cout << "\n";
 
    // Pencarian kata
    string cari1 = "Gita";
    string cari2 = "Zara";
 
    cout << "\n-------------------------------------------------\n";
    cout << "Pencarian kata : \"" << cari1 << "\"  --> ";
    (t.search(cari1) != NULL)
        ? cout << "Ditemukan!" << endl
        : cout << "Tidak Ditemukan." << endl;
 
    cout << "Pencarian kata : \"" << cari2 << "\"  --> ";
    (t.search(cari2) != NULL)
        ? cout << "Ditemukan!" << endl
        : cout << "Tidak Ditemukan." << endl;
 
    cout << "-------------------------------------------------\n";
 
    return 0;
}