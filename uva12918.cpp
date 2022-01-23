#include <iostream>
using namespace std;

int T,k,h;
int main(){
	cin>>T;
	while(T--){
		cin>>k>>h;
		cout<<1LL*(h-1 + h-k)*k/2<<endl;
	}
	return 0;
}
