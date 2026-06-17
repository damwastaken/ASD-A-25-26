#include<iostream>
using namespace std;

class hanoi{
    public:
    int n[10],top;
    hanoi(){
        top=-1;}
    void push(int nilai){
        top++;
        n[top]=nilai;}
    int pop(){
        int ambil=n[top];
        top--;
        return ambil;}
    void tampil(string nama){
        cout<<" "<<nama<<endl;
        cout<<"-----------------"<<endl;
        if(top==-1){
            cout<<"(Kosong)"<<endl;
        }else{
            for(int i=top;i>=0;i--){
                cout<<"|  "<<n[i]<<"  |"<<endl;}}
        cout<<"-----------------"<<endl;}};

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
                if(tumpukan1.top!=-1){
                    pindah=tumpukan1.pop();
                    tumpukan2.push(pindah);
                }else{
                    cout<<"Tumpukan 1 Kosong!"<<endl;
                }break;
            case 2:
                if(tumpukan1.top!=-1){
                    pindah=tumpukan1.pop();
                    tumpukan3.push(pindah);
                }else{
                    cout<<"Tumpukan 1 Kosong!"<<endl;
                }break;
            case 3:
                if(tumpukan2.top!=-1){
                    pindah=tumpukan2.pop();
                    tumpukan1.push(pindah);
                }else{
                    cout<<"Tumpukan 2 Kosong!"<<endl;
                }break;
            case 4:
                if(tumpukan2.top!=-1){
                    pindah=tumpukan2.pop();
                    tumpukan3.push(pindah);
                }else{
                    cout<<"Tumpukan 2 Kosong!"<<endl;
                }break;
            case 5:
                if(tumpukan3.top!=-1){
                    pindah=tumpukan3.pop();
                    tumpukan1.push(pindah);
                }else{
                    cout<<"Tumpukan 3 Kosong"<<endl;
                }break;
            case 6:
                if(tumpukan3.top!=-1){
                    pindah=tumpukan3.pop();
                    tumpukan2.push(pindah);
                }else{
                    cout<<"Tumpukan 3 Kosong"<<endl;
                }break;
            case 7:
                cout<<"Keluar Program..."<<endl;break;
            default:
                cout<<"Pilih [1-7]"<<endl;
        }
    }while(pilihan!=7);
    return 0;
}