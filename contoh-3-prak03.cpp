#include <iostream>
using namespace std;

class Tas
{
	public:
	char Kode barang[9];
	char Nama[30];
	float ipk;
};
int main()
{
	Mahasiswa mhs;
	cout<<"Nomor Pokok Mahasiswa     = "; cin >> mhs.NPM;
	cout<<"Nama Mahasiswa            = "; cin >> mhs.Nama;
	cout<<"Indek Prestasi Konsulatif = "; cin >> mhs.ipk;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"         Data Anda          "<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Nomor Pokok Mahasiswa     = "<< mhs.NPM << endl; 
	cout<<"Nama Mahasiswa            = "<< mhs.Nama << endl;
	cout<<"Indek Prestasi Konsulatif = "<< mhs.ipk << endl;
	
	cin.get();
}