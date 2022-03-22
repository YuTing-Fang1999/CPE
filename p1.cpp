#include <iostream>
using namespace std;

int main(){
	long long s;
	while(cin>>s && s){
		long long page = 0;
		long long tot = 0;
		long long lose;
		while(tot<=s){
			++page;
			tot += page;
		}
		if(s==tot) lose = page;
		else lose = tot-s;
		printf("%lld %lld\n",lose, page);
	}
	return 0;
}
