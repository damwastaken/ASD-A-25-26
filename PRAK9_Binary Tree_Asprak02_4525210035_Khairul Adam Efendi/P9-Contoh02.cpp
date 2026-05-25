#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node{
	char info;
	struct node* left;
	struct node* right;
};

typedef struct node simpul;
simpul *root,*p,*q[30],*r,*current;
char x;

void inisialisasi(){
	root=NULL;
	p=NULL;
}

void buatSimpul(char x){
	p=(simpul*) malloc(sizeof(simpul));
	if(p!=NULL){
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
}

void buatSimpulAkar(){
	if(root==NULL){
		if(p!=NULL){
			root=p;
			p->left=NULL;
			p->right=NULL;
		}
		else{
			cout<<"Simpul belum dibuat"<<endl;
		}
	}
	else{
		cout<<"Pohon sudah ada"<<endl;
	}
}

void insertUrutNomor(char input[6]){
	int i,j,flag;
	char x;
	flag=0;
	i=1;
	j=1;
	q[i]=root;
	while(flag==0&&j<6){
		x=input[j-1];
		if(x!='0'){
			buatSimpul(x);
			current=q[i];
			current->left=p;
			j++;
			q[j]=p;}
		else{
			flag=1;
			j++;
			q[j]=NULL;}
		if(flag==0){
			x=input[j-1];
			if(x!='0'){
				buatSimpul(x);
				current->right=p;
				j++;
				q[j]=p;}}
		else{
			flag=1;
			j++;
			q[j]=NULL;}
		i++;}}
		
void bacaUrutNomor(){
	int i,j,n,counter;
	i=1;j=1;n=1;counter=0;
	int level=0;
	while(q[i]!=NULL){
		current=q[i];
		if(i==1){
			cout<<endl;
			cout<<"Level "<<level<<endl;
		}
		cout<<current->info<<" - ";
		counter++;
		if(counter==n){
			level++;
			cout<<"Level "<<level<<" "<<endl;
		}
		if(counter==n){
			cout<<endl;
			counter=0;
			n=n*2;
		}
		if(current->left!=NULL){
			j++;
			q[i]=current->left;
		}
		if(current->right!=NULL){
			j++;
			q[i]=current->right;
		}
		i++;
	}
}

int main(){
	char root='R';
	char daun[6]={'S','U','V','W','Y','Z'};
	inisialisasi();
	buatSimpul(root);
	buatSimpulAkar();
	insertUrutNomor(daun);
	bacaUrutNomor();
	return 0;
}