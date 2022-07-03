奇怪這題明明不難我卻debug好久==

### 題目說明
找N裡面的質數  
之後從中間 print 2C 個質數  

例如:
```
N = 11, C = 2 
Prime = 1,2,3,5,7,11
print 2,3,5,7
```
### 找質數的方法
如果除以前面的數都除不盡，就表示是質數  
注意要從2開始除，所以 LEN[1],LEN[2]要自己手動初始化  

### 怎麼找範圍
#### even
```
0,1,2,3,4,5
len = 6, C =2;
輸出 1,2,3,4
1 = 6/2 - 2
4 = 6/2 + 1
```
#### odd
```
0,1,2,3,4
len = 5, C =2;
輸出 1,2,3
1 = 5/2 - 1
3 = 5/2 + 1
```

### 算範圍的方法
```
--C;
int a = len[N]/2-C-(len[N]%2==0); if(a<0) a=0;
int b = len[N]/2+C; if(b>=len[N]) b=len[N]-1;
```

### 注意
C 可能比 N 大  
注意`18 18` `2 3`等case

## code
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> PRIME;
vector<int> LEN;
int main(){
	int N,C;
	//init
	PRIME.push_back(1);
	PRIME.push_back(2);
	LEN.push_back(0);
	LEN.push_back(1);
	LEN.push_back(2);
	while(cin>>N>>C){
		printf("%d %d:",N,C);
		//find prime
		for(int i=LEN.size();i<=N;++i){
			bool isPrime = true;
			for(int j=1;j<PRIME.size();++j){
				if(i%PRIME[j] == 0) {
					isPrime = false;
					break;
				}
			}
			if(isPrime) PRIME.push_back(i);
			LEN.push_back(PRIME.size());
		}
		//find boundary
		--C;
		int a = len[N]/2-C-(len[N]%2==0); if(a<0) a=0;
		int b = len[N]/2+C; if(b>=len[N]) b=len[N]-1;
		//output
		for(int i=a; i<=b; ++i){
			cout<<" "<<PRIME[i];
		}
		cout<<endl<<endl;
	}
	return 0;
}
```
