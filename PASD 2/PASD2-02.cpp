#include<iostream>
using namespace std;

class RumahMakan{
    private:
    int pilih;
    public:
    void menu(){
        cout<<"======== [ MENU RUMAH MAKAN SHALERO ] ========"<<endl;
        cout<<"Menu 1: Nasi Goreng Rp 5.000"<<endl;
        cout<<"Menu 2: Gado-gado Rp 3.500"<<endl;
        cout<<"Menu 3: Bubur Ayam Rp 2.500"<<endl;
        cout<<"Menu 4: Ayam Bakar Pedas Rp 7.500"<<endl;
        cout<<"=============================================="<<endl;
        }
    void pilihan(){
        cout<<"Pilihan Anda = ";cin>>pilih;
        cout<<endl;
        switch(pilih){
            case 1:
                cout<<"Anda memilih menu 1"<<endl;
                cout<<"Harga Rp 5.000"<<endl;break;
            case 2:
                cout<<"Anda memilih menu 2"<<endl;
                cout<<"Harga Rp 3.500"<<endl;break;
            case 3:
                cout<<"Anda memilih menu 3"<<endl;
                cout<<"Harga Rp 2.500"<<endl;break;
            case 4:
                cout<<"Anda memilih menu 4"<<endl;
                cout<<"Harga Rp 7.500"<<endl;break;
            default:
                cout<<"Silahkan pilih menu [1-4] yang sudah tersedia."<<endl;}}};

int main(){
    RumahMakan rm;
    rm.menu();
    rm.pilihan();
    return 0;
}