#include<iostream>
using namespace std;

//通过迭代返回n！
int  recursion1(int n){
	//递归出口
	if(n==1)return 1;
	return recursion1(n-1)*n;
}
//通过迭代返回1+2+``````+n
int recursion2(int n){
	//递归出口
	if(n==1)return 1;
	//函数关系
	return recursion2(n-1)+n;
}
//通过递归返回数组前n项和
int recursion3(int array[],int n){
	//递归出口
	if(n==0)return array[0];
	return recursion3(array,n-1)+array[n];
}
int  main(){
	int n[]={1,2,3,4,5,6,7,8,9,10};
	cout<<"3！="<<recursion1(3)<<endl;
	cout<<"1+2+3+4+5="<<recursion2(5)<<endl;
	cout<<"{1,2,3,4,5,6,7,8,9,10}数组和："<<recursion3(n,9 )<<endl;
}
