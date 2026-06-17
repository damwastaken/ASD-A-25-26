#include<iostream>
using namespace std;

struct node{
    char data;
    node* next;};
class stack{
    private:
    node* top;
    public:
    stack(){
        top=NULL;}
    void push(char nilai){
        node* baru=new node;
        baru->data=nilai;
        baru->next=top;
        top=baru;}
    char pop(){
        if(top==NULL){
            return '-';}
        node* hapus=top;
        char nilai=hapus->data;
        top=top->next;
        delete hapus;
        return nilai;}
    void tampil(){
        node* bantu=top;
        cout<<"TOP"<<endl;
        while(bantu!=NULL){
            cout<<"| "<<bantu->data<<" |"<<endl;
            bantu=bantu->next;}
        cout<<"----"<<endl;}};

int main(){
    stack s,temp;
    s.push('A');
    s.push('B');
    s.push('C');
    cout<<"Tumpukan awal:"<<endl;
    s.tampil();
    cout<<"A. Memasukkan D setelah A"<<endl;
    char c=s.pop();
    char b=s.pop();
    char a=s.pop();
    s.push('D');
    s.push(a);
    s.push(b);
    s.push(c);
    s.tampil();

    cout<<"B. Memasukkaan E setelah B"<<endl;
    c=s.pop();
    b=s.pop();
    s.push('E');
    s.push(b);
    s.push(c);
    s.tampil();

    cout<<"Memasukkan F yang paling bawah dengan A, B, C hilang"<<endl;
    while (s.pop()!='-');
    s.push('F');
    s.tampil();
    
    cout<<"Memasukkan F yang paling bawah dengan A, B, C masih ada"<<endl;
    s.push('A');
    s.push('B');
    s.push('C');
    while(true){
        char x=s.pop();
        if(x=='-')
            break;
        temp.push(x);}
    s.push('F');
    while(true){
        char x=temp.pop();
        if(x=='-')
            break;
        s.push(x);}
    s.tampil();
    return 0;}