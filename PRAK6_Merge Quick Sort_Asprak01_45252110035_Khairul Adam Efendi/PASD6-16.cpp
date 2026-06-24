#include<iostream>
using namespace std;

int a[50];

void Merge(int,int,int);

void MergeSort(int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);

        Merge(low,mid,high); }}

void Merge(int low,int mid,int high){
    int h,i,j,b[50],k;
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high)){
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++;}
        else{
            b[i]=a[j];
            j++;}
        i++;}
    if(h>mid){
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;}}
    else{
        for(k=h;k<=mid;k++){
            b[i]=a[k];
            i++;}}
    for(k=low;k<=high;k++){
        a[k]=b[k];}}

int main(){
    int num,i;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" PROGRAM PENGURUTAN MERGE "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;
    cout<<"Masukkan jumlah bilangan yang diinginkan: ";
    cin>>num;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Masukkan sejumlah "<<num<<" data yang akan diurutkan"<<endl;
    for(i=1;i<=num;i++){
        cout<<"Bilangan ke-"<<i<<" : ";
        cin>>a[i];}
    MergeSort(1,num);
    cout<<endl;
    cout<<"Hasil Akhir Pengurutan : "<<endl;
    cout<<endl;
    for(i=1;i<=num;i++){
        cout<<a[i]<<" ";}
    cout<<endl;
	cin.get();}