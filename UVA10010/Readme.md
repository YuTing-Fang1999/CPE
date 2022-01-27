### 題目說明
找字，可以上下左右對角線去找，最後輸出字的第一個位置   
每個字都至少可以被找到一次(選最左上的輸出)  

### 方法
從左上找到右下  
使用DFS去找(其實也不太算啦，因為都是要固定的方向，只要沒找到就直接結束，就是一般的遞迴吧)    

### 注意要統一轉成大血或小寫!
題目不分大小寫
### 注意i,j不要超過陣列範圍!
所以我的輸入從1開始
### 注意字串只有一個字元的case!
要分兩個case去處理

### code
```cpp
#include <iostream>
#include <string>
using namespace std;

char grid[60][60];
int m,n,T,k;
bool isFind;
int xChange[8]={1,-1,0,0,1,-1,-1,1};
int yChange[8]={0,0,1,-1,1,-1,1,-1};
int x,y;
string s;

bool DFS(int i,int j,int dir,int idx,string str){
//	printf("i=%d,j=%d,str[%d]=%c,grid=%c\n",i,j,idx,str[idx],grid[i][j]);
	if(i>m || j>n || i<1 || j<1) return false;
	if(str[idx]!=grid[i][j]) return false;
	if(idx==str.size()-1) return true;
	return DFS(i+yChange[dir],j+xChange[dir],dir,idx+1,str);
}
int main(){
	cin>>T;
	while(T--){
		//input grid
		cin>>m>>n;
		for(int i=1;i<=m;++i){
			cin>>s;
			for(int j=1;j<=n;++j){
				grid[i][j]=toupper(s[j-1]);
//				cout<<grid[i][j];
			}
//			cout<<endl;
		}
		
		cin>>k;
		while(k--){
			cin>>s;
			for(int i=0;i<s.size();++i) s[i]=toupper(s[i]);
			isFind=false;
			for(int i=1;i<=m && !isFind;++i)
			for(int j=1;j<=n && !isFind;++j)
				if(s[0]==grid[i][j]){
					if(s.size()==1){
						cout<<i<<" "<<j<<endl;
						isFind=true;
					}else{
						for(int dir=0;dir<8 && !isFind;++dir)
						if(s[1]==grid[i+yChange[dir]][j+xChange[dir]])
						if(DFS(i,j,dir,0,s)) {
							cout<<i<<" "<<j<<endl;
							isFind=true;
						}
					}
				}
		}
		if(T) cout<<endl;
	}
	return 0;
} 
```
