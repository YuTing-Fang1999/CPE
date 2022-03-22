#include <iostream>
using namespace std;

int main(){
	long long s;
	while(cin>>s && s){
		long long page = 0;
		long long tot = 0;
		while(tot<=s){
			++page;
			tot += page;
		}
		printf("%lld %lld\n",tot-s, page);
	}
	return 0;
}
