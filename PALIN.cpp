// Irshad PI, GECTCR 
// about any  doubts, contact : irshadpi77@gmail.com
#include<iostream>
#include<string>
using namespace std;
string s,res;
long int n,KK;
// adds one to the first half of string
void addone(){
    int k;
    for(k=(n-1)/2;k>=0 && s[k]=='9';k--)
        s[k]='0';
    if(k>=0)
        s[k]++;
    else{  // means all digits are nine
        s="1"+s;
        n+=1;
    }
}
// to compare first and second half
int compare(int i){
  //  cout<<s[i]<<" "<<s[n-i-1]<<'\n';
    if(i<0)
        return -1;
    if(s[i]<s[n-i-1])
        return -1;
    if( s[i]>s[n-i-1])
        return i;
   else if(s[i]==s[n-i-1])
       KK--;
    return compare(i-1);
}
int main(){
	long long int T,i,j;
    string res;
    cin>>T;
    while(T--){
        cin>>s;
        res=s;
        n=s.length();
        KK=(n-1)/2;
            if(compare((n-1)/2)<0 )
                addone();
            res.resize(n);
            for(j=(n-1)/2;j>=0;j--){
                res[j]=res[n-j-1]=s[j];
            }
        cout<<res<<"\n";
    }
}