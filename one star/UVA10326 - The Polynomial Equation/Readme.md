```
ex: (x^2 + 3x + 2)(x+3)   
  =     x^3 + 3x^2 + 2x
      +       3x^2 + 9x + 6
      ----------------------
        x^3 + 6x^2 + 11x + 6
 ```
 
```
ex: (x+1)(x+2)(x+3)   

init 1   
1*(x+1) = 1(1+1) = 1  
                     1
                 =(1+1) = x+1
      (1+1)(1+2) = 1 1
                     2 2
                 = 1 3 2 = x^2 + 3x^ + 2
    (1+3+2)(1+3) = 1 3 2
                     3 9 6
                 = 1 6 11 6 = x^3 + 6x^2 + 11x + 6
 ```
```cpp

#include <iostream>
#include <string.h>
#include <stdlib.h>//llabs
using namespace std;
//記得用long long int 
long long int n,r;
long long int ans[55];
int main(){
	while(cin>>n){
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		for(int i=0;i<n;++i){
			cin>>r;
			//要從後面的先加，不然 j++ 後 ans[j+1] 會影響到後面的乘法運算 
			for(int j=i;j>=0;--j){
				ans[j+1] += (ans[j])*(-r);
			}
		}
	
		if(n==1) printf("x");
		else printf("x^%lld",n);
		for(int i=1;i<n;++i){
			
			if(ans[i]>0) printf(" + ");
			else if(ans[i]<0) printf(" - ");
			
			if(ans[i]!=0) {
				//係數為1時不顯示係數 
				if(abs(ans[i])!=1) printf("%lld",llabs(ans[i]));
				//次方為1時不顯示次方 
				if(n-i>1) printf("x^%lld",n-i);
				else printf("x");
			}
		}
		
		if(ans[n]>=0) printf(" + ");
		else if(ans[n]<0) printf(" - ");
		printf("%lld = 0\n", llabs(ans[n]));
	}
} 
```
