#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin>>N && N){
		int ans = 0;
		for(int i=1;i<=N;++i) ans+=i*i;
		//ans = N(N+1)(2N+1) / 6
		cout<<ans<<endl;
	}
	
	return 0;
}
