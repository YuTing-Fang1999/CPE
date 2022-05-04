一開始以為很簡單，直接換基底運算就好，但數字多達100位，一定會overflow，要用到字串的大數運算   
因此直接使用二進位加法，因為是費氏數列的關係，100 = 011   
```
    100
    100  =  011
  --------------
    200 有數大於2
    111 
   1001 
```
   
依照這個原理我們可以把大於2的數做替換，連起來的兩個1做替換，做完就是答案了   

### 超級bug!
基底是(1,2,3,5,8,...)  
而不是(1,1,2,3,5,8,...)   
```
200 = 1001   
11 = 100   
```
例外case
```
2 = 10
20 = 101
```
### 還有要注意最後一行不要有換行!!

```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//原本想直接用基底去計算，但題目說字串長度會到100，算出來的基底會overflow 
//所以要直接使用二進位去算 

int main(){
	bool notFirst = false;
	string str1, str2;
	while(cin>>str1>>str2){
		if (notFirst) printf("\n");
        else notFirst = true;
		
		int ans[205]={0};
		
		reverse(str1.begin(),str1.end());
		reverse(str2.begin(),str2.end());
		
		for(int i=0;i<str1.size();++i) ans[i] += (str1[i]-'0');
		for(int i=0;i<str2.size();++i) ans[i] += (str2[i]-'0');
				
		bool flag=true;
		while(flag){
			flag=false;
			
			if(ans[0]>=2){ //2 = 10
				flag=true;
				ans[0] -= 2;
				ans[1] += 1;
			}
			
			if(ans[1]>=2){ //20 = 101
				flag=true;
				ans[1] -= 2;
				ans[0] += 1;
				ans[2] += 1;
			}
			
			for(int i=0;i<200;++i){
				if(ans[i]>=1 && ans[i+1]>=1){ // 11 => 100
					flag=true;
					ans[i]  -=1;
					ans[i+1]-=1;
					ans[i+2]+=1;
				}
				if(ans[i]>=2){ //200 => 1001
					flag=true;
					ans[i]  -=2;
					ans[i-2]+=1;
					ans[i+1]+=1;
				}
			}
		}
		
		bool p = false;
		for(int i=200;i>=0;--i){
			if(ans[i]>0) p=true;
			if(p) printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
```
### zerojudge可過但UVA過不了
### 使用udebug也找不出問題在哪...
