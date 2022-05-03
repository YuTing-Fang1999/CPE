#include <iostream>
using namespace std;

int n,L;
int main(){
	while(cin>>n && n){
		int x,y,z,L;
		int x1=0,y1=0,z1=0;
		int x2=1e9,y2=1e9,z2=1e9;
		
		for(int i=0;i<n;++i){
			cin>>x>>y>>z>>L;
			x1 = max(x,x1);
			y1 = max(y,y1);
			z1 = max(z,z1);
			
			x2 = min(x+L,x2);
			y2 = min(y+L,y2);
			z2 = min(z+L,z2);
		}
		printf("%d\n", max(0,x2-x1)*max(0,y2-y1)*max(0,z2-z1));
	}
}
