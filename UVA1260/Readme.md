### 雖然很簡單但我寫得不是最佳的，還是紀錄一下好了
### 一開始照著題目敘述算的
```
#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int T; cin>>T;
	int A[1001];
	int B[1001];
	while(T--){
		int n; cin>>n;
		memset(B,0,sizeof(B));
		for(int i=0;i<n;++i){
			cin>>A[i];
			for(int j=0;j<i;++j){
				if(A[i] >= A[j]) B[i]+=1;
			}
		}
		int sum = 0;
		for(int i=1;i<n;++i) sum+=B[i];
		cout<<sum<<endl;
	}
	return 0;
}
```

### 但其實題目只問最後加總，所以直接算加總即可
time = 0.010
```
#include <iostream>
using namespace std;

int main(){
	int T; cin>>T;
	int A[1001];
	while(T--){
		int n; cin>>n;
		int sum = 0;
		for(int i=0;i<n;++i){
			cin>>A[i];
			for(int j=0;j<i;++j){
				if(A[i] >= A[j]) sum+=1;
				//也可以寫成這樣 sum += (A[i] >= A[j])
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
```

### 進階改良版
以題目B的定義來說，是要確認自己與前i-1個數字比，自己為第幾大  
所以可以邊找邊做排序，排到哪個位置就知道比自己小的有幾個  
```
#include <iostream>
using namespace std;
int main(){
	int T; cin>>T;
	int A[1001];
	while(T--){
		int n; cin>>n;
		int sum = 0,j;
		for(int i=0;i<n;++i){
			int num; cin>>num;
			//using insert sort
			for(j=i-1;j>=0;--j){
				if( num < A[j] ) A[j+1] = A[j];
				else break;
			}
			A[j+1] = num;
			sum += j+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
```
time = 0.010
改成這樣並沒有比較快耶  

### 影響速度的原因
分開定義變數會比較慢，使用C++會比純C慢  

### 總結
這題的重點並不是考演算法，有寫出來就好了，不要糾結太多==  
