#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//相鄰的差在1~N-1中都有出現就表示Jolly
int N;
bool isFind[3005];
bool jolly;
int n[3005];
int main(){
	while(cin>>N){
		jolly=true;
		memset(isFind,false,sizeof(isFind));
		for(int i=0;i<N;++i) cin>>n[i];
		for(int i=1;i<N;++i) {
			int dif=abs(n[i]-n[i-1]);
			if(isFind[dif] || dif==0 || dif>N-1) {
				jolly=false;
				break;
			}
			else isFind[dif]=true;
		}
		
		if(jolly) cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;
	}
	return 0;
} 
