#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	//記得要long long! 2^32 
	long long int n1,n2;
	while(cin>>n1>>n2){
		//ª`·N¬Olld 
		printf("%lld\n",llabs(n1-n2));
	}
	return 0;
}
