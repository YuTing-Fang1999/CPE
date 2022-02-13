解法: https://www.willychen.org/421/uva-1207-agtc/  
有點像是找最長子序列(LCD)那樣  
<img src="https://www.willychen.org/421/uva-1207-agtc/uva-1207-agtc-1.png"/>  
<img src="https://www.willychen.org/421/uva-1207-agtc/uva-1207-agtc-3.png"/>  

### code 
```cpp
#include <iostream>
#include <string>
using namespace std;

string x,y;
int n1,n2;
int grid[1000][1000];
int main(){
	for(int i=0;i<1000;++i){
		grid[0][i]=i;
		grid[i][0]=i;
	}
	while(cin>>n1>>x>>n2>>y){
		for(int i=1;i<=n1;++i){
			for(int j=1;j<=n2;++j){
				//printf("%c %c\n",x[i-1],y[j-1]);
				int n = min(grid[i-1][j], grid[i][j-1]);
				if(x[i-1]==y[j-1]) {
					if(n+1<=grid[i-1][j-1]) grid[i][j]=n+1;
					else grid[i][j]=grid[i-1][j-1];
				}
				else grid[i][j]=min(n,grid[i-1][j-1])+1;
			}
		}
		cout<<grid[n1][n2]<<endl;
	}
	return 0;
}
```
