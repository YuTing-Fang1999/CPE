#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	//�`�N�Ʀr����2^32 
	long long int n1,n2;
	while(cin>>n1>>n2){
		//�`�N�Olld 
		printf("%lld\n",llabs(n1-n2));
	}
	return 0;
}
