這題的symmetric定義跟平常不太一樣，是要對中心點做對稱
```
5 1 3  5->1->3
2 0 2  2->0->2  2<-0<-2
3 1 5  3<-1-<5
```
```
1 2 6 5
3 4 4 3
3 4 4 3
5 6 2 1
```
### 解法 
i由左往右、n-i-1由右往左，直到N/2
注意i的範圍要到i<=N/2
```
for(int i=0;i<=N/2;++i)
  for(int j=0;j<N;++j)
    if(arr[i][j] != arr[N-i-1][N-j-1]){
      sym=false;
      break;
    }
```
### 注意
矩陣裡有負數就不是symmetric
```
-5 1 3 
2 0 2  
3 1 -5  
```

### code
```cpp
#include <iostream>
using namespace std;

int T,N;
char c;
long long arr[105][105];
bool sym;

int main(){
	cin>>T;
	for(int i=1;i<=T;++i){
		sym=true;
		cin>>c>>c>>N;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j){
				cin>>arr[i][j];
				if(arr[i][j]<0) sym=false;
			}
			
		if(sym)				
			for(int i=0;i<=N/2;++i)
				for(int j=0;j<N;++j)
					if(arr[i][j] != arr[N-i-1][N-j-1]){
						sym=false;
						break;
					}
			
		printf("Test #%d: ",i);
		if(sym) cout<<"Symmetric."<<endl;
		else cout<<"Non-symmetric."<<endl;
	}
	return 0;
}
```
