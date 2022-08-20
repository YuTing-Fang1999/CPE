#include <iostream>
using namespace std;
// 4 個點，最多有(4*3)/2 = 6 條邊可以連
// 每棵樹至少要連3條邊，用掉後剩下的棵樹就不可再使用此條邊 
// 最多可以有6/3棵樹
// ans = [N*(N-1)/2] / (N-1) = N/2 
int N, CASE = 1;
int main(){
	while(cin>>N && N){
		printf("Case %d: %d\n", CASE++, N/2);
	}
	return 0;
} 
