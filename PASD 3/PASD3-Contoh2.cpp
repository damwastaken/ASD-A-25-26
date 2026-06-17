#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void buat_simpul(int x);
void awal();
void cetak();
void insertKanan();
struct Node{
    int info;
    struct Node *link;};
typedef struct Node simpul;
simpul *p,*first,*last,*q;
int x;
int main(){
    int A[7]={22,28,7,11,66,63,10};
    int i;
    first=NULL;
    i=0;
    x=A[i];
    buat_simpul(x);
    awal();
    for(i=1;i<=6;i++){
        x=A[i];
        buat_simpul(x);
        insertKanan();}
    cout<<"Nilai sebelum dilakukan insert kanan : ";
    cetak();
    x=100;
    buat_simpul(x);
    insertKanan();
    cout<<endl;
    cout<<"Nilai setelah dilakukan insert kanan : ";
    cetak();
    cout<<endl;
    cin.get();
}

void buat_simpul(int x){
    p=(simpul*) malloc(sizeof(simpul));
    if(p!=NULL){
        p->info=x;
    }else{
        cout<<"Pembuatan simpul tidak berhasil"<<endl;
        cin.get();
        exit(1);}}

void awal(){
    first=p;
    last=p;
    p->link=NULL;}

void insertKanan(){
    last->link=p;
    last=p;
    p->link=NULL;}

void cetak(){
    int x;
    q=first;
    while(q!=NULL){
        x=q->info;
        cout<<" "<<x;
        q=q->link;}}
