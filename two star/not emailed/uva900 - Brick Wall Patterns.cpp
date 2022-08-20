#include <iostream>
using namespace std;

// 跟coin exchange蠻像的
// 總共有兩種brick 
// brick數1與brick數2
// [3] = [2]+1 = [1]+2

int main(){
	long long int ways[55]={0};
	ways[1]=1;
	ways[2]=2;
	for(int i=3;i<55;++i) ways[i]=ways[i-1]+ways[i-2];
	
	int N;
	while(cin>>N && N) printf("%lld\n",ways[N]);	
	
	return 0;
}
