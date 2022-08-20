#include <iostream>
#include <string.h>
using namespace std;
//Runtime error
int T=0,N,H1,H2,M1,M2;
int s,e;
int myTime[500];

int main(){
	while(cin>>N){
		memset(myTime,-1,sizeof(myTime));
		for(int i=0;i<N;++i){
			scanf("%d:%d %d:%d\n",&H1,&M1,&H2,&M2);
			cin.ignore(1024,'\n');
			s=60*(H1-10)+M1;
			e=60*(H2-10)+M2+1;
			
			while(s!=e){
				myTime[s++] = 1;
			}
		}
		myTime[480] = 1;
		
		int t = 0;
		int start = 0;
		int maxNap = 0;
		for(int i=0;i<=480;++i){
			if(myTime[i]<0 && myTime[i+1]>0) {
				if(i-start+1>maxNap){
					maxNap = i-start+1;
					t=start;
				}
			}
			if(myTime[i]>0 && myTime[i+1]<0) start = i;
		}
		printf("Day #%d: the longest nap starts at %02d:%02d and will last for ",++T,10+t/60,t%60,maxNap);
		if(maxNap/60) printf("%d hours and ",maxNap/60);
		printf("%d minutes.\n",maxNap%60);
	}
}
