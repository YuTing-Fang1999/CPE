#include <iostream>
using namespace std;
//µ¥®t¯Å¼Æ
int T;
int a,b;
int main(){
	cin>>T;
	for(int c=1;c<=T;++c){
		cin>>a>>b;
		a+=!(a%2);
		b-=!(b%2);
//		cout<<a<<" "<<b<<endl;
		double ans=(double)(a+b)/2*((b-a)/2 + 1);
		printf("Case %d: ",c); 
		cout<<ans<<endl;
	}
	return 0;
}
