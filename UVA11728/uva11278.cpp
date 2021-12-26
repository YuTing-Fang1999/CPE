#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int S[1001]; 
	memset(S,0,sizeof(S));
	int c=0;
	//因為算出sum of factor比較簡單，所以先算完再逆推 
	//因為sum of factor一定比自己大，所以算到1000即可 
	for(int i=1;i<=1000;++i){
		for(int j=1;j<=i;++j){
			if(i%j==0){
				S[i] += j;
			}
		}
		
	}
	int n;
	while(cin>>n && n){
		int idx=1000;
		while(idx--){
			if(S[idx] == n) break;
		}
		printf("Case %d: ",++c);
		if(idx) cout<<idx<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
