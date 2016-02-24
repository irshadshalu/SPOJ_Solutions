#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int k,n=0,res,l;
	char stack[2010];
	while(1){
		n++;
		cin>>s;
		if(s[0]=='-')
			break;
		k=0;res=0;l=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='{'){
				l++;
			}
			else if(s[i]=='}'){
				l--;
				if(l<0){
					res++;
					l=1;
				}
			}
		}
		cout<<n<<". "<<res+l/2<<'\n';
	}
}
