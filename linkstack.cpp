#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;
void initstack(LNode *head){
	//创造一个空栈
	head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
};
void push(LNode *head,int x){
	LNode*p=(LNode*)malloc(sizeof(LNode));
	p->next=NULL;
	p->data=x;
	p->next=head->next;
	head->next=p;
}
bool pop(LNode *head,int &x){
	//判断栈是否空
	if(!head->next)
		return false;
	LNode *p;
	p=head->next;
	head->next=p->next;
	x=p->data;
	free(p);
	return true;
}
int main(){
	LNode *lst;
	int x;
	initstack(lst);
	push(lst,1);
	push(lst,2);
	push(lst,3);
	pop(lst,x);
	cout<<x<<endl;
	pop(lst,x);
	cout<<x<<endl;
}
