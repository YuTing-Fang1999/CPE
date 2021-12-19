#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	//注意數字有到2^32 
	long long int n1,n2;
	while(cin>>n1>>n2){
		//注意是lld 
		printf("%lld\n",llabs(n1-n2));
	}
	return 0;
}
