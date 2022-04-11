#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// N = 10*M + i (i=0~9)
// X = N - M = 10*M + i - M = 9*M + i
// (X-i) % 9 = 0

long long X,N,M;
int main(){
	while(cin>>X && X){
		vector< long long > ans;
		for(int i=0;i<=9;++i){
			if((X-i)%9 == 0){
				M = (X-i) / 9;
				N = 10*M + i;
				ans.push_back(N);
			}
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();++i){
			if(i>0) printf(" ");
			printf("%lld",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
