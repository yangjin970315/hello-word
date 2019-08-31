#include<iostream>
#include<cstdlib>
using namespace std;
struct Str{
	char *ch=(char*)malloc(sizeof(char));
	int length;
};
bool strassign(Str&S,char *ch){
	if(S.ch)
		free(S.ch);
	char *c=ch;
	int len=0;
	while(*c){
		++c;
		++len;
	}
	if(!len){
		S.ch=NULL;
		S.length=0;
		return true;
	}else{
		S.ch=(char*)malloc(sizeof(char)*(len+2));
		int i=1;
		for(i;i<=len+1;i++)S.ch[i]=ch[i-1];
		S.length=len;
		return true;
	}
}
int index(Str str,Str substr){
	int i=1;
	int j=1;
	int k=i;
	while(j<=substr.length&&i<=str.length-substr.length+1){
		if(str.ch[i]==substr.ch[j]){
			++i;
			++j;
		}else{
			i=++k;
			j=1;
		}
	}
	if(j<substr.length)
		return 0;
	else
		return i-j+1;
}
int main(){
	Str s1,s2,s3;
	char a[]="ababcacacbab";
	char b[]="abcac";
	strassign(s1,a);
	strassign(s2,b);
	int flag;
	flag=index(s1,s2);
	if(flag)
		cout<<"index:"<<flag<<endl;
	else
		cout<<"none"<<endl;

}
