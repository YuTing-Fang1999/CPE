#include <iostream>
#include <cmath>
using namespace std;

float N;
int T=0;
int main(){
	while(cin>>N && N>0){
		float ans = log(N)/log(2.0);
		if((int)ans <ans) ans++;
		printf("Case %d: %d\n",++T,(int)ans);
	}
	return 0;
}
