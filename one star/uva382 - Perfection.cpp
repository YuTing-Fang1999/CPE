#include <iostream>
#define MAXN 60001
using namespace std;

int n;
int table[MAXN] = {0};
int main(){
	for(int i=1;i<MAXN;++i)
		for(int j=i*2;j<MAXN;j+=i)
			table[j]+=i;
			
	printf("PERFECTION OUTPUT\n");
	while(cin>>n && n){
		printf("%5d  ",n);
		if(n == table[n]) printf("PERFECT\n");
		else if(n<table[n]) printf("ABUNDANT\n");
		else if(n>table[n]) printf("DEFICIENT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
