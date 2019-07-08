#include<iostream>
#include<stdlib.h>
using namespace std;
#define List_length 5
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode;
//初始化一个带头结点的空链表
void InitLinkList(LNode *&L){
	//为头结点分配内存空间
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;

}
//尾插法
void CreateLinkListR(LNode *&L){
	LNode *p,*q;
	//LNode *s;
	int i=0;
	int n=0;
	ElemType s1[]={1,3,5,7,9};
	p=L;
	while(n<List_length){
		q=(LNode*)malloc(sizeof(LNode));
		q->data=s1[n];
		q->next=p->next;
		p->next=q;
		p=q;
		n++;
	}
}
//头插法
void CreateLinkListF(LNode*&L){
	LNode *q;
	int n=0;
	ElemType s2[]={10,8,6,4,2};
	while(n<List_length){
		q=(LNode*)malloc(sizeof(LNode));
		q->data=s2[n];
		q->next=L->next;
		L->next=q;
		n++;
	}
}
//查找第一个值为e的结点，并通过p返回
bool FindNode(LNode*L,ElemType e,LNode *&p){
	LNode*s;
	s=L->next;
	while(s!=NULL){
		if(s->data==e){
			p=s;
			return true;
			//break;
		}
		s=s->next;
	}
	return false;
}
//在结点p1后插入结点p2
void Insert(LNode *A,LNode*p1,LNode*p2){
	p2->next=p1->next;
	p1->next=p2;
}
//删除结点p后的结点
void Delete(LNode *p){
	p->next=p->next->next;

}
//归并
void merge(LNode*A,LNode *B,LNode*&C){
	LNode *p1,*p2,*p3;
	//p1，p2指向A B头结点后的第一个有值结点
	p1=A->next;
	p2=B->next;
	//C使用A的头结点，释放B的头结点
	C=A;
	p3=C;
	free(B);
	while(p1!=NULL&&p2!=NULL){
		if(p1->data<=p2->data){
			p3->next=p1;
			p1=p1->next;
			p3=p3->next;
		}else{
			p3->next=p2;
			p2=p2->next;
			p3=p3->next;
		}
	}
	//while循环执行完毕时，因为结点一次只插一个，所以肯定有一个链表没插完，
	//原链表递增有序，说明链表中剩下的所有元素都比最后插进去的要大，直接将剩余部分连接就行了
	if(p2!=NULL)
		p3->next=p2;
	if(p1!=NULL)
		p3->next=p1;
	//p3->next=NULL;//A B的最后有NULL，将剩余部分连接的同时NULL也在C最后了
}
//显示链表
void Print(LNode* L){
	LNode *p;
	p=L->next;
	while(p){
		cout<<p->data<<'\t';
		p=p->next;
	}
	cout<<endl;
}
int main(){
	LNode *A,*B;
	LNode *C;
	LNode *D,*E;
	D->data=4;
	D->next==NULL;
	InitLinkList(A);
	InitLinkList(B);
	CreateLinkListF(A);
	CreateLinkListR(B);
	cout<<"头插{10,8,6,4,2}"<<endl;
	Print(A);
	cout<<"尾插{1,3,5,7,9}"<<endl;
	Print(B);
	//此时A B是两个递增有序的单链表,设计一个算法将A B归并成一个非递减有序(中间可以有相等）的链表C，C的结点由A ，B的结点组成；
	merge(A,B,C);
	cout<<"AB归并后的非递减有序链表C："<<endl;
	Print(C);
	FindNode(C,4,E);
	Insert(C,E,D);
	cout<<"执行插入操作后："<<endl;
	Print(C);
	Delete(E);
	Print(C);

}
