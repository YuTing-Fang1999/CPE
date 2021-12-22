#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Call{
	int from;
	int to;
	int tar;
	Call(int a,int b,int c){
		from=a; to=b; tar=c;
	}
		
};
vector<Call> callVec[10000];
bool called[10000];

int call_num(int src, int time){
	called[src] = true;
	for(int i=0;i<callVec[src].size();++i){
		if( callVec[src][i].from <= time && time <= callVec[src][i].to){
			if(called[callVec[src][i].tar]){
				return 9999;
			}else{
				//­n¥[return!!! 
				return call_num(callVec[src][i].tar,time);
			}
		}
	}
	return src;
}
int main(){
	int n; cin>>n;
	int sysNum = 1;
	cout<<"CALL FORWARDING OUTPUT"<<endl;
	while(sysNum<=n){
		cout<<"SYSTEM "<<sysNum<<endl;
		for(int i=0;i<10000;++i)
			callVec[i].clear();
			
		int src, time, dur, tar;
		while(cin>>src && src != 0){
			cin>>time>>dur>>tar;
			//input Call
			Call c(time,time+dur,tar);
			callVec[src].push_back(c);
			//printf("%d %d %d %d\n",src, c.from,c.to,c.tar); 
		}
		
		while(cin>>time && time != 9000 && cin>>src){
			memset(called, 0 , sizeof(called));
			printf("AT %04d CALL TO %04d RINGS %04d\n", time, src, call_num(src,time));
		}
		++sysNum;
	}
	printf("END OF OUTPUT\n");
	return 0;
}
