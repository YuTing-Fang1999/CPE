//球體面積=4*pi*r^2
//圓面積=pi*r^2
//每多切一塊都會增加一個圓面積
//pi*r^2 / 4*pi*r^2 = 1/4 = 25%
#include <iostream>
using namespace std;
int main(){
	long long n;
	while(cin>>n && n>0){
		if(n==1) cout<<"0%"<<endl;
		else cout<<n*25<<"%"<<endl;
	}
	return 0;
}


