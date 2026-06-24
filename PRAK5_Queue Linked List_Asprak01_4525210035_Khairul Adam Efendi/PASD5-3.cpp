#include<iostream>
using namespace std;

class NilaiMK{
public:
    string npm;
    string nama_mhs;
    double nilai;
};

class elemen{
public:
    NilaiMK Kontainer;
    elemen *next;
};

class queue{
private:
    elemen *first;
    elemen *last;

public:
    queue(){
        first=NULL;
        last=NULL;}
    int isKosong(){
        if(first==NULL)
            return 1;
        else
            return 0;}

    int jmlElemen(){
        int hasil=0;
        elemen *bantu=first;
        while(bantu!=NULL){
            hasil++;
            bantu=bantu->next;}
        return hasil;}

    void add(string npm,string nama_mhs,double nilai){
        elemen *info=new elemen;

        info->Kontainer.npm=npm;
        info->Kontainer.nama_mhs=nama_mhs;
        info->Kontainer.nilai=nilai;
        info->next=NULL;

        if(first==NULL){
            first=info;}
        else{
            last->next=info;}

        last=info;}

    void del(){
        if(first!=NULL){

            elemen *hapus=first;

            if(first==last){
                first=NULL;
                last=NULL;}
            else{
                first=first->next;
                hapus->next=NULL;}

            delete hapus;}}

    void CetakQueue(){
        if(first!=NULL){

            cout<<"Menampilkan Queue"<<endl;

            elemen *bantu=first;
            int i=1;

            while(bantu!=NULL){

                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                cout<<"Elemen ke              : "<<i<<endl;
                cout<<"Nomor Pokok Mahasiswa  : "<<bantu->Kontainer.npm<<endl;
                cout<<"Nama Mahasiswa         : "<<bantu->Kontainer.nama_mhs<<endl;
                cout<<"Nilai Mahasiswa        : "<<bantu->Kontainer.nilai<<endl;

                bantu=bantu->next;
                i++;}

            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;}
        else{
            cout<<"Queue Kosong"<<endl;}}};

int main(){

    queue Q;
    int n;
    cout<<"Jumlah Data : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        string npm;
        string nama;
        double nilai;
        cout<<endl;
        cout<<"Data Mahasiswa Ke-"<<i<<endl;
        cout<<"NPM   : ";
        cin>>npm;
        cout<<"Nama  : ";
        cin>>nama;
        cout<<"Nilai : ";
        cin>>nilai;
        Q.add(npm,nama,nilai);}
    cout<<endl;
    Q.CetakQueue();
    cout<<endl;
    cout<<"Hapus 1 Data"<<endl;
    Q.del();
    Q.CetakQueue();
    return 0;}