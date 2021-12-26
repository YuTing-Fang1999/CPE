#include <iostream>
using namespace std;
//以題目B的定義來說，是要確認自己與前i-1個數字比，自己為第幾大
//所以可以邊找邊做排序，排到哪個位置就知道比自己小的有幾個
int main(){
	int T; cin>>T;
	int A[1001];
	while(T--){
		int n; cin>>n;
		int sum = 0,j;
		for(int i=0;i<n;++i){
			int num; cin>>num;
			//using insert sort
			for(j=i-1;j>=0;--j){
				if( num < A[j] ) A[j+1] = A[j];
				else break;
			}
			A[j+1] = num;
			sum += j+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
