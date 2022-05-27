#include <iostream>
using namespace std;

int main(){
	int table[50001][3] = {0}; 
	for(int i=0;i<255;++i) //sqrt(50000) = 223...
	for(int j=i;j<255;++j)
	for(int k=j;k<255;++k){
		int num = i*i + j*j + k*k;
		if(num<=50000 && table[num][0]==0 && table[num][1]==0 && table[num][2]==0){
			table[num][0] = i;	
			table[num][1] = j;
			table[num][2] = k;
		}
	}
	int N, K;
	cin>>N;
	while(N--){
		cin>>K;
		if(table[K][0]==0 && table[K][1]==0 && table[K][2]==0)
			printf("-1\n");
		else printf("%d %d %d\n",table[K][0],table[K][1],table[K][2]);
	}
} 
