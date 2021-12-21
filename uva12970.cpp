#include <iostream>
using namespace std;

//記得全部都要long long int!!! 
long long int gcd(long long int a,long long int b){
	while( (a%=b) && (b%=a) );
	return (a+b);
}
int main(){
	long long int v1,d1,v2,d2,n=0;
	while(cin>>v1>>d1>>v2>>d2){
		if(!v1 && !d1 && !v2 && !d2) break;
		++n;
		long long int x1 = d1*v2;
		long long int x2 = d2*v1;
		long long int y = v1*v2*2;
		cout<<"Case #"<<n<<": ";
		if(x1 < x2 ) cout<<"You owe me a beer!"<<endl;
		else cout<<"No beer for the captain."<<endl;
		
		cout<<"Avg. arrival time: ";
		if((x1+x2)%y) {
			long long int g = gcd((x1+x2),y);
			printf("%lld/%lld\n",((x1+x2)/g),(y/g));
		}
		else cout<<(x1+x2)/y<<endl;
	}
	return 0;
}
