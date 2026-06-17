#include<iostream>
using namespace std;

struct Node{
    char data;
    Node *next;
};

class stack{
    private:
    Node *top;
    public:
    stack(){
        top=NULL;
    }
}