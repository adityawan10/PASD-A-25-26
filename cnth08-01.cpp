#include<iostream>
using namespace std;

int Search01(int A[], int, int);
int pilihmenu;
int SearchElemen = 0;
int flaq = 0;
int tika[100]; 
int main()
{
    int JmlElemenArray;
    cout << "****************************************" << endl;
    cout << "** N O M O R --- K E N D A R A AN **" << endl;
    cout << "****************************************" << endl;
   do{
	   cout << "***   Pilih Menu   ***" << endl;
	   cout << " 1. Input Data Kendaraan " << endl;
	   cout << " 2. Cari Kendaraan " << endl;
	   cout << " 3. Keluar " << endl;
	   cout << endl;
	   cout << " Masukkan Pilihan Anda " << endl;
	   cin >> pilihmenu ;
   switch(pilihmenu) {
	   case 1 :  cout << "Masukkan jumlah kendaraan : ";
		cin >> JmlElemenArray;
		while (JmlElemenArray <= 0) {
			cout << "Jumlah kendaraan harus lebih dari 0. Masukkan ulang : ";
			cin >> JmlElemenArray;
		}
		cout << "Masukkan nomor kendaraan :" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		for (int count = 0; count < JmlElemenArray; count++)
		{
			cout << "nomor kendaraan [" << count << "] --> ";
			cin >> tika[count];
		}
		cout << "****************************************" << endl;
		cout << "Isi nomor kendaraan yang telah dimasukkan :" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		for (int count = 0; count < JmlElemenArray; count++)
		{
			cout << "\t" << "Nomor Kendaraan [" << count << "] --> " << tika[count] << endl;
		} break;
	   case 2:
		cout << "****************************************" << endl;
		cout << "Masukkan nomor kendaraan yang akan Anda cari ? "; 
		cin >> SearchElemen;
		flaq = Search01(tika, JmlElemenArray, SearchElemen);
		if (flaq != -1)
			cout << "Nomor knedaraan yang dicari ditemukan pada posisi : Nomor Kendaraan[" << flaq << "]" << endl;
		else
			cout << "Nomor kendaraan yang Anda cari tidak ditemukan" << endl;
		break;
	   case 3:
	   break;
	   default:cout<<"pilihmenu 1-3"<<endl;
	   break;
   }
   
   }while(pilihmenu != 3);
    cout << "****************************************" << endl;
    cin.ignore();
    cin.get();
    return 0;
}
int Search01(int tika[], int JmlElemenArray, int Elemen)
{
    int flaq = -1;
    for (int count = 0; count < JmlElemenArray; count++)
    {
        if (Elemen == tika[count])
        {
            flaq = count;
            break;
        }
    }
    return flaq;
}