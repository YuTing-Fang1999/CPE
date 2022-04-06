#include <iostream>
using namespace std;
//2*pos-1
long long N;
long long pos;
int main(){
	while(cin>>N){
		pos = (1+N)*(N+1)/2/2;
		cout<<2*(3*pos-3)-3<<endl;
	}
	return 0;
}
