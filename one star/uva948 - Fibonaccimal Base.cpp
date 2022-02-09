#include <iostream>
using namespace std;

int fib[41];
int N,R;
int main(){
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<41;++i){
		fib[i] = fib[i-1]+fib[i-2]; 
	} 
//	cout<<fib[40];
	cin>>N;
	while(N--){
		cin>>R;
		printf("%d = ",R);
		bool isPrint=false;
		for(int i=39;i>=2;--i){
			if(R-fib[i]>=0){
				cout<<1;
				isPrint=true;
				R-=fib[i];
			}
			else if(isPrint){
				cout<<0;
			}
		}
		printf(" (fib)\n");
	}
	return 0;
} 
