有大石頭(B)跟小石頭(S)    
大石頭可走無限次，小石頭只能走一次  
青蛙有來回所以總共會走兩次   
盡量讓青蛙每一步都跳得越小越好   
最後求其中最大的leap為多少  

注意每個測資只表示一個石頭  
題目說 石頭將按 M 的升序排列 害我以為石頭會以M的升序重複出現 ==

### 解法
模擬兩隻青蛙渡河(一隻代表去，一隻代表回)  
每隻每次都各走一步(因為如果連續走的話，另一隻需要跳更大步才行)  
小石頭(S)走過後要設為N，因為只能走一次，之後不能再走  

###
```cpp
#include <iostream>
using namespace std;

struct Stone{
	char type;
	int M;
};

int T,N,D;
char temp;
Stone stone[105];
int main(){
	cin>>T;
	//起點
	stone[0].type='B';
	stone[0].M=0;
	for(int CASE=1;CASE<=T;++CASE){
		cin>>N>>D;
		for(int i=1;i<=N;++i) cin>>stone[i].type>>temp>>stone[i].M;
		//終點
		stone[N+1].type='B';
		stone[N+1].M=D;
		
		int pos1=0,pos2=0;
		int maxLeap=0;
		bool frog1=true,frog2=true;
		//輪流跳一步
		while(frog1 || frog2){
			if(frog1){
				int pre_pos1 = pos1;
				while(stone[++pos1].type == 'N'); 
				if(stone[pos1].type == 'S') stone[pos1].type = 'N';
				maxLeap = max(maxLeap, stone[pos1].M-stone[pre_pos1].M);
				if(stone[pos1].M == D) frog1=false;
			}
			
			if(frog2){
				int pre_pos2 = pos2;
				while(stone[++pos2].type == 'N');
				if(stone[pos2].type == 'S') stone[pos2].type = 'N';
				maxLeap = max(maxLeap, stone[pos2].M-stone[pre_pos2].M);
				if(stone[pos2].M == D) frog2=false;
			}
		}
		printf("Case %d: %d\n",CASE,maxLeap);
	}
	return 0;
}
```
