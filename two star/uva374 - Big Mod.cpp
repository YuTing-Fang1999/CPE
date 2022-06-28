#include <iostream>
#define LL long long int 
using namespace std;
//B^P mod M
//= B^(P/2) mod M * B^(P/2) mod M * B%M (if P is odd)

LL bigMod(LL B, LL P, LL M){
	if(P==1) return B%M;
	if(P==0) return 1;
	LL temp = bigMod(B, P/2, M) % M; //要 % M 讓 temp 降到最小以避免溢位 
	if(P%2) return (temp * temp * B) % M;
	else return (temp * temp) % M;
}
int main(){
	LL B,P,M;
	while(cin>>B>>P>>M){
		cout<<bigMod(B,P,M)<<endl;
	}
	return 0;
}
