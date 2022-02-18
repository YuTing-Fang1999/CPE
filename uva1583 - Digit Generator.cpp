#include <iostream>
using namespace std;
//«Øªí
int table[150000]={0};
int main(){
	for(int i=1;i<=100000;++i){
		int n=i;
		int M=i;
		while(n){
			M+=n%10;
			n/=10;
		}
		if(!table[M]) table[M]=i;
	}
	int T,M;
	cin>>T;
	while(T--){
		cin>>M;
		cout<<table[M]<<endl;
	}
	return 0;
}
