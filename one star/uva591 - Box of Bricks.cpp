#include <iostream>
using namespace std;

int n;
int hi[105];
int T=0;
int main(){
	while(cin>>n && n){
		
		int totH = 0;
		for(int i=0;i<n;++i) {
			cin>>hi[i];
			totH += hi[i]; 
		}
		int H = totH / n;
		
		int move = 0;
		for(int i=0;i<n;++i) {
			if(hi[i]>H) move+=(hi[i]-H);
		}
		
		printf("Set #%d\n", ++T);
		printf("The minimum number of moves is %d.\n\n",move);
	}
	
} 
