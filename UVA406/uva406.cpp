#include <iostream>
#include <vector>
using namespace std;

vector<int> PRIME;
int len[1001] = {0};
int main(){
	int N,C;
	//init
	PRIME.push_back(1);
	PRIME.push_back(2);
	len[1] = 1; len[2] = 2;
	while(cin>>N>>C){
		printf("%d %d:",N,C);
		//fing prime
		for(int i=PRIME.back()+1;i<=N;++i){
			bool isPrime = true;
			for(int j=1;j<PRIME.size();++j){
				if(i%PRIME[j] == 0) {
					isPrime = false;
					break;
				}
			}
			if(isPrime) PRIME.push_back(i);
			len[i] = PRIME.size();
		}
		//fing boundary
		--C;
		int a = (len[N])/2-C-(len[N]%2==0);
		if(a<0) a=0;
		int b = (len[N])/2+C;
		if(b>=len[N]) b=len[N]-1;
		//output
		for(int i=a; i<=b; ++i){
			cout<<" "<<PRIME[i];
		}
		cout<<endl<<endl;
	}
	return 0;
}
