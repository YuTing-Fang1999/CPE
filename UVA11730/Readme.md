#### 注意每做一次轉換都要重算一次A的質因數
詳細步驟請看 http://kos74185foracm.blogspot.com/2013/07/11730-number-transformation.html  

#### 如果有node出現同樣的數字就走最早出現的node就好(因為會有同樣的分支)

#### 注意Prime至少要算到2000以上(我一開始只算1000一直超出記憶體==)

#### BFS()前面要加return!
```cpp
return BFS();
```
#### 注意S為1的case
`Please note that 1 and A are not being considered as a factor of A`=>直接輸出-1
#### 注意BFS結束的判斷
* node<T才可加入queue
* 如果queue為空就`return -1;`，否則`return BFS();`

### code
```cpp
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int n,L;
	Node(int n,int L){
		this->n=n;
		this->L=L;
	}
};

int S,T,ans,CASE=0;
bool isPrime[3000];
vector< int > Prime;

bool isAppear[3000];
queue< Node > q;

int BFS(){
	Node node = q.front(); q.pop();
	if(node.n==T) return node.L;
	for(int i=0;Prime[i]<node.n;++i){
		if(node.n%Prime[i]==0){
			if(node.n+Prime[i]<=T && !isAppear[node.n+Prime[i]]){
				isAppear[node.n+Prime[i]]=true;
//				cout<<node.n+Prime[i]<<" "<<node.L+1<<endl;
				q.push(Node(node.n+Prime[i],node.L+1));
			}
		}
	}
	if(!q.empty()) return BFS();
	return -1;
}
int main(){
	// 質數篩 
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2;i<=2000;++i){
		if(isPrime[i]){
			Prime.push_back(i);
			for(int j=i*i;j<=2000;j+=i)
				isPrime[j]=false;
		}
	}
	
	while(cin>>S>>T && S && T){
		memset(isAppear,false,sizeof(isAppear));
		q.push(Node(S,0));
		if(S==1) ans=-1;
		else ans = BFS();
		printf("Case %d: %d\n",++CASE,ans);
		while(!q.empty()) q.pop();
	}
	
	return 0;
} 
```
