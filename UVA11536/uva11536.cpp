#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector< int > X;
int T,N,M,K,a,minLen,cnt[105],num;

int main(){
	cin>>T;
	for(int t=1;t<=T;++t){
		cin>>N>>M>>K; 
		//init
		a=0; num=0; minLen=1e8;
		memset(cnt,0,sizeof(cnt));
		X.assign(N,0);
		X[0] = 1; X[1] = 2; X[2] = 3;
		for(int i=3;i<N;++i) X[i]=(X[i-1]+X[i-2]+X[i-3])%M+1;
		//
		for(int i=0;i<N;++i){
			if(X[i]<=K) {
				if(++cnt[X[i]]==1) num++;
				
				while(cnt[X[a]]>1) {
				  //beware the order
				  cnt[X[a]]--; a++; 
				  //
				  while(X[a]>K) a++;
				}
				
				if(num==K) minLen = min(minLen,i-a+1);
			}
			
		}
	
		printf("Case %d: ",t);
		if(minLen>N) printf("sequence nai\n");
		else cout<<minLen<<endl;
	}
	return 0;
}
