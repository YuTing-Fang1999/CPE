題目給一個數字R，此R為N進制，且R可被N-1整除  
求最小可能的N為多少(2 ≤ N ≤ 62)  

### 解法
取自https://yuihuang.com/uva-10093/  
```
假設R為abc 
=> N進位轉成10進位 
= a * N^2 + b * N + c
= a*N*(N-1+1) + b*(N-1+1) + c
= a*N*(N-1) + a*N + b*(N-1) + b + c
= a*N*(N-1) + a*(N-1) + a + b*(N-1) + b + c
= (a * N + a + b) * (N-1) + (a + b + c)
```
因題目已經明說R可被N-1整除，所以(a + b + c)一定也是N-1的倍數   
總之可以總結為一個定理  
#### 若一個n進位的數可以被n - 1整除，則它每個位數的總和也會被n - 1整除  

這只是一個數學證明而出的定理而已，不用想太多    
但如果是(N-2)的話，就會變成4a+2b+c為(N-2)的倍數了(也是由上述一樣的過程推導)   

### code
```cpp
#include <iostream>
#include <string>
using namespace std;
//若一個n進位的數可以被n - 1整除，則它每個位數的總和也會被n - 1整除(由數學歸納出來的特性)
string R;
int main(){
	while(cin>>R){
		int temp, N = 1, num=0;
		
		for(int i=0;i<R.size();++i){
			if('0'<=R[i] && R[i]<='9') temp=R[i]-'0';
			else if('A'<=R[i] && R[i]<='Z') temp=(R[i]-'A'+10);
			else if('a'<=R[i] && R[i]<='z') temp=(R[i]-'a'+36);
			else continue;
			
			if(temp>N) N=temp;
			num+=temp;
		}

		while(N<62){
			if(num%N==0) break;
			++N;
		}
		
		if(N==62) printf("such number is impossible!\n");
		else cout<<N+1<<endl;
	}
	return 0;
} 
```
