#include <iostream>
using namespace std;

int data[10], data2[10];
int n;

void tukar(int a, int b){
	int t;
	t = data[b];
	data[b] = data[a];
	data[a] = t;
}

void input(){

}

void tampil(){
	for(int i=0; i<n; i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
}

void BubbleSort(){
	for(int i=1; i<n; i++){
		for(int j=n-1; j>=i; j--){
			if(data[j] > data[j-1]){
				tukar(j, j-1);
			}
			tampil();
		}
		cout<<endl;
	}
}

int main(){

	cout<<"*----------------------------*"<<endl;
	cout<<"Bubble Sort Ascending"<<endl;
	cout<<"*----------------------------*"<<endl;
	n=10;
	int temp[10]={45,25,21,0,0,35,11,6,5,21};
	for(int i=0;i<n;i++){
		data[i]=temp[i];
		data2[i]=data[i];
	}
	cout<<"Data Awal : ";
	tampil();
	cout<<"\nProses Bubble Sort"<<endl;
	BubbleSort();
	cout<<"\nHasil Akhir : ";
	tampil();
	return 0;
}