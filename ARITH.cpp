// Irshad PI, GECTCR 
// about any  doubts, contact : irshadpi77@gmail.com
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
//prints hyphon for required length
#define printh(n) {for(int gg=0;gg<n;gg++) printf("-"); printf("\n");}
//fills the space on left to fit ( like "%nd" for string )
void print(string a,int n){
	int l=a.length();
	FOR(i,0,n-l-1)
		printf(" ");
	cout<<a<<'\n';
}
// returns sum of two numbers represented as a string, common by hand logic
string sum(string a,string b){
	int m=a.length(),n=b.length(),maxL,minL;
	maxL=max(m,n);
	minL=min(m,n);
	string res,temp;
	res.resize(maxL);
	temp.resize(maxL-minL);
	FOR(i,0,maxL-minL-1)
		temp[i]='0';
	if(m==minL)
		a=temp+a;
	else
		b=temp+b;
	int carry=0;
	RFOR(i,maxL-1,0){
		if((a[i]+b[i])-2*'0'+carry>9){
			res[i]=(carry+(a[i]+b[i])-2*'0')%10+'0';
			carry=(carry+(a[i]+b[i])-2*'0')/10;
		}
		else{
			res[i]=(carry+a[i]+b[i])-'0';
			carry=0;
		}
	}
	if(carry){
		string temp2="0";
		temp2[0]=(char)(carry+'0');
		res=temp2+res;
	}
	return res;
}
string sub(string a,string b){ // return a-b
	int m=a.length(),n=b.length(),maxL,minL;
	maxL=max(m,n);
	minL=min(m,n);
	string res,temp;
	res.resize(maxL);
	temp.resize(maxL-minL);
	FOR(i,0,maxL-minL-1)
		temp[i]='0';
	if(m==minL)
		a=temp+a;
	else
		b=temp+b;
	int borrow=0;
	RFOR(i,maxL-1,0){
		if((a[i]-b[i])-borrow<0){
			res[i]=(10+(a[i]-b[i])-borrow)%10+'0';
			borrow=1;
		}
		else{
			res[i]=(a[i]-b[i]-borrow)+'0';
			borrow=0;
		}
	}
	int k;
	for(k=0;res[k]=='0';k++);
	res=res.substr(k,res.length());
	return res;
}
// returns a string multiplied by an integer,uses sum()
string multn(string s,int n){
	string res;
	int m=s.length();
	res.resize(m);
	FOR(i,0,m-1) res[i]='0';
	FOR(i,0,n-1)
		res=sum(res,s);
	int k=0;
	for(k=0;k<res.length()&&res[k]=='0';k++);
	if(k==res.length())
		res="0";
	return res;
}
// returns product of two numbers as string, uses sum() and multn()
string mult(string a,string b){
	int m=a.length(),n=b.length();
	string res;
	res.resize(m);
	FOR(i,0,m-1) res[i]='0';
	string tem;
	RFOR(i,n-1,0){
		tem=multn(a,b[i]-'0');
		FOR(j,0,n-i-2)
			tem=tem+"0";
		res=sum(res,tem);
	}
	return res;
}
int main(){
	long t,n,i,j;
	string a,b,temp;
	char opr;
	cin>>t;
	while(t--){
		cin>>temp;
		if(temp.find('+')!=string::npos){
				opr='+';
				a=temp.substr(0,temp.find('+'));
				b=temp.substr(temp.find('+')+1,temp.length());
				string res=sum(a,b);
				int m=max(res.length(),b.length()+1);
				print(a,m);
				print("+"+b,m);
				printh(m);
				print(res,m);
			}
		else if(temp.find('-')!=string::npos){
				opr='-';
				a=temp.substr(0,temp.find('-'));
				b=temp.substr(temp.find('-')+1,temp.length());
				string res=sub(a,b);
				int m=max(res.length(),b.length()+1);
				print(a,m);
				print("-"+b,m);
				printh(m);
				print(res,m);
			}
		else if(temp.find('*')!=string::npos){
				opr='*';
				a=temp.substr(0,temp.find('*'));
				b=temp.substr(temp.find('*')+1,temp.length());
				string res=mult(a,b);
				int len=res.length(),k=b.length(),l=a.length();
				print(a,len);
				print('*'+b,len);
				int tt=multn(a,b[k-1]-'0').length();
				FOR(i,0,len-1-max(k+1,tt)) printf(" ");
				printh(max(k+1,tt));
				RFOR(i,k-1,0){
					print(multn(a,b[i]-'0'),len+i-(k-1));
				}
				if(k>1){
					printh(len);
					print(res,len);
				}
			}
		printf("\n");
	}
}