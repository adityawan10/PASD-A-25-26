#include <iostream>
#include <string.h>
using namespace std;

typedef struct
{
	string KodeBuku;
	string JudulBuku;
	string Pengarang;
}	DataBuku;

typedef struct elm *alamatelm;
typedef struct elm 
{
	DataBuku Kontainer;
	alamatelm next;
}	elemen;

typedef struct
{
	elemen* top;
}	stack;

void buatSTkosong(stack *S) {
	(*S).top = NULL;
}

int isKosong(stack S)
{
	bool hasil = false;
	if(S.top == NULL) 
	{
		hasil = true;
	}
	return hasil;
}

int jmlElemen (stack S)
{
	int hasil = 0;
	if(S.top != NULL)
	{
		elemen *bantu;
		bantu = S.top;
		while(bantu != NULL)
		{
			hasil = hasil + 1;
			bantu = bantu -> next;
		}
	}
	return hasil;
}
void push(string npm, string nama_mhs, double nilai, stack *S)
{
	elemen *info;
	info = new elemen;
	info -> Kontainer.KodeBuku = KodeBuku;
	info -> Kontainer.JudulBuku = JudulBuku;
	info -> Kontainer.Pengarang = Pengarang;
	
	if((*S).top == NULL)
	{
		cout << "Stack penuh" << endl;
		info -> next = NULL;
	}
	else 
	{
		info -> next = (*S).top;
	}
	(*S).top = info;
	info = NULL;
}
void Pop(stack *S)
{
	if((*S).top != NULL){
	elemen *hapus = (*S).top;
	if(jmlElemen(*S)== 1)
	{
		(*S).top =NULL;
	}
	else 
	{
		(*S).top = (*S).top -> next;
	}
	hapus -> next = NULL;
	delete hapus;
}
else 
{
	cout << "Stack Kosong" << endl;
}		
}
void CetakStack(stack S)
{
	if(S.top != NULL)
	{
		cout << " MENAMPILKAN STACK " << endl;
		elemen *bantu = S.top;
		int i = 1;
		while(bantu != NULL)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Tumpukan ke               : " << i << endl;
			cout << "Kode Buku           : " << bantu -> Kontainer.npm <<endl;
			cout << "Judul Buku          : " << bantu -> Kontainer.nama_mhs << endl;
			cout << "Pengarang           : " << bantu -> Kontainer.nilai <<endl;
			
			bantu = bantu -> next;
			i = i + 1;
		}
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
		else 
		{
			cout << "Stack Kosong" << endl;
		}
	
}
		
		int main()
		{
			stack S;
			buatSTkosong(&S);
			CetakStack(S);
			cout << endl;
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
			push ("4523210666", "Budi" , "Adit", &S);
			push ("4523210888", "Nuri" , "Daffa", &S);
			push ("4523210555", "Arif" , "Ari", &S);
			CetakStack (S);
			cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << endl;
			cout << endl;
			Pop(&S);
			CetakStack(S);
			cout << endl;
			cout << endl;
			Pop (&S);
			CetakStack(S);
			cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cin.get();
		}

			
			
			
			
			
	

	