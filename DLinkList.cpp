#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
#define List_length 5
typedef struct DLNode{
	ElemType data;
	struct DLNode * next,*prior;
}DLNode;
void InitDList(DLNode*&L){
	L=(DLNode*)malloc(sizeof(DLNode));
	L->next=NULL;
	L->prior=NULL;
}
void createDLinkList(DLNode*&L){
	int s1[]={9,7,5,3,1};
	int n=0;
	DLNode *p1,*p2;
	p2=L;
	while(n<List_length){
		p1=(DLNode*)malloc(sizeof(DLNode));
		p1->data=s1[n];
		p1->next=p2->next;
		p1->prior=p2;
		p2->next=p1;
		p2=p1;
		n++;
	}
}

void Insert(DLNode *p1,DLNode *p2){
	p2->next=p1->next;
	p2->prior=p1;
	if(p1->next)p1->next->prior=p2;
	p1->next=p2;
}
void Print(DLNode* L){
	DLNode*p;
	p=L->next;
	while(p){
		cout<<p->data<<'\t';
		p=p->next;
	}
	cout<<endl;
}
int main(){
	DLNode *L;
	InitDList(L);
	createDLinkList(L);
	DLNode *N;
	N->data=10;
	N->next=N->prior=NULL;
	Insert(L,N);
	Print(L);
}
