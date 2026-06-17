#include<iostream>
#include<iomanip>
using namespace std;
/*
    Mohon maaf, tanpa mengurangi rasa hormat,
    dikarenakan kedua soal (7 dan 15) Sama persis, saya gabungkan
    atau saya buat 1 program yang memenuhi aturan dan perintah dari
    kedua soal tersebut.
    Atas perhatiannya saya ucapkan terima kasih.
*/

//Untuk Soal 7 (STRUCT)
struct Barang{
    string kode,nama;
    int harga,quantity,jumlah;
};

int main(){
    string namaPelanggan,alamat,telp;
    int jumlahBarang,totalBayar=0;

    cout<<"=============================================="<<endl;
    cout<<"              PENJUALAN TOKO BAGUS            "<<endl;
    cout<<"=============================================="<<endl;
    cin.ignore();
    cout<<"Nama Pelanggan            : ";getline(cin,namaPelanggan);
    cout<<"Alamat Pelanggan          : ";getline(cin,alamat);
    cout<<"Telp Pelanggan            : ";getline(cin,telp);
    cout<<"Jumlah Barang yang Dibeli : ";cin>>jumlahBarang;

    //Untuk Soal 15 (POINTER)
    Barang data[100];
    Barang *p=data;
    cout<<endl;
    
    for(int i=0;i<jumlahBarang;i++){
        cin.ignore();
        cout<<"Barang ke-"<<i+1<<endl;
        cout<<"Kode Barang : ";getline(cin,(p+i)->kode);
        cout<<"Nama Barang : ";getline(cin,(p+i)->nama);
        cout<<"Harga Barang : ";cin>>(p+i)->harga;
        cout<<"Quantity    : ";cin>>(p+i)->quantity;

        (p+i)->jumlah=(p+i)->harga*(p+i)->quantity;
        totalBayar+=(p+i)->jumlah;
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"=============================================="<<endl;
    cout<<"              PENJUALAN TOKO BAGUS            "<<endl;
    cout<<"=============================================="<<endl;
    cout<<"Nama Pelanggan     : "<<namaPelanggan<<endl;
    cout<<"Alamat Pelanggan   : "<<namaPelanggan<<endl;
    cout<<"Telp Pelanggan     : "<<namaPelanggan<<endl;
    cout<<"Barang yang Dibeli :"<<endl<<endl;
    cout<<"=============================================="<<endl;
    cout<<left
        <<setw(5)<<"No"
        <<setw(10)<<"Kode"
        <<setw(15)<<"Nama"
        <<setw(12)<<"Harga"
        <<setw(10)<<"Qty"
        <<setw(12)<<"Jumlah"
        <<endl;
    cout<<"=============================================="<<endl;
    for(int i=0;i<jumlahBarang;i++){
        cout<<left
            <<setw(5)<<i+1
            <<setw(10)<<(p+i)->kode
            <<setw(15)<<(p+i)->nama
            <<setw(12)<<(p+i)->harga
            <<setw(10)<<(p+i)->quantity
            <<setw(12)<<(p+i)->jumlah
            <<endl;
    }
    cout<<"=============================================="<<endl;
    cout<<"Jumlah Barang yang Dibeli : "<<jumlahBarang<<endl;
    cout<<"Total Bayar               : "<<totalBayar<<endl;
    cout<<"=============================================="<<endl;
    return 0;
}