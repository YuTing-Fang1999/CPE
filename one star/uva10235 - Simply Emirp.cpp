#include <iostream>
#include <cmath>
using namespace std;
//這題N的範圍太大了無法用質數篩
//注意emirp is "different" Prime when its digits are reversed

int N;

int reverseNum(int n){
	int n2=0;
	while(n){
		n2*=10;
		n2+=n%10;
		n/=10;
	}
	return n2;
}

bool isPrime(int N){
	for(int i=2;i<=sqrt(N);++i){
		if(N%i==0) return false;
	}
	return true;
}
int main(){
	while(cin>>N){
		if(isPrime(N)){
			
			int N2=reverseNum(N);
//			cout<<N2<<endl;
			if(isPrime(N2) && N!=N2) printf("%d is emirp.\n",N);
			else printf("%d is prime.\n",N);
			
		}else printf("%d is not prime.\n",N);
	}
	return 0;
}
