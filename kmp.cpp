#include<iostream>
#include<cstdlib>
#define Maxsize 15
using namespace std;
struct Str{
	char *ch=(char*)malloc(sizeof(char));
	int length;
};
bool strassign(Str &S,char *ch){
	if(S.ch)
		free(S.ch);
	char *c=ch;
	int len=0;
	while(*c){
		++len;
		++c;
	}
	if(len==0){
		S.ch=NULL;
		S.length=0;
		return true;
	}else{
		S.ch=(char*)malloc(sizeof(char)*(len+2));
		if(S.ch==NULL)return false;
		int i;
		for(i=0;i<=len;++i)S.ch[i+1]=ch[i];
		S.length=len;
	return true;
	}

}
void getnext(Str substr,int next[]){
	int j=0,i=1;
	next[1]=0;
	while(i<substr.length+1){
		if(j==0||substr.ch[i]==substr.ch[j]){
			++i;
			++j;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
}
int kmp(Str str,Str substr,int next[]){
	//若匹配失败，则返回一个可区别于主串所有位置的标记，如0
	//若匹配成功，则返回模式串在主串中的位置
	int i,j;
	i=1;
	j=1;
	while(i<=str.length&&j<=substr.length){//此处需完整比较主串中的每一个字符，与简单模式匹配有区别
		if(j==0||str.ch[i]==substr.ch[j]){//主串i后移的条件是前面发生匹配或模式串与主串的第一个字符不匹配
			++i;
			++j;
		}else{
			j=next[j];
		}
	}
	if(j>substr.length)
		return i-substr.length;
	else 
		return 0;
}
int main(){
	Str s1,s2,s3;
	int next[Maxsize];
	char a[]="ababcacacbab";
	char b[]="ababaab";
	strassign(s1,a);
	strassign(s2,b);
	getnext(s2,next);
	int flag;
	flag=kmp(s1,s2,next);
	if(flag)
		cout<<"index:"<<flag<<endl;
	else
		cout<<"none"<<endl;

}
