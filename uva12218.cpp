#include <iostream>
#include <string>
using namespace std;

int T;
string N;
bool Swin;
int i,j;
int CASE = 0;

bool canMove(int len){
	for(i=0;i<N.size();++i){
		if(N[i]=='0') continue;
		
		int num = 0;
		for(j=0;j<N.size();++j){
			if(j==i) continue;
			num+=N[j]-'0';
		}
		if(num%3==0 || len==1){//can move
			N[i]='0';
			Swin = !Swin;
			return true;
		}
	}
	return false;
}
int main(){
	cin>>T;
	while(T--){
		cin>>N;
		Swin = false;
		int len = N.size();
		while(canMove(len)){
			--len;
		}
		printf("Case %d: ",++CASE);
		if(Swin) cout<<'S'<<endl;
		else cout<<'T'<<endl;
	}
	return 0;
}
