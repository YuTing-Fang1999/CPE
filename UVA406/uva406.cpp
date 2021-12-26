#include <iostream>
#include <vector>
using namespace std;

vector<int> PRIME;
vector<int> LEN;
int main(){
	int N,C;
	//init
	PRIME.push_back(1);
	PRIME.push_back(2);
	LEN.push_back(0);
	LEN.push_back(1);
	LEN.push_back(2);
	while(cin>>N>>C){
		printf("%d %d:",N,C);
		//fing prime
		for(int i=LEN.size();i<=N;++i){
			bool isPrime = true;
			for(int j=1;j<PRIME.size();++j){
				if(i%PRIME[j] == 0) {
					isPrime = false;
					break;
				}
			}
			if(isPrime) PRIME.push_back(i);
			LEN.push_back(PRIME.size());
		}
		//fing boundary
		--C;
		int a = (LEN[N])/2-C-(LEN[N]%2==0);
		if(a<0) a=0;
		int b = (LEN[N])/2+C;
		if(b>=LEN[N]) b=LEN[N]-1;
		//output
		for(int i=a; i<=b; ++i){
			cout<<" "<<PRIME[i];
		}
		cout<<endl<<endl;
	}
	return 0;
}
