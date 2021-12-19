#include <iostream>
#include <string>
using namespace std;

int main(){
	int J,R;
	while(cin>>J>>R && J){
		int point[501];
		memset(point,0,sizeof(point));
		while(R--){
			for(int i=1;i<=J;++i){
				int p; cin>>p;
				point[i]+=p;
			}
		}
		int v = J;
		for(int i=J;i>=1;--i)
			if(point[i]>point[v]) v=i;
		cout<<v<<endl;
	}
	return 0;
}
