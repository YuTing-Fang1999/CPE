#include <iostream>
#include <stdlib.h>

using namespace std;
void Ducci(int arr[],int n2){
	int a0=arr[0];
	for(int i=0;i<n2-1;++i){
		arr[i]=abs(arr[i]-arr[i+1]);
	}
	arr[n2-1]=abs(arr[n2-1]-a0);
}

bool isZero(int arr[],int n2){
	for(int i=0;i<n2-1;++i)
		if(arr[i]) return false;
	
	return true;
}

int main(){
	int n; cin>>n;

	while(n--){
		int n2; cin>>n2;
		int arr[20];
		for(int i=0;i<n2;++i)
			cin>>arr[i];
		
		bool isLoop = true;
		//自作聰明，將陣列變成字串存入set反而比較慢
		//直接爆開比較快==
		for(int i=0;i<1001;++i){
			Ducci(arr,n2);
			if(isZero(arr,n2)) {
				isLoop = false;
				cout<<"ZERO"<<endl;
				break;
			}
		}
		if(isLoop){
			cout<<"LOOP"<<endl;
		}
	}
	return 0;
}
