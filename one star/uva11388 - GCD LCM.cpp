#include <iostream>
using namespace std;
//最大公因數 (GCD) 
//最小公倍數 (LCM)
//L%G==0
int main(){
	int G, L, N;
	cin>>N;
	while(N--){
		cin>>G>>L;
		if(L<G) swap(G,L);
		if(L%G) printf("-1\n");
		else printf("%d %d\n",G,L);
	}
	return 0;
}
