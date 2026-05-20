#include <iostream>
using namespace std;
 
struct Data {
    int n;
    int A[100];
};
 
void bubbleSort(Data &d) {
    int k = 0;
    int flag = 1;
 
    while (k <= d.n - 2 && flag == 1) {
        int i = 0;
        flag = 0;
 
        while (i <= d.n - 2 - k) {
            if (d.A[i] > d.A[i + 1]) {  
                flag = 1;
                int X   = d.A[i];
                d.A[i]  = d.A[i + 1];
                d.A[i + 1] = X;
            }
            i++;
        }
        k++;
    }
}
 
int main() {
    Data d;
 
    cout << "Masukkan jumlah elemen: ";
    cin >> d.n;
 
    cout << "Masukkan " << d.n << " bilangan : ";
    for (int i = 0; i < d.n; i++) {
        cout << "A[" << i << "] = ";
        cin >> d.A[i];
    }
 
    cout << "Data sebelum diurutkan : ";
    for (int i = 0; i < d.n; i++) {
        cout << d.A[i];
        if (i < d.n - 1) cout << ", ";
    }
    cout << endl;
 
    bubbleSort(d);
 
    cout << "Data setelah diurutkan : ";
    for (int i = 0; i < d.n; i++) {
        cout << d.A[i];
        if (i < d.n - 1) cout << ", ";
    }
    cout << endl;
 
    return 0;
}