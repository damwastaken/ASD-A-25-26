#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
	struct Node *Left;
	char INFO;
	struct Node *Right;
};

typedef struct Node Simpul;

Simpul *Root,*P,*Current;
Simpul *Q[129];

void Inisialisasi(){
	Root=NULL;
	P=NULL;
	Current=NULL;
	for(int i=0;i<129;i++){
		Q[i]=NULL;
	}
}

void BuatSimpul(char X){
	P=new Simpul;
	if(P!=NULL){
		P->INFO=X;
		P->Left=NULL;
		P->Right=NULL;
	}
	else{
		cout<<"Memory Heap Full"<<endl;
		exit(1);
	}
}

void BuatSimpulAkar(){
	if(Root==NULL){
		if(P!=NULL){
			Root=P;
			Root->Left=NULL;
			Root->Right=NULL;
			cout<<"Root Berhasil Dibuat"<<endl;
		}
		else{
			cout<<"Simpul Belum Dibuat"<<endl;
		}
	}
	else{
		cout<<"Root Sudah Ada"<<endl;
	}
}

bool IsEmpty(){
	if(Root==NULL)
		return true;
	else
		return false;
}

Simpul *Alokasi(char X){
	Simpul *NodeBaru;
	NodeBaru=new Simpul;
	if(NodeBaru!=NULL){
		NodeBaru->INFO=X;
		NodeBaru->Left=NULL;
		NodeBaru->Right=NULL;
	}
	return NodeBaru;
}

void InsertUrutNomor(){
	int depan=1;
	int belakang=1;
	char X;

	Q[belakang]=Root;

	while(depan<=belakang){
		Current=Q[depan];

		cout<<"Masukkan Anak Kiri dari "<<Current->INFO<<" (0 jika tidak ada) : ";
		cin>>X;
		if(X!='0'){
			Current->Left=Alokasi(X);
			belakang++;
			Q[belakang]=Current->Left;
		}

		cout<<"Masukkan Anak Kanan dari "<<Current->INFO<<" (0 jika tidak ada) : ";
		cin>>X;
		if(X!='0'){
			Current->Right=Alokasi(X);
			belakang++;
			Q[belakang]=Current->Right;
		}

		depan++;
	}
}

void BacaUrutNomor(){
	int depan=1;
	int belakang=1;

	Q[belakang]=Root;

	cout<<endl;
	cout<<"=================================="<<endl;
	cout<<"ISI BINARY TREE (LEVEL ORDER)"<<endl;
	cout<<"=================================="<<endl;

	while(depan<=belakang){
		Current=Q[depan];

		if(Current!=NULL){
			cout<<Current->INFO<<" ";

			if(Current->Left!=NULL){
				belakang++;
				Q[belakang]=Current->Left;
			}

			if(Current->Right!=NULL){
				belakang++;
				Q[belakang]=Current->Right;
			}
		}

		depan++;
	}

	cout<<endl;
}

void PreOrder(Simpul *Root){
	if(Root!=NULL){
		cout<<Root->INFO<<" ";
		PreOrder(Root->Left);
		PreOrder(Root->Right);
	}
}

void InOrder(Simpul *Root){
	if(Root!=NULL){
		InOrder(Root->Left);
		cout<<Root->INFO<<" ";
		InOrder(Root->Right);
	}
}

void PostOrder(Simpul *Root){
	if(Root!=NULL){
		PostOrder(Root->Left);
		PostOrder(Root->Right);
		cout<<Root->INFO<<" ";
	}
}

int HitungNode(Simpul *Root){
	if(Root==NULL)
		return 0;
	return 1+HitungNode(Root->Left)+HitungNode(Root->Right);
}

int HitungDaun(Simpul *Root){
	if(Root==NULL)
		return 0;
	if(Root->Left==NULL && Root->Right==NULL)
		return 1;
	return HitungDaun(Root->Left)+HitungDaun(Root->Right);
}

int TinggiTree(Simpul *Root){
	if(Root==NULL)
		return 0;

	int kiri=TinggiTree(Root->Left);
	int kanan=TinggiTree(Root->Right);

	if(kiri>kanan)
		return kiri+1;
	else
		return kanan+1;
}

int main(){
	char X;

	Inisialisasi();

	cout<<"===================================="<<endl;
	cout<<"      PROGRAM BINARY TREE"<<endl;
	cout<<"===================================="<<endl;
	cout<<"Masukkan Root : ";
	cin>>X;

	BuatSimpul(X);
	BuatSimpulAkar();

	cout<<endl;
	InsertUrutNomor();

	cout<<endl;
	BacaUrutNomor();

	cout<<endl;
	cout<<"===================="<<endl;
	cout<<"PREORDER"<<endl;
	cout<<"===================="<<endl;
	PreOrder(Root);

	cout<<endl;
	cout<<endl;

	cout<<"===================="<<endl;
	cout<<"INORDER"<<endl;
	cout<<"===================="<<endl;
	InOrder(Root);

	cout<<endl;
	cout<<endl;

	cout<<"===================="<<endl;
	cout<<"POSTORDER"<<endl;
	cout<<"===================="<<endl;
	PostOrder(Root);

	cout<<endl;
	cout<<endl;

	cout<<"===================="<<endl;
	cout<<"INFORMASI TREE"<<endl;
	cout<<"===================="<<endl;
	cout<<"Jumlah Node  : "<<HitungNode(Root)<<endl;
	cout<<"Jumlah Daun  : "<<HitungDaun(Root)<<endl;
	cout<<"Tinggi Tree  : "<<TinggiTree(Root)<<endl;

	cout<<endl;
	system("pause");
	return 0;
}