//矩阵的压缩存储
//稀疏矩阵的三元组存储
#include<iostream>
#define Maxsize 5
#define Maxteams 25
using namespace std;
void createtrimat(int A[][Maxsize],int m,int n,int B[][3]){
	//m为A矩阵行数，n为A矩阵列数，B为三元组
	int k=1;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j){
			if(A[i][j]!=0){
				B[k][0]=A[i][j];
				B[k][1]=i;
				B[k][2]=j;
				++k;//找到非零元素，将非零元素的值与位置保存在三元组中
			}
		}
		B[0][0]=k-1;
		B[0][1]=m;
		B[0][2]=n;//将矩阵A的行数列数以及非零元素的个数保存在三元组中
}
void print(int B[][3]){
	//打印三元组
	int k=1;
	for(int i=0;i<B[0][1];++i){
		for(int j=0;j<B[0][2];++j){
			if(i==B[k][1]&&j==B[k][2]){
				cout<<B[k][0]<<"\t";
				++k;
			}
			else
				cout<<0<<"\t";
		}
		cout<<endl;
	}
	//cout<<"over!"<<endl;
}	
bool search(int B[][3],int x){
	for(int i=1;i<=B[0][0];++i)
		if(B[i][0]==x)
			return true;
		return false;
}
void transpose(int A[][3],int B[][3]){
	//计算A的转置矩阵B，A，B均用三元组表示
	//不能简单的将A中元素的行与列互换，，A中的元素为原矩阵按照行优先存储的结果
	//正确做法，互换三元组中各个元素的行下标与列下表，并将其按照原矩阵列优先的顺序存储
	//画图可知：新矩阵中第一行的元素为原矩阵中第一列的元素，并且新元素的下标为原元素的下标互换位置
	int p,q,col;
	B[0][0]=A[0][0];
	B[0][1]=A[0][2];
	B[0][2]=A[0][1];
	if(B[0][0]>0){
		for(col=0;col<B[0][1];++col){
		//原矩阵的列优先存储
			for(p=1;p<B[0][0];++p){
				if(A[p][2]==col){
					B[q][0]=A[p][0];
					B[q][1]=A[p][2];
					B[q][2]=A[p][1];
					++q;
				}
			}
		}
	}
}
void add(int A[][3],int B[][3],int C[][3]){
	//依次遍历A的行号和列号，
	//若A的行号小于B的行号，则将A的元素存入C中，
	//若A的行号等于Ｂ的行号，则比较AB的列号：若列号相等，将元素相加存入C；否则将列号较小的元素存入C
	//若A的行号大于B的行号，则将B的元素存入C中
	//注：Ａ　Ｂ　Ｃ均是矩阵的三元组存储结构
	int i=1,j=1,m;
	int k=1;
	while(i<=A[0][0]&&j<=B[0][0]){
		if(A[i][1]<B[j][1]){
			//若Ａ中第一个元素行号比Ｂ中第一个小（三元组是按行优先存储顺序存储）Ｂ中与A第一个元素下标对应的元素为0
			C[k][0]=A[i][0];
			C[k][1]=A[i][1];
			C[k][2]=A[i][2];
			++k;
			++i;//A中第一个元素处理完后，就处理Ａ的第二个元素，还是与Ｂ中当前元素比较。　　这样当处理完毕后，Ａ　或Ｂ中剩余元素一定在处理过的元素之后，直接给Ｃ就行了
		}
		else if(A[i][1]>B[j][1]){
			C[k][0]=B[j][0];
			C[k][1]=B[j][1];
			C[k][2]=B[j][2];
			++k;
			++j;//作用同上
		}
		else if(A[i][1]==B[j][1]){
			//行标相同则比较列标
			if(A[i][2]<B[j][2]){
				C[k][0]=A[i][0];
				C[k][1]=A[i][1];
				C[k][2]=A[i][2];
				++k;
				++j;
			}else if(A[i][2]>B[j][2]){
				C[k][0]=B[j][0];
				C[k][1]=B[j][1];
				C[k][2]=B[j][2];
				++k;
				++j;
			}else{
				//Ａ　Ｂ中的当前元素行标列表均相同
				m=A[i][0]+B[j][0];//若元素之和不为０，则将和存入Ｃ中；为０则不存入三元组，并处理ＡＢ中的下一元素
				if(m){
					C[k][0]=m;
					C[k][1]=A[i][1];
					C[k][2]=A[i][2];
					++k;
					++j;
					++i;
				}else{
					++i;
					++j;
				}
			}
		}
	}//循环结束后，Ａ或Ｂ中可能存在剩余元素
	while(i<=A[0][0]){
		C[k][0]=A[i][0];
		C[k][1]=A[i][1];
		C[k][2]=A[i][2];
		++k;
		++i;
	}
	while(j<=B[0][0]){
		C[k][0]=B[j][0];
		C[k][1]=B[j][1];
		C[k][2]=B[j][2];
		++k;
		++j;
	}
	//处理完Ａ　Ｂ中的所有元素后，Ｃ[0][0],C[0][1],Ｃ[0][2]
	C[0][0]=--k;
	C[0][1]=A[0][1];
	C[0][2]=A[0][2];

}

int main(){
	int  A[Maxteams+1][3];
	int  B1[Maxteams+1][3];
	int  B2[Maxteams+1][3];
	int  C[5][5];
	int  D[5][5];
	for (int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			if(i==j){
				D[i][j]=1;
				C[i][j]=2;
			}else{
				D[i][j]=0;
				C[i][j]=0;		
			}//创建两个初等矩阵
	createtrimat(C,5,5,B1);
	createtrimat(D,5,5,B2);
	add(B1,B2,A);
	cout<<"C:"<<endl;
	print(B1);
	cout<<"D:"<<endl;
	print(B2);
	cout<<"C+D:"<<endl;
	print(A);	
}
