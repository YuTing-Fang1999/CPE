#include <iostream>
#include <algorithm>
using namespace std;

long long n[5];
int T;
int main(){
	cin>>T;
	while(T--){
		for(int i=0;i<4;++i) cin>>n[i];
		sort(n,n+4);
		
		bool R = true, S = true;
		long long sum = 0;
		for(int i=0;i<3;++i) {
			sum+=n[i];
			if(n[i]!=n[i+1]){
				S = false;
				if(i!=1)R = false;
			}
		}
		if(S) printf("square\n");
		else if(R) printf("rectangle\n");
		else if(sum>n[3]) printf("quadrangle\n");
		else printf("banana\n");
	}
	return 0;
}
