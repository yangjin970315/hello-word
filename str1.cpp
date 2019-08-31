//定长
#include<iostream>
#define MaxSize 10
using namespace std;
struct Str{
	char ch[MaxSize+1];//需要一个多一个存储空间存放‘0’
	int length;
};
bool strassign(Str &S,char *ch){
	int len=0;
	char *c=ch;
	while(*c){//求ch串长
		++len;
		++c;
	}
	if(len>MaxSize)return false;
	if(len==0){
		S.length=0;
		return true;
	}else{
		c=ch;
		for(int i=0;i<=len;i++)
			S.ch[i]=*(c++);//将结尾的'\0'一起存入串中
		S.length=len;
		return true;
	}

}
int main(){
	Str s;
	char ch[]="ababababa";
	strassign(s,ch);
	for(int i=0;i<s.length;++i)cout<<s.ch[i];
}
