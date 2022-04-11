#include <iostream>
using namespace std;

int table[1005]={0};
int T,N;
int main(){
	for(int i=1;i<=1000;++i){
		for(int j=i*2;j<=1000;j+=i){
			table[j]+=i;
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		if(table[N]<N)printf("deficient\n");
		if(table[N]==N)printf("perfect\n");
		if(table[N]>N)printf("abundant\n");
	}
	return 0;
}
