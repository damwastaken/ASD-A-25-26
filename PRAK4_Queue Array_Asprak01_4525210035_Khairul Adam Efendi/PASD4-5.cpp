#include<iostream>
using namespace std;

void tampil(string OS[],int n){
    for(int i=0;i<n;i++){
        cout<<OS[i];
        if(i<n-1)
            cout<<" | ";}
    cout<<endl;}

int main(){
    string OS[20];
    int n=5;
    OS[0]="Maemo";
    OS[1]="Symbian";
    OS[2]="Mac";
    OS[3]="Windows";
    OS[4]="Iphone";
    cout<<"Data Awal:"<<endl;
    tampil(OS,n);
    cout<<endl;
    cout<<"A. Iphone 5 di atas Iphone"<<endl;
    for(int i=n;i>4;i--)
        OS[i]=OS[i-1];
    OS[4]="Iphone 5";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"B. Windows Phone di atas Windows"<<endl;
    for(int i=n;i>3;i--)
        OS[i]=OS[i-1];
    OS[3]="Windows Phone";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"C. SnowLeopard setelah Mac"<<endl;
    for(int i=n;i>3;i--)
        OS[i]=OS[i-1];
    OS[3]="SnowLeopard";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"D. Symbian Belle setelah Symbian"<<endl;
    for(int i=n;i>2;i--)
        OS[i]=OS[i-1];
    OS[2]="Symbian Belle";
    n++;
    tampil(OS,n);
    cout<<endl;
    cout<<"E. Maemo 4 paling bawah"<<endl;
    OS[n]="Maemo 4";
    n++;
    tampil(OS,n);
    return 0;}