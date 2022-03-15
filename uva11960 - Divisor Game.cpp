#include <iostream>
using namespace std;

int T,N;
int table[1000005]={0};

int main(){
	//init table
	for(int i=1;i<=1000000;++i){
		for(int j=i;j<=1000000;j+=i){
			table[j]+=1;
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		int ans=N;
		for(int i=N-1;i>0;--i){
			if(table[i]>table[ans]){
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
