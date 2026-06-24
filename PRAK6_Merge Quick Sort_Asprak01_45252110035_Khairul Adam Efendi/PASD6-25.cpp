#include<iostream>
using namespace std;

class MergeSort{
private:
    int arr[100];
    int n;

public:

    void inputData(){
        cout<<"Masukkan jumlah data : ";
        cin>>n;
        cout<<"Masukkan "<<n<<" data :"<<endl;
        for(int i=0;i<n;i++){
            cout<<"Data ke-"<<i+1<<" : ";
            cin>>arr[i];}}

    void merge(int Kiri,int mid,int Kanan){
        int n1=mid-Kiri+1;
        int n2=Kanan-mid;
        int L[100],R[100];
        for(int i=0;i<n1;i++){
            L[i]=arr[Kiri+i];}
        for(int j=0;j<n2;j++){
            R[j]=arr[mid+1+j];}
        int i=0;
        int j=0;
        int k=Kiri;
        while(i<n1&&j<n2){
            if(L[i]>=R[j]){
                arr[k]=L[i];
                i++;}
            else{
                arr[k]=R[j];
                j++;}
            k++;}
        while(i<n1){
            arr[k]=L[i];
            i++;
            k++;}
        while(j<n2){
            arr[k]=R[j];
            j++;
            k++;}}

    void mergeSort(int Kiri,int Kanan){
        if(Kiri<Kanan){
            int mid=Kiri+(Kanan-Kiri)/2;
            mergeSort(Kiri,mid);
            mergeSort(mid+1,Kanan);
            merge(Kiri,mid,Kanan);}}

    void cetakData(){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";}
        cout<<endl;}

    void proses(){
        cout<<endl;
        cout<<"Data Sebelum Disort"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
        cetakData();
        mergeSort(0,n-1);
        cout<<endl;
        cout<<"Data Setelah Disort Descending"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cetakData();}
};

int main(){
    MergeSort M;
    M.inputData();
    M.proses();
    return 0;}