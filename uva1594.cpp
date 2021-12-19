#include <iostream>
#include <stdlib.h>
#include <set>
#include <string>
using namespace std;
void Ducci(int arr[],int n2){
	int a0=arr[0];
	for(int i=0;i<n2-1;++i){
		arr[i]=abs(arr[i]-arr[i+1]);
	}
	arr[n2-1]=abs(arr[n2-1]-a0);
}

string to_string(int arr[],int n2){
	string str;
	for(int i=0;i<n2;++i){
		str.push_back(arr[i] + '0');
		str.push_back(',');
	}
	return str;
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
		int arr[1005];
		for(int i=0;i<n2;++i){
			cin>>arr[i];
		}
		
		set<string> mySet;
		while(1){
			Ducci(arr,n2);
			if(isZero(arr,n2)) {
				cout<<"ZERO"<<endl;
				break;
			}
			
			string str = to_string(arr,n2);
			//cout<<str<<endl;
			if(mySet.find(str)!=mySet.end()){
				cout<<"LOOP"<<endl;
				break;
			}
			mySet.insert(str);
		}
	}
	return 0;
}
