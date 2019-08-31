#include<iostream>
using namespace std;
#define MaxSize 5//队列长度
struct queue{
	int data[MaxSize];
	int front,rear;
};
void initqueue(queue &q){
	q.front=q.rear=0;
}
bool enqueue(queue &q,int x){
	//入队列
	if((q.rear+1)%MaxSize==q.front)
		return false;
	q.rear=(q.rear+1)%MaxSize;
	q.data[q.rear]=x;
	return true;
}
bool dequeue(queue &q,int &x){
	//出队列
	if(q.rear==q.front)
		return false;
	q.front=(q.front+1)%MaxSize;
	x=q.data[q.front];
	return true;
}
int main(){
	queue q;
	int x;
	initqueue(q);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	dequeue(q,x);
	cout<<x<<endl;
	dequeue(q,x);
	cout<<x<<endl;
}
