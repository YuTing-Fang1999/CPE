### 暴力解、存表  
窮舉k=1~13, m=k+1  
算出下一個被殺的人是誰，如果被殺的編號<k，就++m繼續算  
直到編號大於k的人都被殺掉為止  

找出下一個被殺的編號  
killedNum = (killedNum + m) % p (p為目前的存活人數)   
因為殺的人都是後半段，殺完後存活的人位置會往前挪，所以不用注意被殺的人的編號是多少，只要注意不要砍到前半段的人即可   


```cpp

#include <iostream>
using namespace std;

int table[15];
int k,m,p,killedNum;//killedNum start from 0 to 2*k-1
int main(){
	for(int k=1;k<14;++k){
		m = k+1;
		p = 2*k;
		killedNum = -1; 
		
		while(true){
			killedNum = (killedNum + m) % p;
			if(killedNum < k) {
				//init and recompute
				++m;
				p = 2*k;
				killedNum = -1;
			}
			else{
				--killedNum;
				--p;
	
				if(p==k){
					table[k] = m;
					break;
				}
			}
		}
	}
	
	
	while(cin>>k && k){
		printf("%d\n",table[k]);
	}
	
	return 0;
}

```
