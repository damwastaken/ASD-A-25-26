#include<iostream>
using namespace std;

void tampil(string OS[],int n){
    for(int i=0;i<n;i++){
        cout<<OS[i];
        if(i<n-1)
            cout<<" | ";}
    cout<<endl;}

void copyData(string dataAwal[],string OS[],int n){
    for(int i=0;i<n;i++)
        OS[i]=dataAwal[i];}

int main(){
    string dataAwal[10]={"Maemo","Symbian","Mac","Windows","Iphone"};
    string OS[20];
    int n;
    cout<<"DATA AWAL"<<endl;
    tampil(dataAwal,5);
    cout<<endl;
    cout<<"A. Tambah Maemo 4 paling bawah, hapus Mac"<<endl;
    n=5;
    copyData(dataAwal,OS,n);
    for(int i=2;i<n-1;i++)
        OS[i]=OS[i+1];
    n--;
    OS[n]="Maemo 4";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"B. Tambah Windows Mobile dibawah Windows, hapus Iphone"<<endl;
    n=5;
    copyData(dataAwal,OS,n);
    n--;
    OS[n]="Windows Mobile";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"C. Tambah Java Midlet dibawah Symbian, hapus Maemo"<<endl;
    n=5;
    copyData(dataAwal,OS,n);
    for(int i=0;i<n-1;i++)
        OS[i]=OS[i+1];
    n--;
    for(int i=n;i>1;i--)
        OS[i]=OS[i-1];
    OS[1]="Java Midlet";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"D. Tambah Lion OS X dibawah Mac, hapus Maemo"<<endl;
    n=5;
    copyData(dataAwal,OS,n);
    for(int i=0;i<n-1;i++)
        OS[i]=OS[i+1];
    n--;
    for(int i=n;i>2;i--)
        OS[i]=OS[i-1];
    OS[2]="Lion OS X";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"E. Tambah Android dibawah Iphone, hapus Maemo"<<endl;
    n=5;
    copyData(dataAwal,OS,n);
    for(int i=0;i<n-1;i++)
        OS[i]=OS[i+1];
    n--;
    OS[n]="Android";
    n++;
    tampil(OS,n);
    return 0;}