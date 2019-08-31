#include<iostream>
using namespace std;
#define MaxSize 20
struct sqstack{
	int data[MaxSize];
	int top;
};
void initstack(sqstack&S){
	S.top=-1;//栈空的标志为栈顶下标为-1
}
bool push(sqstack &S,int x){
	//元素入栈，，先移动栈顶指针，再存入数据
	//判断栈是否满
	if(S.top==MaxSize-1)
		return false;
	S.data[++S.top]=x;//栈顶先往后移动然后将元素x存入栈顶位置
	return true;
}
bool pop(sqstack&S,int &x){
	//栈顶元素出栈，并将出栈弹出的元素用x返回
	//判断栈是否空
	if(S.top==-1)
		return false;
	x=S.data[S.top--];//将栈顶元素取出同时栈顶指针减一
	return true;
}
bool gettop(sqstack S,int &x){
	if(S.top==-1)
		return false;
	x=S.data[S.top];
	return true;
}
int main(){
	sqstack S;
	initstack(S);
	push(S,1);
	push(S,2);
	int x;
	gettop(S,x);
	cout<<x<<endl;
	pop(S,x);
	cout<<x<<endl;
	gettop(S,x);
	cout<<x<<endl;
}
