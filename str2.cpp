//串的变长存储方式
#include<iostream>
#include<cstdlib>
using namespace std;
struct Str{
	char *ch=(char*)malloc(sizeof(char));
	int length;
};
bool Strassign(Str &S,char *ch){
	//传入的是字符数组的首地址   ch[]=""
	if(S.ch){
		free(S.ch);//释放原串空间
		S.ch=NULL;
	}
	int len=0;
	char *c;
	c=ch;
	while(*c){//求出串长
		++len;
		++c;
	}
	if(len==0){
		//若串长为0则直接返回空串
		S.ch=NULL;
		S.length=0;
		return true;
	}else{
		//若串长不为0，则复制
		S.ch=(char*)malloc((len+1)*sizeof(char));//取len+1是为了多分配一个空间存放'\0'
		if(!S.ch){
			return false;}
		else{
			c=ch;
			for(int i=0;i<=len;++i,++c)S.ch[i]=*c;
			S.length=len;
		return true;
		}
	}
}
int Strlength(Str S){return S.length;}
bool concat(Str &str,Str str1,Str str2){
	//将str1与str2组合为新的串str
	if(str.ch){
		free(str.ch);//释放原串空间
		str.ch=NULL;}
	str.ch=(char*)malloc((str1.length+str2.length+1)*sizeof(char));//多分配一个空间是为了存储'\0'
	if(!str.ch)return false;
	int i=0;
	int j=0;
	while(i<str1.length){
		str.ch[i]=str1.ch[i];
		++i;
	}
	while(j<=str2.length){
		str.ch[i+j]=str2.ch[j];
		++j;//将str2结尾的'\0'一块存入串中
	}
	str.length=str1.length+str2.length;//新串长度
	return true;
}
void func1(Str &s1,char ch1,char ch2){
	//综合应用1.1
	//将串中所有值为ch1的字符转换成ch2的字符，如果str为空串或者串中不含值为ch1的字符，do nothing
	if(!s1.ch)return ;
	char *c=s1.ch;
	while(*c){
		*c==ch1?*c=ch2:*c;
		++c;
	}
}
void func2(Str &str){
	//综合应用1.2
	//实现串的逆转函数，若str为空串则do nothin
	int i=0;
	int j=str.length-1;
	char temp;
	if(!str.ch)return ;
	while(i<j){
		temp=str.ch[i];
		str.ch[i]=str.ch[j];
		str.ch[j]=temp;
		++i;
		--j;
	}
}
void func3_1(Str&str,char ch){
	//解法1
	//删除str中值为ch的字符
	if(!str.ch)return;
	char *c=str.ch;
	int i=0;
	int j;
	while(i<str.length){
		if(str.ch[i]==ch){
			for(j=i+1;j<str.length;j++)str.ch[j-1]=str.ch[j];
			--str.length;
		}else
			++i;
		
	}
}
void func3_2(Str&str,char ch){
	//解法2
	int sum=0;//需要被删除的元素的个数
	int i;
	int j;
	for(i=0;i<str.length;++i)
		str.ch[i]==ch?++sum:i;//求被删除的字符的个数
	if(sum){
		char *temp_ch=(char*)malloc(sizeof(char)*(str.length-sum+1));
		for(i=0,j=0;i<=str.length;++i)
			str.ch[i]!=ch?(temp_ch[j++]=str.ch[i]):i;//将不需要删除的字符复制到新空间上
		free(str.ch);
		str.ch=temp_ch;
		str.length=str.length-sum;
	}
}
void func3_3(Str&str,char ch){
	//解法三，（2的升级版）
	//Ps：可理解为“一段一段的移动”
	if(!str.length){
		int ch_num=0;//记录串中元素需要前移几个单位（第一次前移1个，则第二个ch前有一个空格，所以第二个ch到第三个ch之间的元素需前移三个单位，以此类推）
		int i=0;//用于对主串遍历
		int j;//用于元素后移
		while(str.ch[i]){
			if(str.ch[i]==ch){
				++ch_num;
				for(j=i+1;str.ch[j]!=ch&&str.ch[j]!='\0';++j)
					str.ch[j-ch_num]=str.ch[j];//for循环结束条件：串中与目标字符相同的元素的下一元素为ch
				i=j;
				--str.length;
			}else{
				++i;
			}
		}
	}
	str.ch[str.length]='\0';
}
int main(){
	Str s1;
	Str s2;
	Str s3;
	char c[]="yangtjjjantjan";
	char b[]="jin";
	char sss[]="ddd";
	Strassign(s1,c);
	int i;
	for(i=0;i<s1.length;i++)cout<<s1.ch[i];
	cout<<"s1串长"<<Strlength(s1)<<endl;
	Strassign(s2,b);
	//Strassign(s3,sss);
	concat(s3,s1,s2);
	cout<<"s3=s1+s2连接后：";
	for(i=0;i<s3.length;i++)cout<<s3.ch[i];
	cout<<endl;
	func1(s1,'j','i');
	//将s1中所有j变为i
	cout<<"将s1中所有j变为i:";
	for(i=0;i<s1.length;++i)cout<<s1.ch[i];
	cout<<endl;
	//将s2逆转
	func2(s2);
	cout<<"s2逆转:";
	for(i=0;i<s2.length;++i)cout<<s2.ch[i];
	cout<<endl;
	//删除s1中值为i的字符
	//func3_1(s1,'i');
	func3_2(s1,'i');
	cout<<"删除s1中值为i的字符"<<endl;
	cout<<"s1:";
	for(i=0;i<s1.length;++i)cout<<s1.ch[i];
	cout<<endl;

}
