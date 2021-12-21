#include <iostream>
using namespace std;

int main(){
	long long int low, high;
	while(cin>>low>>high){
		if(!low && !high) break;
		cout<<high/5 - low/5 + 1<<endl;
	}
	return 0;
}
