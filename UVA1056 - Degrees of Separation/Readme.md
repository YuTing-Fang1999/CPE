### 題目
題目要求是輸出兩點之間最短路徑中的最大距離    
如果有兩點是沒連接在一起的，就輸出DISCONNECTED  

### 解法
用map將名字轉為點的id  
將關係圖用矩陣存起來  
最後算出任兩點的最短路徑  

### 一直WA
#### 路徑沒找完整
注意找路徑的順序為k、i、j(k的順序要在最外圈!)
```cpp
for(int k=1;k<=N;++k){
  for(int j=1;j<=N;++j)
    for(int i=1;i<=N;++i){
      if(path[i][k] && path[k][j]){
        if(path[i][j]==0 || path[i][j]>path[i][k]+path[k][j]) 
          path[i][j]=path[i][k]+path[k][j];
      }
    }
}
```

#### maxDegree的數量不對
以下的關係圖  
```
0 1 1 1 
1 0 1 1 
1 1 0 1 
1 1 1 0 
```
找出的路徑為  
```
2 1 1 1 
1 2 1 1 
1 1 2 1 
1 1 1 2 
```
自己到自己一定會先經過其他點，所以為2  
但題目的要求並不包含自己到自己，所以在找最大degree時，不能找到i==j  
```cpp
for(int i=1;i<=N;++i)
    for(int j=1;j<i;++j)
        path[i][j]...
```
因為是對稱式矩陣，所以只要找下三角即可   

### code
```cpp
#include <iostream>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int N,R,T=0;
map< string, int > name2id;
string s1,s2;
int path[55][55];
int main(){
	while(cin>>N>>R && N && R){
		name2id.clear();
		memset(path,0,sizeof(path));
		int id=1;
		for(int i=0;i<R;++i){
			cin>>s1>>s2;
			if(name2id[s1]==0) name2id[s1]=id++;
			if(name2id[s2]==0) name2id[s2]=id++;
			//printf("%d %d\n",name2id[s1],name2id[s2]);
			path[name2id[s1]][name2id[s2]]=1;
			path[name2id[s2]][name2id[s1]]=1;
		}
		for(int k=1;k<=N;++k){
			for(int j=1;j<=N;++j)
				for(int i=1;i<=N;++i){
					if(path[i][k] && path[k][j]){
						if(path[i][j]==0 || path[i][j]>path[i][k]+path[k][j]) 
							path[i][j]=path[i][k]+path[k][j];
					}
				}
		}
		
		int maxDegree=0;
		bool disconnect=false;
		for(int i=1;i<=N;++i){
			for(int j=1;j<i;++j){
				if(path[i][j]>maxDegree) maxDegree=path[i][j];
				else if(path[i][j]==0) {
					disconnect=true;
					break;
				}
			}
		}
		if(disconnect) printf("Network %d: DISCONNECTED\n\n",++T);
		else printf("Network %d: %d\n\n",++T,maxDegree);
	}
	return 0;
}
```
