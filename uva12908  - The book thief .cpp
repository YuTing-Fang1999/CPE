#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long s;
	while(cin>>s && s){
		int page = int(sqrt(s));
		int tot = (1+page)*page/2;
		while (tot <= s) tot += ++page;
		printf("%lld %lld\n",tot-s, page);
	}
	return 0;
}
