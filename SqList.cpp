#include<iostream>
#include<stdlib.h>
typedef int ElemType;
#define SqList_length 10
using namespace std;
struct SqList{
	ElemType *data;
	int length;
};
//构造一个空顺序表
void InitSqList(SqList &L){
	L.data=(ElemType*)malloc(SqList_length*sizeof(ElemType));
	L.length=0;
}
//在顺序表指定位置p插入元素e
bool InsertElem(SqList &L,ElemType e,int p){
	//插入位置不合法,返回失败
	if(L.length==SqList_length||p<0||p>SqList_length-1)return false;
	int i;
	for(i=L.length-1;i>=p;i--){
		L.data[i+1]=L.data[i];
	}
	L.data[p]=e;
	L.length++;
	return true;
}
//在顺序表指定位置p的元素，并通过e返回
bool DeleteElem(SqList &L,int p,ElemType &e){
	//删除位置不合法返回False
	if(p<0||p>L.length-1||L.length==0)return false;
	int i;
	e=L.data[p];
	for(i=p+1;i<L.length;i++){
		L.data[i-1]=L.data[i];
	}
	L.length--;
	return true;
}
//求指定位置元素
bool GetElem(SqList L,ElemType &e,int p){
	//位置不合法返回false
	if(p<0||p>L.length-1)return false;
	e=L.data[p];
	return true;
}

//显示表
void Print(SqList L){
	int i=0;
	cout<<"表：";
	while(i<L.length){
		cout<<L.data[i]<<'\t';
		i++;
	}
	cout<<endl;
}
int main(){
	SqList L;
	InitSqList(L);
	Print(L);
	InsertElem(L,1,0);
	InsertElem(L,2,1);
	InsertElem(L,3,2);
	InsertElem(L,4,3);
	Print(L);
	ElemType e;
	DeleteElem(L,1,e);
	cout<<e<<endl;
	Print(L);
	GetElem(L,e,1);
	cout<<e<<endl;
}
