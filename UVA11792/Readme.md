有些車站出現在不同路線上，我們稱呼它為「重點車站」，而其餘的稱呼為「次要車站」。我們相信 Krochanska 位在一個去其他地方都是最快的重點車站。
你可以假設從一條路線切換到另一條路線不會耗時，你必須找出 Cirilo Krochanska 在哪裡。

### 解法
使用BFS找到其他重點車站的最短路徑

### 注意
要記錄的是加入車站的次數(而不是車站連接的邊!)  
否則如果重點車站是位於尾巴時會miss掉(找bug找超久...)  

### code
```cpp
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 10005
using namespace std;

int T,N,S;
vector< int > conn[MAXN];
bool visit[MAXN];
int used[MAXN];
int dist[MAXN];
int preNum, nextNum;
int cnt;

//find minium path
int BFS(int parent){
	for(int i=1;i<=N;++i)  {
		visit[i] = false;
		dist[i] = 0;
	}
	queue< int > q;
	q.push(parent);
	int c = 0;
	
	while(!q.empty()){
		parent = q.front(); q.pop();
		for(int i=0;i<conn[parent].size();++i){
			int child = conn[parent][i];
			if(!visit[child]){
				dist[child] = dist[parent] + 1;
				q.push(child);
				visit[child] = true;
				if(used[child]>1) c++;
			}
			if(c == cnt) break;
		}
		if(c == cnt) break;
	}
	
	int d=0;
	for(int i=1;i<=N;++i){
		if(used[i]>1) d+=dist[i];
	}
	
	return d;
}
int main(){
	cin>>T;
	while(T--){
		cin>>N>>S;
		//init
		for(int i=1;i<=N;++i) {
			used[i]=0;
			conn[i].clear();
		}
		
		//init conn
		while(S--){
			cin>>preNum;
			used[preNum]++;
			while(cin>>nextNum && nextNum){
				conn[preNum].push_back(nextNum);
				conn[nextNum].push_back(preNum);
				preNum=nextNum;
				//注意只要計算 used[preNum] 就好,否則如果重要車站在尾巴會分辨不出來
				used[preNum]++;
			}
		}
		
		//compute the number of important station 
		cnt = 0;
		for(int i=1;i<=N;++i){
			if(used[i]>1) cnt++;
		}
		
		//find ths minium distance of important station 
		int minPath=1e9;
		int path;
		int ans;
		
		for(int i=1;i<=N;++i){
			if(used[i]>1){
				path = BFS(i);
//				printf("s=%d, path=%d\n",i,path);
				if(path<minPath) {
					minPath = path;	
					ans=i;
				}
			}
		}
//		printf("c=%d\n",cnt);
		printf("Krochanska is in: %d\n",ans);
		
	}
	
	return 0;
} 
```
