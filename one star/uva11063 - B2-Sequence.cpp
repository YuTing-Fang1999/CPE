#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int N,T=0;
int b[10005];
bool isB2;

// 題目說B2不能有負數不代表輸入不會有負數!! 
// 記得要空兩行!! 
int main(){
	while(cin>>N){
		isB2=true;
		map< int, bool > mark;
		
		for(int i=0;i<N;++i) cin>>b[i];
		
		for(int i=0;i<N;++i) {
			if(b[i]<=0 || (i>0 && b[i-1]>=b[i]) || !isB2){
				isB2=false;
				break;
			}
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
		
		if(isB2) printf("Case #%d: It is a B2-Sequence.\n\n",++T);
		else printf("Case #%d: It is not a B2-Sequence.\n\n",++T);
	}
	return 0;
}
