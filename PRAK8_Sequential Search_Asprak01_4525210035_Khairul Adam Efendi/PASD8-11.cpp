#include<iostream>
using namespace std;

struct Data{
	char huruf;
};

int Search01(Data A[],int,int);
int main(){
	const int jmlElemenArray=11;
	Data tika[jmlElemenArray]={'A','B','C','D','E','F','G','H','I','J','K'};
	cout<<"*************************************"<<endl;
	cout<<"** S E Q U E N T A L   S E A R C H **"<<endl;
	cout<<"*************************************"<<endl;
	cout<<"Isi data nya adalah"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<endl;
	for(int count=0;count<jmlElemenArray;count++){
		cout<<"\t"<<"Data ["<<count<<"]"<<"--> "<<tika[count].huruf<<endl;
	}
	char searchElemen=0;
	int flaq=0;
	cout<<"*************************************"<<endl;
	cout<<endl;
	searchElemen='E';
	cout<<"Data yang ingin dicari = "<<searchElemen<<endl;
	flaq=Search01(tika,jmlElemenArray,searchElemen);
	if(flaq!=-1)
		cout<<"Data yang dicari ditemukan pada posisi : Data["<<flaq<<"]"<<endl;
	else
		cout<<"Data yang Anda cari tidak ditemukan"<<endl;
	cin.get();
	return 0;
}

int Search01(Data tika[],int jmlElemenArray,int Elemen){
	int flaq=-1;
	for(int count=0;count<jmlElemenArray;count++){
		if(Elemen==tika[count].huruf){
			flaq=count;
			break;
		}
	}
	return flaq;
}