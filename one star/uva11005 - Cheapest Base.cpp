#include <iostream>
#include <queue> 
using namespace std;
//輸入的R為10進位，將R轉成2~36進位，窮舉看哪種進位的cost最低 
int cost[36];
int T,N,R,minCost;
queue< int > baseQueue;

int main(){
	cin>>T;
	for(int CASE=1;CASE<=T;++CASE){
		if(CASE>1) cout<<endl;
		printf("Case %d:\n",CASE);
		for(int i=0;i<36;++i) cin>>cost[i];
		
		cin>>N;
		while(N--){
			cin>>R;
			printf("Cheapest base(s) for number %d:",R);
			
			minCost=1e8;
			//窮舉所有進位 
			for(int base=2;base<=36;++base){
				//copy R 
				int R2 = R;
				//計算cost 
				int nowCost = 0;
				while(R2){
					nowCost+=cost[R2%base];
					R2/=base;
				}
//				printf("%d %d\n",base,nowCost);
				if(nowCost<minCost){
					minCost=nowCost;
					while(!baseQueue.empty()) baseQueue.pop();
					baseQueue.push(base);
				}
				else if(nowCost==minCost)
					baseQueue.push(base);
			}
			while(!baseQueue.empty()){
				printf(" %d",baseQueue.front());
				baseQueue.pop();
			}
			cout<<endl;
		}
	}
	return 0;
}
