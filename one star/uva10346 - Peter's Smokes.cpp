#include <iostream>
using namespace std;

int n,k;
int main(){
	while(cin>>n>>k){
		int ans = n;
		while(n>=k){
			ans += n/k;
			n = n/k + n%k;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
