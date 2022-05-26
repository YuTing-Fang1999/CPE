#include <iostream>
#include <algorithm>
using namespace std;

int moring[105];
int evening[105];
int main(){
	int n,d,r;
	while(cin>>n>>d>>r && (n||d||r)){
		for(int i=0;i<n;++i) cin>>moring[i];
		for(int i=0;i<n;++i) cin>>evening[i];
		sort(moring,moring+n);
		sort(evening,evening+n,greater<int>());
		
		int price = 0;
		for(int i=0;i<n;++i){
			int t = moring[i]+evening[i]-d;
			if(t>0) price+=t*r;
		}
		printf("%d\n",price);
	}
	return 0;
}
