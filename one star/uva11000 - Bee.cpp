#include <iostream>
using namespace std;
//母蜂會生一隻公蜂
//公蜂會生一隻公蜂和一隻母蜂
//第一隻母峰不會死 
// F = 1 + m
// M = f + m
// 2^32 = 4294967296
int main(){
	long long int F[50], M[50];
	F[0] = 1, M[0] = 0;
	for(int i=1;i<50;++i){
		F[i] = 1 + M[i-1];
		M[i] = F[i-1] + M[i-1];
	}
	int N;
	while(cin>>N && N>=0){
		printf("%lld %lld\n", M[N], F[N]+M[N]);
	}
	return 0;
}
