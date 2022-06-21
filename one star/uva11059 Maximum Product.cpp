#include <iostream>
using namespace std;
//注意是要求consecutive terms of S!! 
long long int temp, maxP;
int N;
int S[20];
int T=0;
int main(){
	while(cin>>N){
		maxP = 0;
		for(int i=0;i<N;++i) cin>>S[i];
		for(int i=0;i<N;++i){
			temp = 1;
			for(int j=i;j<N;++j){
				temp *= S[j];
				if(temp > maxP) maxP = temp;
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n",++T, maxP);
	}
	return 0;
}
