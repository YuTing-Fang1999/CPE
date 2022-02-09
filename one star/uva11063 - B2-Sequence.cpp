#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int N,T=0;
int b[10005];
map< int, bool > mark; //也可以使用set來判斷 
bool isB2;

int main(){
	while(cin>>N){
		isB2=true;
		mark.clear();
		
		for(int i=0;i<N;++i) cin>>b[i];
		for(int i=0;i<N;++i) {
			for(int j=i;j<N;++j){
				int sum = b[i]+b[j];
				if(mark[sum]){
					isB2=false;
					break;
				}
				else{
					mark[sum]=true;
				}
			}
			
		}
		
		if(isB2) printf("Case #%d: It is a B2-Sequence.\n",++T);
		else printf("Case #%d: It is not a B2-Sequence.\n",++T);
	}
	return 0;
}
