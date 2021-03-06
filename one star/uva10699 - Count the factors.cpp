#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		printf("%d : ",n);
		int maxP = int(sqrt(n - 1e-9))+1;
		int count=0;
		for(int p=2;p<=maxP;++p){
			if(n%p==0){
				++count;
				while(n%p==0) n/=p;
			}
		}
		//若n尚未變為1，表示尚存在一個大於根號n的質數為其因數，再將質因數個數加一
		if(n!=1) ++count;
		printf("%d\n",count);
	}
}
