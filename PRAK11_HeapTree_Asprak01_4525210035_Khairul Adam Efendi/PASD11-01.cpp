#include<iostream>
using namespace std;

void HEAP(int canArray[],int n,int i){
	int temp,canBesar=i,kiri=2*i+1,kanan=2*i+2;
	if(kiri<n&&canArray[kiri]<canArray[canBesar])
		canBesar=kiri;
	if(kanan<n&&canArray[kanan]<canArray[canBesar])
		canBesar=kanan;
	if(canBesar!=i){
		temp=canArray[i];	
		canArray[i]=canArray[canBesar];
		canArray[canBesar]=temp;
		HEAP(canArray,n,canBesar);
	}
}

void sortHEAP(int canArray[],int n){
	int temp;
	for(int i=n/2-1;i>=0;i--)
		HEAP(canArray,n,i);
	for(int i=n-1;i>=0;i--){
		temp=canArray[0];
		canArray[0]=canArray[i];
		canArray[i]=temp;
		HEAP(canArray,i,0);
	}
}

int main(){
	int canArray[]={22,7,66,28,11,63,24,12,77,99};
	int n=10,i;
	cout<<"Menampilkan data sebelum diurutkan"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(i=0;i<n;i++)
		cout<<canArray[i]<<" ";
	cout<<endl;
	sortHEAP(canArray,n);
	cout<<endl;
	cout<<"Menampilkan data setelah diurutkan"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(i=0;i<n;i++)
		cout<<canArray[i]<<" ";
	cin.get();
}