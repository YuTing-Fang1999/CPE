照著規則做就好了
### 中間出的bug
對角線的判斷為i+j==4 (一開始寫成5了)  
與free space相關的idx為2(一開始寫成3了) 
### 每個case都會出75個數，但可能不會unique?
最後測試是唯一的，看來題目不會在這裡出陷阱，但我還是上傳有偵測版本的code好了

### code 
```cpp
#include <iostream>
#include <string.h>
using namespace std;

int T;
int num;
int row[5],col[5],diagonal[2];
int num2row[80],num2col[80];
bool isAppear[80];

int main(){
	cin>>T;
	while(T--){
	memset(num2row,-1,sizeof(num2row));
	memset(num2col,-1,sizeof(num2col));
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	memset(diagonal,0,sizeof(diagonal));
	memset(isAppear,false,sizeof(isAppear));
	++row[2];++col[2];++diagonal[0];++diagonal[1];
	
	for(int i=0;i<5;++i) 
	for(int j=0;j<5;++j)
	{
		if(i==2 && j==2) continue;
		cin>>num;
		num2row[num] = i;
		num2col[num] = j;
	}
	int cnt=1;
	for(;cnt<=75;++cnt){
		cin>>num;
		if(num2row[num]!=-1){ // && !isAppear[num] 如果要偵測的話
			isAppear[num]=true;
			
			int i = num2row[num];
			int j = num2col[num];
			
			row[i]++;
			if(row[i]==5) break;
			
			col[j]++;
			if(col[j]==5) break;
			
			if(i==j) diagonal[0]++;
			if(diagonal[0]==5) break;
			
			if(i+j==4) diagonal[1]++;
			if(diagonal[1]==5) break;
			
			//printf("%d %d\n",i,j);
			//printf("%d %d %d %d\n",row[i],col[j],diagonal[0],diagonal[1]);
		}
	}
	printf("BINGO after %d numbers announced\n",cnt);
	while(++cnt <=75) cin>>num;
	}
	return 0;
}
```
