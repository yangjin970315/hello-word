#include<iostream>
#include<stdlib.h>
using namespace std;
struct SqList{
	int data[10];
	int length;
};
void Print(SqList L){
	int i=0;
	cout<<"表：";
	while(i<L.length)cout<<L.data[i++]<<'\t';
	cout<<endl;
}
void InitSqList(SqList&L){
	int i=0;
	while(i<10){
		L.data[i]=rand()%50;
		i++;
	}
	L.length=10;
}
//使表中比表头元素大的元素在表的后半部分，小的在表的前半部分
void quicksort(SqList &L){//L要改变，所以用引用型

	int temp;
	int i,j;
	temp=L.data[0];
	i=0;
	j=L.length-1;
	while(i<j){
		while(i<j&&L.data[j]>temp)j--;//找到后半部分比temp小的元素；此时j为该不合格元素的下标
		if(i<j){
			L.data[i]=L.data[j];
			i++;
		}

		while(i<j&&L.data[i]<temp)i++;//找到前半部分比temp大的元素：此时i为该不合格元素的下标；并且满足i<j，不满足i<j的话说明此时i=j（说明下标为i的元素左边均比temp小，右边...)
		if(i<j){
			L.data[j]=L.data[i];
			j--;
		}
	}
	L.data[i]=temp;
}

int main(){
	SqList L;
	InitSqList(L);
	Print(L);
	quicksort(L);
	Print(L);
}
//快速排序可以理解为一开始data[0]是空的（因为值已经被temp保存）

//从右向左遍历，找到比temp小的元素，将该元素的值存放到”空的地方“（下标为i的元素）；此时该元素变为“空的地方”
//从左向右遍历，找到比temp大的元素，将该元素的值存放的“空的地方”（下标为j的元素）；此时该元素变为“空的地方”
//循环执行上述两过程，直到从左（右）向右（左）的过程中i（j）变为“空的地方”的元素下标，将temp的值存放在该处，表又完整了！！

//notes：在找不合格元素下标时，结束while循环有两种方式。其1是找到不合格元素；另一个则是i==j
//       因此后面赋值操作若不加条件的话还会进行无意义的操作，因为i==j时，不应进行任何操作

