題目說任何數字都可由費氏數列組成，所以我們從最大的費氏數列一路減回去即可(減完後的數依舊可由後面的費氏數列組成)     
題目說數字最大到100,000,000   
由 https://wywu.pixnet.net/blog/post/26512033 可知  
最多到第39項(第40項=102334155 超過 100000000)  

### code
```cpp
#include <iostream>
using namespace std;

int fib[41];
int N,R;
int main(){
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<41;++i){
		fib[i] = fib[i-1]+fib[i-2]; 
	} 
//	cout<<fib[40];
	cin>>N;
	while(N--){
		cin>>R;
		printf("%d = ",R);
		bool isPrint=false;
		for(int i=39;i>=2;--i){
			if(R-fib[i]>=0){
				cout<<1;
				isPrint=true;
				R-=fib[i];
			}
			else if(isPrint){
				cout<<0;
			}
		}
		printf(" (fib)\n");
	}
	return 0;
} 
```
