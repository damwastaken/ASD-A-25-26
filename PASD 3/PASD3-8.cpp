#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class hanoi{
    private:
    Node *top;
    public:
    hanoi(){
        top=NULL;
    }
    bool kosong(){
        return top==NULL;
    }
    void push(int nilai){
        Node *baru=new Node;
        baru->data=nilai;
        baru->next=top;
        top=baru;
    }
    int pop(){
        if(kosong()){
            return -1;
        }
        Node *hapus=top;
        int ambil=hapus->data;
        top=top->next;
        delete hapus;
        return ambil;
    }
    void tampil(string nama){
        cout<<" "<<nama<<endl;
        cout<<"-----------------"<<endl;
        if(kosong()){
            cout<<"(Kosong)"<<endl;
        }else{
            Node *bantu=top;
            while(bantu!=NULL){
                cout<<"|  "<<bantu->data<<"  |"<<endl;
            bantu=bantu->next;
            }
        }
        cout<<"-----------------"<<endl;
    }
};

int main(){
    hanoi tumpukan1;
    hanoi tumpukan2;
    hanoi tumpukan3;
    tumpukan1.push(3);
    tumpukan1.push(2);
    tumpukan1.push(1);

    int pilihan,pindah;
    do{
        cout<<"==================================="<<endl;
        cout<<"           PROGRAM STACK           "<<endl;
        cout<<"==================================="<<endl;

        tumpukan1.tampil("TUMPUKAN 1");
        tumpukan2.tampil("TUMPUKAN 2");
        tumpukan3.tampil("TUMPUKAN 3");

        cout<<"Menu :"<<endl;
        cout<<"1. Pindah Tumpukan 1 ke 2"<<endl;
        cout<<"2. Pindah Tumpukan 1 ke 3"<<endl;
        cout<<"3. Pindah Tumpukan 2 ke 1"<<endl;
        cout<<"4. Pindah Tumpukan 2 ke 3"<<endl;
        cout<<"5. Pindah Tumpukan 3 ke 1"<<endl;
        cout<<"6. Pindah Tumpukan 3 ke 2"<<endl;
        cout<<"7. Keluar"<<endl;
        cout<<"Pilihan : ";cin>>pilihan;
        switch(pilihan){
            case 1:
                if(!tumpukan1.kosong()){
                    pindah=tumpukan1.pop();
                    tumpukan2.push(pindah);
                }break;
            case 2:
                if(!tumpukan1.kosong()){
                    pindah=tumpukan1.pop();
                    tumpukan3.push(pindah);
                }break;
            case 3:
                if(!tumpukan2.kosong()){
                    pindah=tumpukan2.pop();
                    tumpukan1.push(pindah);
                }break;
            case 4:
                if(!tumpukan2.kosong()){
                    pindah=tumpukan2.pop();
                    tumpukan3.push(pindah);
                }break;
            case 5:
                if(!tumpukan3.kosong()){
                    pindah=tumpukan3.pop();
                    tumpukan1.push(pindah);
                }break;
            case 6:
                if(!tumpukan3.kosong()){
                    pindah=tumpukan3.pop();
                    tumpukan2.push(pindah);
                }break;
            case 7:
                cout<<"Keluar Program..."<<endl;break;
            default:
                cout<<"Pilih [1-7]"<<endl;
        }
    }while(pilihan!=7);
    return 0;
}