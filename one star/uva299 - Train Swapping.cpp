#include <iostream>
using namespace std;

//計算泡沫排序的交換次數 
int T,N,train[55];
int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;++i) cin>>train[i];
		
		int cnt=0;
		for(int i=0;i<N;++i){
			for(int j=0;j<N-i-1;++j){
				if(train[j]>train[j+1]){
					swap(train[j],train[j+1]);
					++cnt;
				} 
			}
		}
		
		printf("Optimal train swapping takes %d swaps.\n",cnt);
	}
	return 0;
}
