//if N <= 100, then f91(N) = f91( f91( N+11) )
//if N >= 101, then f91(N) = N-10
//狦计单101钡-10
//狦计单100程﹚穦101~111ぇ丁
//狦111f91( f91(111) ) = f91( 101 ) = 91
//安块獶111ㄒ105穦ぃ耞狡+11籔-10跑Θ111程临琌穦块91 
#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin>>N && N){
		if(N>=101) printf("f91(%d) = %d\n", N, N-10);
		else printf("f91(%d) = 91\n",N);
	}
	return 0;
}
