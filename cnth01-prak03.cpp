#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
	string npm;
	string nama_mhs;
	double nilai;
}
NilaiMK;

typedef struct {
	int top;
	NilaiMK Dat[10];
}   stack;

void buatSTkosong (stack *S) {
	(*S).top = -1;
}
bool isKosong(stack S) {
	bool hasil = false;

return hasil;
}
bool isPenuh(stack S) {
	bool hasil = false;
	
	if(S.top == 5) {
		hasil = true;
	}
	return hasil;
}

void push(string npm, string nama_mhs, double nilai, stack *S)
{
	if(isPenuh(*S) == 1) {
		cout << "Stack penuh" <<endl;
	}
	else{
		if(isKosong(*S) == 1) {
			(*S).top = 0;
			(*S).Dat[0].npm =npm;
			(*S).Dat[0].nama_mhs = nama_mhs;
			(*S).Dat[0].nilai = nilai;
		}
		else{
		(*S).top = (*S).top + 1;
		(*S).Dat[(*S).top].npm =npm;
		(*S).Dat[(*S).top].nama_mhs = nama_mhs;
		(*S).Dat[(*S).top].nilai = nilai;
		}
	}
}
void Pop(stack *S) {
	if((*S).top == 0) {
		(*S).top = -1;
	}
	else{
		if((*S).top != -1) {
			(*S).top = (*S).top - 1;
		}
	}
}
void CetakStack(stack S)
{
	if(S.top != -1)
	{
		cout <<" Menampilkan stack " << endl;
		int i;
		for(i=S.top; i>=0; i--)
		{
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Elemen ke                 : "<< i << endl;
			cout<<"Nomor Pokok Mahasiswa     : "<< S.Dat[i].npm <<endl;
			cout<<"Nama Mahasiswa            : "<< S.Dat[i].nama_mhs << endl;
			cout<<"Nilai Mahasiswa           : "<< S.Dat[i].nilai << endl;
			cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}
	}
	else
	{
		cout << "Stack Kosong " << endl;
	}
}
int main()
{
	stack S;
	
	buatSTkosong(&S);
	CetakStack(S);
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	push("4523210666", "Budi", 88.75, &S);
	push("4523210777", "Susi", 78.85, &S);
	push("4523210888", "Sari", 98.65, &S);
	push("4523210999", "Bimo", 68.55, &S);
	CetakStack(S);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<endl;
	cout<<endl;
	Pop(&S);
	CetakStack(S);
	cout<<endl;
	cout<<endl;
    Pop(&S);
	CetakStack(S);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	return 0;
}


			