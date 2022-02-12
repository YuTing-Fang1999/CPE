#include <iostream>
using namespace std;

int T,N,arr[20];

void Ducci(){
	int a0=arr[0];
	for(int j=0;j<N-1;++j)
		arr[j] = abs(arr[j]-arr[j+1]);
	arr[N-1]=abs(arr[N-1]-a0);
}

bool isZero(){
	for(int j=0;j<N;++j)
		if(arr[j]!=0) 
			return false;
		
	return true;
}
int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;++i) cin>>arr[i];
		
		bool zero=false;
		for(int i=0;i<1001;++i){
			Ducci();
			if(isZero()){
				zero=true;
				break;
			}
		}
		if(zero) cout<<"ZERO"<<endl;
		else cout<<"LOOP"<<endl;
	}
	return 0;
}
