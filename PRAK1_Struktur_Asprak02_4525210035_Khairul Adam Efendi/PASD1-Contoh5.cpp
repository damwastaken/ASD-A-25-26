#include<iostream>
using namespace std;

int main(){
    int n,*pn,**ppn;
    n=44;
    pn=&n;
    ppn=&pn;
    cout<<endl;
    cout<<"Isi variabel [n - *pn - *ppn]          = "<<n<<" - "<<*pn<<" - "<<*ppn<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Alamat variabel [&n - &pn - &ppn]      = "<<&n<<" - "<<&pn<<" - "<<&ppn<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Isi Variabel dalam HEXA [n - pn - ppn] = "<<n<<" - "<<pn<<" - "<<ppn<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;
    cin.get();
}