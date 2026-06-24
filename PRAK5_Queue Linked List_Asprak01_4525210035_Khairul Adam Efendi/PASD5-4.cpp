#include<iostream>
using namespace std;

typedef struct elm *alamatelm;

typedef struct elm{
    string info;
    alamatelm next;
}elemen;

typedef struct{
    elemen *first;
    elemen *last;
}queue;

void buatQUkosong(queue *Q){
    (*Q).first=NULL;
    (*Q).last=NULL;}

void add(string data,queue *Q){
    elemen *baru=new elemen;
    baru->info=data;
    baru->next=NULL;
    if((*Q).first==NULL){
        (*Q).first=baru;}
    else{
        (*Q).last->next=baru;}
    (*Q).last=baru;}

void del(queue *Q){
    if((*Q).first!=NULL){
        elemen *hapus=(*Q).first;
        if((*Q).first==(*Q).last){
            (*Q).first=NULL;
            (*Q).last=NULL;}
        else{
            (*Q).first=(*Q).first->next;
            hapus->next=NULL;}
        delete hapus;}}

void tampil(queue Q){
    elemen *bantu=Q.first;
    while(bantu!=NULL){
        cout<<bantu->info;
        if(bantu->next!=NULL)
            cout<<" -> ";
        bantu=bantu->next;}
    cout<<endl;}

void insertSetelah(string cari,string data,queue *Q){
    elemen *bantu=(*Q).first;
    while(bantu!=NULL && bantu->info!=cari){
        bantu=bantu->next;}
    if(bantu!=NULL){
        elemen *baru=new elemen;
        baru->info=data;
        baru->next=bantu->next;
        bantu->next=baru;
        if(bantu==(*Q).last){
            (*Q).last=baru;}}}

int main(){
    cout<<"A. Memasukkan D setelah A"<<endl;
    queue Q1;
    buatQUkosong(&Q1);
    add("A",&Q1);
    add("B",&Q1);
    add("C",&Q1);
    cout<<"Data Awal : ";
    tampil(Q1);
    insertSetelah("A","D",&Q1);
    cout<<"Hasil     : ";
    tampil(Q1);
    cout<<endl;
    cout<<"B. Memasukkan F paling akhir dengan A,B,C hilang"<<endl;
    queue Q2;
    buatQUkosong(&Q2);
    add("A",&Q2);
    add("B",&Q2);
    add("C",&Q2);
    cout<<"Data Awal : ";
    tampil(Q2);
    while(Q2.first!=NULL){
        del(&Q2);}
    add("F",&Q2);
    cout<<"Hasil     : ";
    tampil(Q2);
    cout<<endl;
    cout<<"C. Memasukkan F paling akhir dengan A,B,C hilang"<<endl;
    queue Q3;
    buatQUkosong(&Q3);
    add("A",&Q3);
    add("B",&Q3);
    add("C",&Q3);
    cout<<"Data Awal : ";
    tampil(Q3);
    while(Q3.first!=NULL){
        del(&Q3);}
    add("F",&Q3);
    cout<<"Hasil     : ";
    tampil(Q3);
    cout<<endl;
    cout<<"D. Memasukkan E setelah B"<<endl;
    queue Q4;
    buatQUkosong(&Q4);
    add("A",&Q4);
    add("B",&Q4);
    add("C",&Q4);
    cout<<"Data Awal : ";
    tampil(Q4);
    insertSetelah("B","E",&Q4);
    cout<<"Hasil     : ";
    tampil(Q4);
    return 0;}