#include<iostream>
using namespace std;

typedef struct{
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct elm *alamatelm;
typedef struct elm{
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

typedef struct{
    elemen* top;
} stack;

void buatSTkosong(stack *s){
    (*s).top=NULL;
}

int isKosong(stack s){
    bool hasil=false;
    if(s.top==NULL){
        hasil=true;
    }
    return hasil;
}

int jmlElemen(stack s){
    int hasil=0;
    if(s.top!=NULL){
        elemen *bantu;
        bantu=s.top;
        while(bantu!=NULL){
            hasil=hasil+1;
            bantu=bantu->next;
        }
    }
    return hasil;
}

void push(string npm,string nama_mhs,double nilai,stack *s){
    elemen *info;
    info=new elemen;
    info->Kontainer.npm=npm;
    info->Kontainer.nama_mhs=nama_mhs;
    info->Kontainer.nilai=nilai;
    if((*s).top==NULL){
        cout<<"Stack Penuh!"<<endl;
        info->next=NULL;
    }else{
        info->next=(*s).top;
    }
    (*s).top=info;
    info=NULL;
}

void pop(stack *s){
    if((*s).top!=NULL){
        elemen *hapus=(*s).top;
        if(jmlElemen(*s)==1){
            (*s).top=NULL;
        }else{
            (*s).top=(*s).top->next;
        }
        hapus->next=NULL;
        delete hapus;
    }else{
        cout<<"Stack Kosong!"<<endl;
    }
}

void cetakStack(stack s){
    if(s.top!=NULL){
        cout<<"Menampilkan Stack"<<endl;
        elemen *bantu=s.top;
        int i=1;
        while(bantu!=NULL){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"Elemen ke             : "<<i<<endl;
            cout<<"Nomor Pokok Mahasiswa : "<<bantu->Kontainer.npm<<endl;
            cout<<"Nama Mahasiswa        : "<<bantu->Kontainer.nama_mhs<<endl;
            cout<<"Nilai Mahasiswa       : "<<bantu->Kontainer.nilai<<endl;
            bantu=bantu->next;
            i=i+1;
        }
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }else{
        cout<<"Stack Kosong!"<<endl;}
}

int main(){
    stack s;
    buatSTkosong(&s);
    cout<<endl;
    cout<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    push("4525210666","Budi",88.75,&s);
    push("4525210777","Susi",78.85,&s);
    push("4525210888","Nuri",98.65,&s);
    push("4525210999","Bimo",68.55,&s);
    push("4525210555","Arif",78.85,&s);
    push("4525210444","Rido",98.65,&s);
    push("4525210222","Ella",68.55,&s);
    cetakStack(s);
    cout<<"====================================="<<endl;
    cout<<endl;
    cout<<endl;
    pop(&s);
    cetakStack(s);
    cout<<endl;
    cout<<endl;
    pop(&s);
    cetakStack(s);
    cout<<"====================================="<<endl;
    return 0;
}