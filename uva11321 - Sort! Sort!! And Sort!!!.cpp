#include <iostream>
#include <algorithm>
using namespace std;
//奇大>奇小>偶小>偶大

int arr[100005];
int N,M;

bool cmp(int a, int b){
	if(a%M < b%M) return true;
	if(a%M > b%M) return false;
	if(a%2){
		if(b%2) return a>b;
		else return true;
	}
	else{
		if(b%2==0) return a<b;
		else return false;
	}
}
int main(){
	while(cin>>N>>M && N && M){
		for(int i=0;i<N;++i) cin>>arr[i];
		sort(arr,arr+N,cmp);
		
		printf("%d %d\n",N,M);
		for(int i=0;i<N;++i){
			cout<<arr[i]<<endl;
		}
	}
	printf("%d %d\n",N,M);
	return 0;
} 
