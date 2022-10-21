### Problem Description
```
....
.B..
..W.
....
```
* W can only go to the upper left or upper right (can jump one step or jump two steps)
* W cannot walk on B

Following is the position  W can move.   
```
1.2.
.B.2
..W.
....
```
The path is 2.  
### Input
```
2 -> T
4 -> N 
....
....  -> NxN
....
..W.
8
.B.B.B..
........
........
..B.....
........
..B.....
.W......
........
```
### Output
```
Case 1: 5
Case 2: 1
```
### Code
```cpp
#include <iostream>
using namespace std;

int main(){
	int T,N;
	cin>>T;
	char region[105][105];
	for(int CASE=1;CASE<=T;++CASE){
		cin>>N;
		int r,c;
		for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
			cin>>region[i][j];
			if(region[i][j]=='W'){
				r=i, c=j;
			}
		}
		int cnt[105][105]={0};
		cnt[r][c]=1;
		for(int i=r-1;i>=0;--i)
		for(int j=0;j<N;++j){
			if(region[i][j]=='B') continue;
			if(j-1>=0){
				if(region[i+1][j-1]=='B' && j-2>=0){
					cnt[i][j]+=cnt[i+2][j-2];
				}
				else{
					cnt[i][j]+=cnt[i+1][j-1];
				}
			}
			if(j+1<N){
				if(region[i+1][j+1]=='B' && j+2<N){
					cnt[i][j]+=cnt[i+2][j+2];
				}
				else{
					cnt[i][j]+=cnt[i+1][j+1];
				}
			}
			cnt[i][j]%=1000007;
		}
		int ans=0;
		for(int j=0;j<N;++j){
			ans+=cnt[0][j];
			ans%=1000007;
		}
		printf("Case %d: %d\n", CASE, ans);

	}
	return 0;
}
```
