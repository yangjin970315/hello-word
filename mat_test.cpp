#include<iostream>
using namespace std;
#define Maxsize 5


void mutmat(int A[][Maxsize],int B[][Maxsize],int C[][Maxsize],int m,int n,int k){
	//矩阵乘法
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j){
			C[i][j]=0;
			for(int h=0;h<k;++h)
				C[i][j]+=A[i][h]*B[h][j];
		}
}





void movelement(int A[],int n){
//--------------------------------------------------------------------------------//
	//算法：将A中的所有非零元素移动到A的前端
	//从左到右扫描整个数组，发现非零元素时使其尽可能与靠左边的零元素进行互换
	//需要特殊考虑的就是数组前有连续的元素非零
	int i=-1,j,temp;
	for(j=0;j<n;++j)
		if(A[j]!=0){
			++i;//i后移-------发现非零元素，则i后移，说明i的增量即为A中非零元素的个数
			if(i!=j){
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
}//此算法，在j后移时，找到非零元素就会将i+1
//若此时i=j，说明j的左边并没有零，A中前j+1个元素皆非零，因此不需要互换位置，
//若此时i！=j（即i<j）说明j当前位置前的元素有0
//A[i]与A[j]互换后，A[i]左侧一定有0，因此若后面还有非零元素的话即可互换
//发现非零元素，则i后移，说明i的增量即为A中非零元素的个数
//此后重复上述过程直至结束
//------------------------------------------------------------------------------//

int findmax(int A[],int i,int j){
	//通过递归求A中的最大值
	//递归关系：将数组看为两部分，求两部分中较大值
	//递归出口：数组只有一个元素，则本身为最大值
	if(i==j)
		return A[i];
	else{
		int max;
		max=findmax(A,i+1,j);
		if(max>A[i])return max;
		else return A[i];
	}
}
int arraysum(int A[],int i,int j){
	//通过递归求A中元素的和
	//递归关系：将数组看做两部分，求两部分的和
	//递归出口：数组中只有一个元素，本身为和的值
	if(i==j)
		return A[i];
	else
		return A[i]+arraysum(A,i+1,j);
}




//-------------------------------------------------------//
//0  1  2  3  4  5  6
//   1  2  3  4  5  6
//      2  3  4  5  6
//         3  4  5  6
//            4  5  6
//               5  6
//                  6
//(6+5)/2   (4+(6+5)/2*2)/3   ---------可见递归时，平均数的求法应为（后部分平均数×后部分元素个数+前一部分数）/后部分元素个数+1
//-------------------------------------------------------//

float arrayavg(int A[],int i,int j){
	//通过递归求A中元素的平均值
	//递归关系：将数组看做两部分
	//递归出口：数组中只有一个数，这个数本身就是平均值
	if(i==j)
		return (float)A[i];
	else
		return ((float)A[i]+(j-i)*arrayavg(A,i+1,j))/(j-i+1);
}
void divide1(int A[],int n){
	//将数组中的所有奇数移动到偶数之前，且复杂度为O（n）
	int i=0;
	int j=n-1;
	while(i<j){
		while(i<j&&A[i]%2)++i;//找到左边的偶数
		while(i<j&&!(A[j]%2))--j;//找到右边的奇数       出错原因:!运算符的优先级高于%
		if(i<j){
			int temp;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			++i;
			--j;
		}
	}
}
void divide2(int A[],int n){
	//以A[n-1]为轴枢，将数组划分为两部分，right<=A[n-1]   left>A[n-1]
	int i=0,j=n-1;
	int temp=A[n-1];
	while(i<j){
		while(i<j&&A[i]>temp)++i;//找到左边<=A[n-1]的元素的位置
		if(i<j){
			A[j]=A[i];
			--j;
		}
		while(i<j&&A[j]<=temp)--j;//找到左边>temp的元素的位置
		if(i<j){
			A[i]=A[j];
			++i;
		}
	}
	A[i]=temp;
}
void printmin(int A[][Maxsize],int m,int n){
	//统计既是行里面最小的又是列里面最小的，并输出元素的值和位置
	int min1;//行最小
	int i=0;
	int flag;
	int x,y;
	for(;i<m;++i){
		min1=A[i][0];
		x=i;y=0;
		for(int j=1;j<n;++j)
			if(A[i][j]<min1){
				min1=A[i][j];
				y=j;
				}//找到所在行中元素最小的元素
		flag=1;
		for(int j=0;j<m;++j)
			if(min1>A[m][y]){
				flag=0;
				break;//在min1所在列中找到比min1更小的数，说明min1不符合要求
			}
		if(flag)
			cout<<min1<<x<<y<<endl;
	}
}
void printmat(int A[][Maxsize],int m,int n){
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j)
			cout<<A[i][j]<<' ';
		cout<<endl;
	}
}
int main(){
	int A[7];
	for(int i=0;i<7;++i)
		i%2==0?A[i]=1:A[i]=0;//创建一个A数组[1 0 1 0 1 0 1]
	cout<<"A :";
	for(int i=0;i<7;++i)
		cout<<A[i]<<' ';
	cout<<endl;
	movelement(A,7);
	cout<<"A :";
	for(int i=0;i<7;++i)
		cout<<A[i]<<' ';
	cout<<endl;
	for(int i=0;i<7;++i)
		A[i]=i;
	cout<<"A:";
	for(int i=0;i<7;++i)
		cout<<A[i]<<' ';
	cout<<endl;
	cout<<"Max :"<<findmax(A,0,6)<<endl;
	cout<<"Sum: "<<arraysum(A,0,6)<<endl;
	cout<<"Average:"<<arrayavg(A,0,6)<<endl;
	divide1(A,7);
	cout<<"divide A"<<endl;
	cout<<"A:";
	for(int i=0;i<7;++i)
		cout<<A[i]<<' ';
	cout<<endl;
	divide2(A,7);
	cout<<"divide again "<<endl;
	cout<<"A:";
	for(int i=0;i<7;++i)
		cout<<A[i]<<' ';
	cout<<endl;
	int B[5][5];
	int C[5][5];
	int D[5][5];
	for (int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			if(i==j){
				B[i][j]=1;
				C[i][j]=2;
			}else{
				B[i][j]=0;
				C[i][j]=0;		
			}//创建两个初等矩阵

	cout<<'B'<<endl;
	printmat(B,5,5);
	cout<<'C'<<endl;
	printmat(C,5,5);
	mutmat(B,C,D,5,5,5);
	cout<<"B*C"<<endl;
	printmat(D,5,5);

}
