#include <iostream>
#include <stdlib.h>
using namespace std;

int n, a;
int main(){
	while(cin>>n && n){
		long long int bottle = 0, cost = 0;
		while(n--){
			cin>>a;
			bottle += a;
			cost += abs(bottle);
		}
		cout<<cost<<endl;	
	}
	
	return 0;
}
