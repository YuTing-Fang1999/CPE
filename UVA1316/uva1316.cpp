#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N;

struct Product{
	int p,d;
};
vector< Product > prod;
bool canIn[10001];

bool cmp(Product a,Product b){
	if(a.p>b.p) return true;
	if(a.p == b.p) return a.d<b.d;
	return false;
}
int main(){
	while(cin>>N){
		memset(canIn,true,N+1);
		prod.clear();
		for(int i=0;i<N;++i){
			Product p;
			cin>>p.p>>p.d;
			prod.push_back(p);
		}
		sort(prod.begin(),prod.end(),cmp);
		int ans=0;
		for(int i=0;i<prod.size();++i){
			if(canIn[prod[i].d]){
				ans+=prod[i].p;
				canIn[prod[i].d]=false;
			}
			else{
				int now=prod[i].d;
				while(!canIn[now] && now>=1) --now;
				if(now>=1){
					ans+=prod[i].p;
					canIn[now]=false;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
