#include <iostream>
using namespace std;
// (n-1) + n*(m-1)
// = n-1 + nm - n
// = nm -1
int main(){
	int n,m;
	while(cin>>n>>m){
		printf("%d\n",n*m-1);
	}
	return 0;
}
