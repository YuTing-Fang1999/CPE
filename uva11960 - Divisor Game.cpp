#include <iostream>
using namespace std;
#define MAXN 1000000

int T,N;
int table[1000005]={0};

int main(){
	//init table
	for(int i=1;i<=MAXN;++i){
		for(int j=i;j<=MAXN;j+=i){
			++table[j];
		}
	}
	int max_idx = 2;
	int max_num = table[2];
	for(int i=3;i<=MAXN;++i){
		if(table[i]>=max_num){
			max_num = table[i];
			max_idx = i;
		}
		table[i] = max_idx;
	}
	
	cin>>T;
	while(T--){
		cin>>N;
		cout<<table[N]<<endl;
	}
	return 0;
}
