#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;
struct LiQueue
{
	LNode *front;
	LNode *rear;
};
void initQueue(LiQueue *&Q){
	Q=(LiQueue*)malloc(sizeof(LiQueue));
	Q->rear=Q->front=NULL;
}
void enQueue(LiQueue *Q,int x){
	//元素x入队
	LNode *p=(LNode*)malloc(sizeof(LNode));
	p->next=NULL;
	p->data=x;
	if(Q->rear==NULL){
		Q->front=Q->rear=p;//若队列空则p既是队头结点也是队尾结点
	}else{	
		Q->rear->next=p;
		Q->rear=p;//若队列不空则将新节点插入队尾结点后
	}
}
bool deQueue(LiQueue *q,int &x){
	//出队
	if(q->rear==NULL)return false;
	LNode *p;
	p=q->front;
	x=p->data;
	if(q->rear==q->front)
		q->front=q->rear=NULL;//若队中只有一个结点则出队时需对队尾操作
	else
		q->front=p->next;
	
	free(p);
	return true;
}
int main(){
	LiQueue *lqu;
	initQueue(lqu);
	enQueue(lqu,1);
	enQueue(lqu,2);
	int x;
	enQueue(lqu,3);
	deQueue(lqu,x);
	cout<<x<<endl;
	deQueue(lqu,x);
	cout<<x<<endl;
}
