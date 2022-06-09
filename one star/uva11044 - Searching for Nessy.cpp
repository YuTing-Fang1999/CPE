#include <iostream>
using namespace std;
// Don't care about the edge
int main(){
	int T, n, m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		cout<<(n/3) * (m/3)<<endl;
	}
	return 0;
}
