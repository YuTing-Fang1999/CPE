#include <iostream>
using namespace std;

// ��coin exchange�Z����
// �`�@�����brick 
// brick��1�Pbrick��2
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
