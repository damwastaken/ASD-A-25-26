#include<iostream>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};

Node *root=NULL;

Node* buatNode(char data){
    Node *baru=new Node;
    baru->data=data;
    baru->left=NULL;
    baru->right=NULL;
    return baru;
}

Node* insert(Node *root,char data){
    if(root==NULL)
        return buatNode(data);
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}

Node* minimum(Node *root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}

Node* hapus(Node *root,char data){
    if(root==NULL)
        return NULL;
    if(data<root->data)
        root->left=hapus(root->left,data);
    else if(data>root->data)
        root->right=hapus(root->right,data);
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        Node *temp=minimum(root->right);
        root->data=temp->data;
        root->right=hapus(root->right,temp->data);
    }
    return root;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    char data[]={'A','F','D','B','E','C'};
    for(int i=0;i<6;i++)
        root=insert(root,data[i]);
    cout<<"Inorder Awal : ";
    inorder(root);
    cout<<endl;
    cout<<endl;
    root=hapus(root,'E');
    root=insert(root,'M');
    cout<<"a. Hapus E, Insert M : ";
    inorder(root);
    cout<<endl;
    root=hapus(root,'B');
    root=insert(root,'N');
    cout<<"b. Hapus B, Insert N : ";
    inorder(root);
    cout<<endl;
    root=hapus(root,'D');
    root=insert(root,'O');
    cout<<"c. Hapus D, Insert O : ";
    inorder(root);
    cout<<endl;
    root=hapus(root,'F');
    root=insert(root,'P');
    cout<<"d. Hapus F, Insert P : ";
    inorder(root);
    cout<<endl;
    return 0;
}