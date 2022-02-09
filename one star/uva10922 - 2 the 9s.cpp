#include <iostream>
#include <string>
using namespace std;

int degree(int N,int d){
	if(N==9) return d+1;
	if(N%9) return d;
	int n=0;
	while(N){
		n+=N%10;
		N/=10;
	}
	return degree(n,d+1);
}

string str;
int main(){
	while(cin>>str && str!="0"){
		int N=0;
		for(int i=0;i<str.size();++i) N+=str[i]-'0';
		int d=degree(N,0);
		if(d) printf("%s is a multiple of 9 and has 9-degree %d.\n",str.c_str(),d);
		else printf("%s is not a multiple of 9.\n",str.c_str());
	}
	return 0;
}
