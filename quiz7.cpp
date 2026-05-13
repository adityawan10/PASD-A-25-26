#include <iostream>
using namespace std;
 
class BubbleSort {
private:
    int arr[10];
    int n;
 
    void tukar(int a, int b) {
        int t;
        t = arr[b];
        arr[b] = arr[a];
        arr[a] = t;
    }
 
public:
    void Input() {
        cout << "Masukkan jumlah data = ";
        cin >> n;
        cout << "------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Masukkan data ke-" << (i + 1) << " = ";
            cin >> arr[i];
        }
        cout << endl;
    }
 
    void Tampil() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
 
    void bubble_sort() {
        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                if (arr[j] < arr[j - 1])    
                    tukar(j, j - 1);
            }
            Tampil();
        }
        cout << endl;
    }
};
 
int main() {
    BubbleSort bs;
 
    cout << "----------------------------------" << endl;
    cout << "* Selamat datang di aplikasi      *" << endl;
    cout << "*         Bubble Sort             *" << endl;
    cout << "----------------------------------" << endl;
 
    bs.Input();
 
    cout << "Proses Bubble Sort (Ascending)....." << endl;
    cout << "------------------------------------" << endl;
    bs.Tampil();
    bs.bubble_sort();
 
    cout << "------------------------------------" << endl;
    cout << "          TERIMA KASIH             " << endl;
    cout << "------------------------------------" << endl;
    cin.get();
 
    return 0;
}